#ifndef FPUSTRESSTESTER_H
#define FPUSTRESSTESTER_H

#include "libs.h"

class FPUStressTester : public QThread {
public:
    void run() override;
};

#endif // FPUSTRESSTESTER_H
