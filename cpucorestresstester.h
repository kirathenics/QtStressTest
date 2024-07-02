#ifndef CPUCORESTRESSTESTER_H
#define CPUCORESTRESSTESTER_H

#include "libs.h"

class CPUCoreStressTester : public QObject, public QRunnable
{
    Q_OBJECT

public:
    CPUCoreStressTester(QAtomicInt* stopFlag, int coreNumber, QObject *parent = nullptr);

    void run() override;

signals:
    void logMessage(const QString &message);

private:
    QAtomicInt* stopFlag;
    int coreNumber;
};

#endif // CPUCORESTRESSTESTER_H
