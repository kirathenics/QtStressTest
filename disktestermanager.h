#ifndef DISKTESTERMANAGER_H
#define DISKTESTERMANAGER_H

#include "localdiskstresstester.h"

class DiskTesterManager
{
public:
    DiskTesterManager() = default;

    ~DiskTesterManager() {
        stop();
    }

    void start();
    void stop();

private:
    QList<LocalDiskStressTester*> diskStressTesters;
};

#endif // DISKTESTERMANAGER_H
