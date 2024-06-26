#include "stresstestapp.h"
#include "ui_stresstestapp.h"


StressTestApp::StressTestApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StressTestApp)
    //, cpuStressTester(nullptr)
    , fpuStressTester(nullptr)
    , cacheStressTester(nullptr)
    , ramStressTester(nullptr)
    , localDiskStressTester(nullptr)
    , gpuStressTester(nullptr)
{
    ui->setupUi(this);

    ui->currentDateTime_label->setText("");
    ui->timer_label->setText("00:00:00");

    timer = new QTimer(this);
    timer->setInterval(1000);
    time = new QTime(0, 0, 0);

    ui->cpu_checkBox->setChecked(false);
    ui->fpu_checkBox->setChecked(false);
    ui->cache_checkBox->setChecked(false);
    ui->ram_checkBox->setChecked(false);
    ui->localDisk_checkBox->setChecked(false);
    ui->gpu_checkBox->setChecked(true);

    ui->stop_pushButton->setEnabled(false);

    connect(timer, &QTimer::timeout, this, &StressTestApp::updateTimerLabel);
}

StressTestApp::~StressTestApp()
{
//    if (cpuStressTester) {
//        cpuStressTester->requestInterruption();
//        cpuStressTester->wait();
//        delete cpuStressTester;
//    }

    cpuStressTester.stop();

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

    if (localDiskStressTester) {
        localDiskStressTester->requestInterruption();
        localDiskStressTester->wait();
        delete localDiskStressTester;
    }

    if (gpuStressTester) {
        gpuStressTester->requestInterruption();
        gpuStressTester->wait();
        delete gpuStressTester;
    }

    delete ui;
}


//unsigned long long StressTestApp::FibonacciFunction(int n) {
//    if (n <= 1) {
//        return 1;
//    }
//    return FibonacciFunction(n - 1) + FibonacciFunction(n - 2);
//}



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

//    if (ui->cpu_checkBox->isChecked()) {
//        if (cpuStressTester) {
//            cpuStressTester->requestInterruption();
//            cpuStressTester->wait();
//            delete cpuStressTester;
//        }
//        cpuStressTester = new CPUStressTester();
//        cpuStressTester->start();
//    }
    if (ui->cpu_checkBox->isChecked()) {
        cpuStressTester.start();
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
        if (localDiskStressTester) {
            localDiskStressTester->requestInterruption();
            localDiskStressTester->wait();
            delete localDiskStressTester;
        }
        localDiskStressTester = new LocalDiskStressTester();
        localDiskStressTester->start();
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

    //        if (cpuStressTester) {
    //            cpuStressTester->requestInterruption();
    //            cpuStressTester->wait();
    //            delete cpuStressTester;
    //            cpuStressTester = nullptr;
    //        }

    cpuStressTester.stop();

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

    if (localDiskStressTester) {
        localDiskStressTester->requestInterruption();
        localDiskStressTester->wait();
        delete localDiskStressTester;
        localDiskStressTester = nullptr;
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
    //clear graphs
    //clear logs

    if (ui->start_pushButton->isEnabled()) {
        ui->currentDateTime_label->setText("");
        ui->timer_label->setText("00:00:00");
        time = new QTime(0, 0, 0);
    }
}

void CPUCoresStressTester::start() {
    stopFlag.fetchAndStoreRelaxed(0);
    int numCores = QThread::idealThreadCount();
    for (int i = 0; i < numCores; ++i) {
        CPURunnable* task = new CPURunnable(&stopFlag);
        threadPool.start(task);
    }
}

void CPUCoresStressTester::stop() {
    stopFlag.fetchAndStoreRelaxed(1);
    threadPool.waitForDone();
}




