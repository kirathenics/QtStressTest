#include "cpucorestresstester.h"

CPUCoreStressTester::CPUCoreStressTester(QAtomicInt* stopFlag, QObject *parent)
    : QObject(parent), stopFlag(stopFlag)
{
}

void CPUCoreStressTester::run()
{
    QString threadInfo = QString("Тест ядра процессора в потоке %1 начался.").arg(reinterpret_cast<quintptr>(QThread::currentThread()));
    qDebug() << threadInfo;
    emit logMessage(threadInfo);

    double result = 0;
    while (!stopFlag->loadAcquire()) {
        for (int i = 0; i < 1000000; ++i) {
            result += qSin(QRandomGenerator::global()->generate());
        }
    }

    threadInfo = QString("Тест ядра процессора в потоке %1 завершился.").arg(reinterpret_cast<quintptr>(QThread::currentThread()));
    qDebug() << threadInfo;
    emit logMessage(threadInfo);
}
