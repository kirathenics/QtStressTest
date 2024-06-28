#include "disktestermanager.h"

void DiskTesterManager::run() {
    stop(); // Останавливаем все ранее запущенные тесты дисков

    QList<QStorageInfo> storageList = QStorageInfo::mountedVolumes();
    foreach (QStorageInfo storage, storageList) {
        if (storage.isValid() && storage.isReady() && !storage.isReadOnly()) {
            LocalDiskStressTester* diskTester = new LocalDiskStressTester(storage.rootPath());
            diskStressTesters.append(diskTester);
            diskTester->start();
        }
    }
}

void DiskTesterManager::stop() {
    for (LocalDiskStressTester* tester : diskStressTesters) {
        tester->requestInterruption();
        tester->wait();
        //tester->stop();
        delete tester;
    }
    diskStressTesters.clear();
}
