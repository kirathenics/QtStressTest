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

#include <QThreadPool>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QAtomicInt>

QT_BEGIN_NAMESPACE
namespace Ui { class StressTestApp; }
QT_END_NAMESPACE


class CPURunnable : public QRunnable {
public:
    CPURunnable(QAtomicInt* stopFlag) : stopFlag(stopFlag) {}
    void run() override {
        qDebug() << "Starting CPU stress test on thread" << QThread::currentThread();
        double result = 0;
        while (!stopFlag->loadAcquire()) {
            for (int i = 0; i < 1000000; ++i) {
                result += qSin(QRandomGenerator::global()->generate());
            }
        }
        qDebug() << "CPU stress test stopped on thread" << QThread::currentThread();
    }

private:
    QAtomicInt* stopFlag;
};

class CPUCoresStressTester {
public:
    CPUCoresStressTester() : stopFlag(0) {}
    void start();
    void stop();

private:
    QThreadPool threadPool;
    QAtomicInt stopFlag;
};

//class CPUStressTester : public QThread {
//public:
//    void run() override {
//        qDebug() << "Starting CPU stress test";
//        double result = 0;
//        while (!isInterruptionRequested()) {
//            for (int i = 0; i < 1000000; ++i) {
//                result += qSin(QRandomGenerator::global()->generate());
//            }
//            QThread::msleep(10); // Имитация нагрузки
//        }
//        qDebug() << "CPU stress test stopped";
//    }
//};

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

    CPUCoresStressTester cpuStressTester;
//    CPUStressTester* cpuStressTester;
    FPUStressTester* fpuStressTester;

    void updateCurrentDateTime();
    void startOrResumeTimer();
    void stopTimer();
    void updateTimerLabel();

    unsigned long long FibonacciFunction(int n);
};
#endif // STRESSTESTAPP_H
