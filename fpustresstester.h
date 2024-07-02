#ifndef FPUSTRESSTESTER_H
#define FPUSTRESSTESTER_H

#include "libs.h"
#include "testabs.h"

/*class FPUStressTester : public AbstractStressTester
{
public:
    void run() override;
};*/

class FPUStressTester : public testabs
{
    Q_OBJECT

public:
    explicit FPUStressTester(QObject *parent = nullptr);

    void run() override;

/*    void stop();

signals:
    void logMessage(const QString &message);*/
};

#endif // FPUSTRESSTESTER_H
