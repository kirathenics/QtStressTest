#ifndef STRESSTESTAPP_H
#define STRESSTESTAPP_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QTime>

#include <QThread>
#include <QDebug>
#include <QtMath>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class StressTestApp; }
QT_END_NAMESPACE


class CPUStressTester : public QThread {
public:
    void run() override {
        qDebug() << "Starting CPU stress test";
        double result = 0;
        while (!isInterruptionRequested()) {
            for (int i = 0; i < 1000000; ++i) {
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
                result += qSqrt(QRandomGenerator::global()->generate());
            }
            QThread::msleep(10); // Имитация нагрузки
        }
        qDebug() << "FPU stress test stopped";
    }
};


class StressTestApp : public QMainWindow
{
    Q_OBJECT

public:
    StressTestApp(QWidget *parent = nullptr);
    ~StressTestApp();

private slots:
    void on_start_pushButton_clicked();
    void on_stop_pushButton_clicked();

private:
    Ui::StressTestApp *ui;
    QTimer* timer;
    QTime* time;

    CPUStressTester* cpuStressTester;
    FPUStressTester* fpuStressTester;

    void updateCurrentDateTime();
    void startOrResumeTimer();
    void stopTimer();
    void updateTimerLabel();

    unsigned long long FibonacciFunction(int n);
};
#endif // STRESSTESTAPP_H
