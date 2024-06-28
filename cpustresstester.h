#ifndef CPUSTRESSTESTER_H
#define CPUSTRESSTESTER_H

#include "cpucorestresstester.h"

class CPUStressTester {
public:
    CPUStressTester() : stopFlag(0) {}

    ~CPUStressTester() {
        stop();
    }

    void run();
    void stop();

private:
    QThreadPool threadPool;
    QAtomicInt stopFlag;
};

#endif // CPUSTRESSTESTER_H
