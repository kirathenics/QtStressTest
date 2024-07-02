#include "cpucorestresstester.h"

CPUCoreStressTester::CPUCoreStressTester(QAtomicInt* stopFlag, int coreNumber, QObject *parent)
    : QObject(parent)
    , stopFlag(stopFlag)
    , coreNumber(coreNumber)
{
}

void CPUCoreStressTester::run()
{
    QString threadInfo = QString("Тест ядра процессора #%1 начался.").arg(coreNumber);
    qDebug() << threadInfo;
    emit logMessage(threadInfo);

    double result = 0;
    while (!stopFlag->loadAcquire()) {
        for (int i = 0; i < 1000000; ++i) {
            result += qSin(QRandomGenerator::global()->generate());
        }
    }

    threadInfo = QString("Тест ядра процессора #%1 завершился.").arg(coreNumber);
    qDebug() << threadInfo;
    emit logMessage(threadInfo);
}
