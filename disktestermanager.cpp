#include "disktestermanager.h"

DiskTesterManager::DiskTesterManager(QObject *parent)
    : QObject(parent)
{
}

DiskTesterManager::~DiskTesterManager()
{
    stop();
}

void DiskTesterManager::start()
{
    stop(); // Останавливаем все ранее запущенные тесты дисков

    QList<QStorageInfo> storageList = QStorageInfo::mountedVolumes();
    foreach (QStorageInfo storage, storageList) {
        if (storage.isValid() && storage.isReady() && !storage.isReadOnly()) {
            LocalDiskStressTester* diskTester = new LocalDiskStressTester(storage.rootPath(), this);
            connect(diskTester, &LocalDiskStressTester::logMessage, this, &DiskTesterManager::logMessage);
            diskStressTesters.append(diskTester);
            diskTester->start();
        }
    }
}

void DiskTesterManager::stop()
{
    for (LocalDiskStressTester* tester : diskStressTesters) {
        //tester->requestInterruption();
        //tester->wait();
        tester->stop();
        delete tester;
    }
    diskStressTesters.clear();
}
