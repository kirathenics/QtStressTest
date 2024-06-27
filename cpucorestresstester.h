#ifndef CPUCORESTRESSTESTER_H
#define CPUCORESTRESSTESTER_H

#include "libs.h"

class CPUCoreStressTester : public QRunnable {
public:
    CPUCoreStressTester(QAtomicInt* stopFlag) : stopFlag(stopFlag) {}
    void run() override;

private:
    QAtomicInt* stopFlag;

    unsigned long long FibonacciFunction(int n);
};

#endif // CPUCORESTRESSTESTER_H
