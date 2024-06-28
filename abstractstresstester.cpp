#include "abstractstresstester.h"

void AbstractStressTester::run() {
    qDebug() << "Abstract stress test started";

    while (!isInterruptionRequested()) {
        QThread::msleep(10); // Имитация нагрузки
    }

    qDebug() << "Abstract stress test stopped";
}

void AbstractStressTester::stop() {
    this->requestInterruption();
    this->wait();
}
