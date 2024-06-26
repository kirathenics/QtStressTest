#include "stresstestapp.h"
#include "ui_stresstestapp.h"


#include <QThread>
#include <QDebug>
#include <QtGlobal>
#include <QtMath>
#include <QRandomGenerator>

class CPUStressTester : public QThread {
public:
    void run() override {
        qDebug() << "Starting CPU stress test";
        double result = 0;
        while (!isInterruptionRequested()) {
            for (int i = 0; i < 1000000; ++i) {
//                result += qSin(qrand());
                result += qSin(QRandomGenerator::global()->generate());
            }
            QThread::msleep(10); // Имитация нагрузки
        }
        qDebug() << "CPU stress test stopped";
    }
};

class FPUStressTester : public QThread {
public:
    void run() override {
        qDebug() << "Starting FPU stress test";
        double result = 0;
        while (!isInterruptionRequested()) {
            for (int i = 0; i < 1000000; ++i) {
//                result += qSqrt(qrand());
                result += qSqrt(QRandomGenerator::global()->generate());
            }
            QThread::msleep(10); // Имитация нагрузки
        }
        qDebug() << "FPU stress test stopped";
    }
};




StressTestApp::StressTestApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StressTestApp)
{
    ui->setupUi(this);

    ui->timer_label->setText("00:00:00");

    timer = new QTimer(this);
    timer->setInterval(1000);
    time = new QTime(0, 0, 0);

    //ui->cpu_checkBox->setChecked(true);

    connect(timer, &QTimer::timeout, this, &StressTestApp::updateTimerLabel);
}

StressTestApp::~StressTestApp()
{
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
        CPUStressTester* cpuStressTester = new CPUStressTester();
        cpuStressTester->start();
    }
    if (ui->fpu_checkBox->isChecked()) {
        FPUStressTester* fpuStressTester = new FPUStressTester();
        fpuStressTester->start();
    }
    //cpuStress();
}


void StressTestApp::on_stop_pushButton_clicked()
{
    if (!ui->start_pushButton->isEnabled()) {
        ui->start_pushButton->setEnabled(true);
        stopTimer();
    }
}

