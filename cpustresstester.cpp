#include "cpustresstester.h"

CPUStressTester::CPUStressTester(QObject *parent)
    : QObject(parent)
    , stopFlag(0)
{
}

CPUStressTester::~CPUStressTester()
{
    stop();
}

void CPUStressTester::start()
{
    stop();

    stopFlag.fetchAndStoreRelaxed(0);
    int numCores = QThread::idealThreadCount();
    for (int i = 0; i < numCores; ++i) {
        CPUCoreStressTester* task = new CPUCoreStressTester(&stopFlag, this);
        connect(task, &CPUCoreStressTester::logMessage, this, &CPUStressTester::logMessage);
        threadPool.start(task);
    }
}

void CPUStressTester::stop()
{
    stopFlag.fetchAndStoreRelaxed(1);
    threadPool.waitForDone();
}
