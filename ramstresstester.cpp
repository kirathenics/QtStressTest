#include "ramstresstester.h"

void RAMStressTester::run() {
    qDebug() << "Starting RAM stress test";
    const int arraySize = 1024 * 1024 * 100; // 100 MB

    while (!isInterruptionRequested()) {
        int* array = new int[arraySize];

        for (int i = 0; i < arraySize; ++i) {
            array[i] = QRandomGenerator::global()->generate();
        }
        for (int i = 0; i < arraySize; ++i) {
            array[i] ^= QRandomGenerator::global()->generate();
        }
        QThread::msleep(10); // Имитация нагрузки

        delete[] array;
    }

    qDebug() << "RAM stress test stopped";
}
