#include "cpustresstester.h"

void CPUStressTester::start() {
    stopFlag.fetchAndStoreRelaxed(0);
    int numCores = QThread::idealThreadCount();
    for (int i = 0; i < numCores; ++i) {
        CPUCoreStressTester* task = new CPUCoreStressTester(&stopFlag);
        threadPool.start(task);
    }
}

void CPUStressTester::stop() {
    stopFlag.fetchAndStoreRelaxed(1);
    threadPool.waitForDone();
}
