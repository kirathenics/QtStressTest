#include "disktestermanager.h"

void DiskTesterManager::startAllTests() {
    stopAllTests(); // Останавливаем все ранее запущенные тесты дисков

    QList<QStorageInfo> storageList = QStorageInfo::mountedVolumes();
    foreach (QStorageInfo storage, storageList) {
        if (storage.isValid() && storage.isReady() && !storage.isReadOnly()) {
            LocalDiskStressTester* diskTester = new LocalDiskStressTester(storage.rootPath());
            diskStressTesters.append(diskTester);
            diskTester->start();
        }
    }
}

void DiskTesterManager::stopAllTests() {
    for (LocalDiskStressTester* tester : diskStressTesters) {
        tester->requestInterruption();
        tester->wait();
        delete tester;
    }
    diskStressTesters.clear();
}
