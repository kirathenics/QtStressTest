#include "fpustresstester.h"

/*void FPUStressTester::run()
{
    qDebug() << "Starting FPU stress test";

    double result = 0;
    while (!isInterruptionRequested()) {
        for (int i = 0; i < 1000000; ++i) {
            result += qSqrt(QRandomGenerator::global()->generate());
        }
        QThread::msleep(10); // Имитация нагрузки
    }

    qDebug() << "FPU stress test stopped";
}*/

FPUStressTester::FPUStressTester(QObject *parent)
    : testabs(parent)
{
}

void FPUStressTester::run()
{
    qDebug() << "Starting FPU stress test";
    emit logMessage("Тест математического сопроцессора начался.");

    double result = 0;
    while (!isInterruptionRequested()) {
        for (int i = 0; i < 1000000; ++i) {
            result += qSqrt(QRandomGenerator::global()->generate());
        }
        QThread::msleep(10); // Имитация нагрузки
    }

    qDebug() << "FPU stress test stopped";
    emit logMessage("Тест математического сопроцессора завершился.");
}

/*void FPUStressTester::stop()
{
    this->requestInterruption();
    this->wait();
}*/
