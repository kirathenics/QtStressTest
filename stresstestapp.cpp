#include "stresstestapp.h"
#include "ui_stresstestapp.h"


StressTestApp::StressTestApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StressTestApp)
    , cpuStressTester(nullptr)
    , fpuStressTester(nullptr)
{
    ui->setupUi(this);

    ui->timer_label->setText("00:00:00");

    timer = new QTimer(this);
    timer->setInterval(1000);
    time = new QTime(0, 0, 0);

    ui->cpu_checkBox->setChecked(true);
    ui->fpu_checkBox->setChecked(true);

    connect(timer, &QTimer::timeout, this, &StressTestApp::updateTimerLabel);
}

StressTestApp::~StressTestApp()
{
    if (cpuStressTester) {
        cpuStressTester->requestInterruption();
        cpuStressTester->wait();
        delete cpuStressTester;
    }
    if (fpuStressTester) {
        fpuStressTester->requestInterruption();
        fpuStressTester->wait();
        delete fpuStressTester;
    }

    delete ui;
}


unsigned long long StressTestApp::FibonacciFunction(int n) {
    if (n <= 1) {
        return 1;
    }
    return FibonacciFunction(n - 1) + FibonacciFunction(n - 2);
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

    updateCurrentDateTime();

    startOrResumeTimer();

    if (ui->cpu_checkBox->isChecked()) {
        if (cpuStressTester) {
            cpuStressTester->requestInterruption();
            cpuStressTester->wait();
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
}


void StressTestApp::on_stop_pushButton_clicked()
{
    if (!ui->start_pushButton->isEnabled()) {
        ui->start_pushButton->setEnabled(true);
        stopTimer();

        if (cpuStressTester) {
            cpuStressTester->requestInterruption();
            cpuStressTester->wait();
            delete cpuStressTester;
            cpuStressTester = nullptr;
        }
        if (fpuStressTester) {
            fpuStressTester->requestInterruption();
            fpuStressTester->wait();
            delete fpuStressTester;
            fpuStressTester = nullptr;
        }
    }
}

