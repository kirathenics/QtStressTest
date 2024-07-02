#ifndef CPUSTRESSTESTER_H
#define CPUSTRESSTESTER_H

#include "cpucorestresstester.h"

class CPUStressTester : public QObject
{
    Q_OBJECT

public:
    CPUStressTester(QObject *parent = nullptr);
    ~CPUStressTester();

    void start();
    void stop();

signals:
    void logMessage(const QString &message);

private:
    QThreadPool threadPool;
    QAtomicInt stopFlag;
};

#endif // CPUSTRESSTESTER_H
