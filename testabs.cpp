#include "testabs.h"

testabs::testabs(QObject *parent)
    : QThread(parent)
{
}

void testabs::run()
{
    qDebug() << "Abstract stress test started";
    emit logMessage("Тест абстрактного модуля начался.");

    while (!isInterruptionRequested()) {
        QThread::msleep(10); // Имитация нагрузки
    }

    qDebug() << "Abstract stress test stopped";
    emit logMessage("Тест абстрактного модуля завершился.");
}

void testabs::stop()
{
    this->requestInterruption();
    this->wait();
}
