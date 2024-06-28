#ifndef FPUSTRESSTESTER_H
#define FPUSTRESSTESTER_H

#include "libs.h"

//class FPUStressTester : public QThread {
//public:
//    void run() override;

//    void stop() {
//        this->requestInterruption();
//        this->wait();
//    }
//};

class FPUStressTester : public AbstractStressTester {
public:
    void run() override;
};

#endif // FPUSTRESSTESTER_H
