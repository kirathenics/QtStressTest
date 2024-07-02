#ifndef FPUSTRESSTESTER_H
#define FPUSTRESSTESTER_H

#include "libs.h"

class FPUStressTester : public AbstractStressTester
{
    Q_OBJECT

public:
    explicit FPUStressTester(QObject *parent = nullptr);

    void run() override;
};

#endif // FPUSTRESSTESTER_H
