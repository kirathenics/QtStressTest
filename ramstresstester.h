#ifndef RAMSTRESSTESTER_H
#define RAMSTRESSTESTER_H

#include "libs.h"

//class RAMStressTester : public QThread {
//public:
//    void run() override {
//        MEMORYSTATUSEX status;
//        status.dwLength = sizeof(status);
//        GlobalMemoryStatusEx(&status);
//        unsigned long long totalMemory = status.ullTotalPhys;
//        unsigned long long availableMemory = status.ullAvailPhys;

//        qDebug() << "Starting RAM stress test for available memory size" << availableMemory << "bytes";

//        if (totalMemory <= 0) {
//            qDebug() << "Error! Unable to determine total memory size!";
//            return;
//        }

//        char* data = new char[availableMemory];
//        for (unsigned long long i = 0; i < availableMemory; ++i) {
//            data[i] = rand() % 256;
//        }
//        delete[] data;

//        qDebug() << "RAM stress test stopped";
//    }
//};

class RAMStressTester : public AbstractStressTester
{
    Q_OBJECT

public:
    explicit RAMStressTester(QObject *parent = nullptr);

    void run() override;

    using AbstractStressTester::logMessage;
};

#endif // RAMSTRESSTESTER_H
