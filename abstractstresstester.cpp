#include "abstractstresstester.h"

AbstractStressTester::AbstractStressTester(QObject *parent)
    : QThread(parent)
{
}

void AbstractStressTester::run()
{
    qDebug() << "Abstract stress test started";
    emit logMessage("Тест абстрактного модуля начался.");

    while (!isInterruptionRequested()) {
        QThread::msleep(10); // Имитация нагрузки
    }

    qDebug() << "Abstract stress test stopped";
    emit logMessage("Тест абстрактного модуля завершился.");
}

void AbstractStressTester::stop()
{
    this->requestInterruption();
    this->wait();
}

