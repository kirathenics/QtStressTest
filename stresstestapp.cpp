#include "stresstestapp.h"
#include "ui_stresstestapp.h"


StressTestApp::StressTestApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StressTestApp)
    , cpuStressTester(nullptr)
    , fpuStressTester(nullptr)
    , cacheStressTester(nullptr)
    , ramStressTester(nullptr)
    , diskTesterManager(nullptr)
    , gpuStressTester(nullptr)
{
    ui->setupUi(this);

    ui->logs_tableWidget->setColumnCount(2);
    QStringList tableHeaders;
    tableHeaders << "Дата/Время" << "Событие";
    ui->logs_tableWidget->setHorizontalHeaderLabels(tableHeaders);

    ui->currentDateTime_label->setText("");
    ui->timer_label->setText("00:00:00");

    timer = new QTimer(this);
    timer->setInterval(1000);
    time = new QTime(0, 0, 0);

    ui->cpu_checkBox->setChecked(false);
    ui->fpu_checkBox->setChecked(false);
    ui->cache_checkBox->setChecked(false);
    ui->ram_checkBox->setChecked(true);
    ui->localDisk_checkBox->setChecked(false);
    ui->gpu_checkBox->setChecked(false);

    ui->stop_pushButton->setEnabled(false);

    connect(timer, &QTimer::timeout, this, &StressTestApp::updateTimerLabel);
}

StressTestApp::~StressTestApp()
{
    if (cpuStressTester) {
        cpuStressTester->stop();
        delete cpuStressTester;
    }

    if (fpuStressTester) {
        fpuStressTester->requestInterruption();
        fpuStressTester->wait();
        delete fpuStressTester;
    }

    if (cacheStressTester) {
        cacheStressTester->requestInterruption();
        cacheStressTester->wait();
        delete cacheStressTester;
    }

    if (ramStressTester) {
        ramStressTester->requestInterruption();
        ramStressTester->wait();
        delete ramStressTester;
    }

    if (diskTesterManager) {
        diskTesterManager->stopAllTests();
        delete diskTesterManager;
    }

    if (gpuStressTester) {
        gpuStressTester->requestInterruption();
        gpuStressTester->wait();
        delete gpuStressTester;
    }

    delete ui;
}


void StressTestApp::updateCurrentDateTime() {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
    ui->currentDateTime_label->setText(dateTimeString);
}

void StressTestApp::startOrResumeTimer() {
    if (!timer->isActive()) {
        timer->start();
    }
}

void StressTestApp::stopTimer() {
    if (timer->isActive()) {
        timer->stop();
    }
}

void StressTestApp::updateTimerLabel() {
    *time = time->addSecs(1);
    //qDebug() << time;
    ui->timer_label->setText(time->toString("HH:mm:ss"));
}



void StressTestApp::on_start_pushButton_clicked()
{
    //qDebug() << "Нажато!";

    ui->start_pushButton->setEnabled(false);
    ui->stop_pushButton->setEnabled(true);

    updateCurrentDateTime();

    startOrResumeTimer();

    if (ui->cpu_checkBox->isChecked()) {
        if (cpuStressTester) {
            cpuStressTester->stop();
            delete cpuStressTester;
        }
        cpuStressTester = new CPUStressTester();
        cpuStressTester->start();
    }

    if (ui->fpu_checkBox->isChecked()) {
        if (fpuStressTester) {
            fpuStressTester->requestInterruption();
            fpuStressTester->wait();
            delete fpuStressTester;
        }
        fpuStressTester = new FPUStressTester();
        fpuStressTester->start();
    }

    if (ui->cache_checkBox->isChecked()) {
        if (cacheStressTester) {
            cacheStressTester->requestInterruption();
            cacheStressTester->wait();
            delete cacheStressTester;
        }
        cacheStressTester = new CacheStressTester();
        cacheStressTester->start();
    }

    if (ui->ram_checkBox->isChecked()) {
        if (ramStressTester) {
            ramStressTester->requestInterruption();
            ramStressTester->wait();
            delete ramStressTester;
        }
        ramStressTester = new RAMStressTester();
        ramStressTester->start();
    }

    if (ui->localDisk_checkBox->isChecked()) {
        if (diskTesterManager) {
            diskTesterManager->stopAllTests();
            delete diskTesterManager;
        }
        diskTesterManager = new DiskTesterManager();
        diskTesterManager->startAllTests();
    }

    if (ui->gpu_checkBox->isChecked()) {
        if (gpuStressTester) {
            gpuStressTester->requestInterruption();
            gpuStressTester->wait();
            delete gpuStressTester;
        }
        gpuStressTester = new GPUStressTester();
        gpuStressTester->start();
    }
}


void StressTestApp::on_stop_pushButton_clicked()
{
    ui->start_pushButton->setEnabled(true);
    ui->stop_pushButton->setEnabled(false);
    stopTimer();

    if (cpuStressTester) {
        cpuStressTester->stop();
        delete cpuStressTester;
        cpuStressTester = nullptr;
    }

    if (fpuStressTester) {
        fpuStressTester->requestInterruption();
        fpuStressTester->wait();
        delete fpuStressTester;
        fpuStressTester = nullptr;
    }

    if (cacheStressTester) {
        cacheStressTester->requestInterruption();
        cacheStressTester->wait();
        delete cacheStressTester;
        cacheStressTester = nullptr;
    }

    if (ramStressTester) {
        ramStressTester->requestInterruption();
        ramStressTester->wait();
        delete ramStressTester;
        ramStressTester = nullptr;
    }

    if (diskTesterManager) {
        diskTesterManager->stopAllTests();
        delete diskTesterManager;
        diskTesterManager = nullptr;
    }

    if (gpuStressTester) {
        gpuStressTester->requestInterruption();
        gpuStressTester->wait();
        delete gpuStressTester;
        gpuStressTester = nullptr;
    }
}

void StressTestApp::on_clear_pushButton_clicked()
{
    //TODO: clear graphs
    //TODO: clear logs

    if (ui->start_pushButton->isEnabled()) {
        ui->currentDateTime_label->setText("");
        ui->timer_label->setText("00:00:00");
        time = new QTime(0, 0, 0);
    }
}

void StressTestApp::addLogEntry(const QString &action)
{
    int row = ui->logs_tableWidget->rowCount();
    ui->logs_tableWidget->insertRow(row);

    QTableWidgetItem *dateTimeItem = new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    QTableWidgetItem *actionItem = new QTableWidgetItem(action);

    ui->logs_tableWidget->setItem(row, 0, dateTimeItem);
    ui->logs_tableWidget->setItem(row, 1, actionItem);
}
