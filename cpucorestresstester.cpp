#include "cpucorestresstester.h"

void CPUCoreStressTester::run()
{
    qDebug() << "Starting CPU stress test on thread" << QThread::currentThread();
    double result = 0;
    while (!stopFlag->loadAcquire()) {
        for (int i = 0; i < 1000000; ++i) {
            result += qSin(QRandomGenerator::global()->generate());
        }
    }
    qDebug() << "CPU stress test stopped on thread" << QThread::currentThread();
}

unsigned long long CPUCoreStressTester::FibonacciFunction(int n)
{
    if (n <= 1) {
        return 1;
    }
    return FibonacciFunction(n - 1) + FibonacciFunction(n - 2);
}
