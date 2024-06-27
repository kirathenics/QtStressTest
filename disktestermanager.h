#ifndef DISKTESTERMANAGER_H
#define DISKTESTERMANAGER_H

#include "localdiskstresstester.h"

class DiskTesterManager {
public:
    DiskTesterManager() = default;

    ~DiskTesterManager() {
        stopAllTests();
    }

    void startAllTests();
    void stopAllTests();

private:
    QList<LocalDiskStressTester*> diskStressTesters;
};

#endif // DISKTESTERMANAGER_H
