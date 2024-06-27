#ifndef LOCALDISKSTRESSTESTER_H
#define LOCALDISKSTRESSTESTER_H

#include "libs.h"

//class LocalDiskStressTester : public QThread {
//public:
//    void run() override {
//        qDebug() << "Starting Disk stress test";

//        QList<QStorageInfo> storageList = QStorageInfo::mountedVolumes();
//        foreach (QStorageInfo storage, storageList) {
//            if (storage.isValid() && storage.isReady() && !storage.isReadOnly()) {
//                QDir testDir(storage.rootPath() + "/StressTest");
//                if (!testDir.exists()) {
//                    testDir.mkpath(".");
//                }
//                qDebug() << "Starting disk stress test for drive" << storage.rootPath();
//                stressTestDisk(testDir.absolutePath());
//                qDebug() << "Disk stress test for drive" << storage.rootPath() << "completed";

//                // Удаление тестовой папки после завершения теста
//                if (testDir.exists()) {
//                    if (!testDir.removeRecursively()) {
//                        qDebug() << "Failed to remove test directory:" << testDir.absolutePath();
//                    }
//                }
//            }
//        }

//        qDebug() << "Disk stress test completed";
//    }

//private:
//    void stressTestDisk(const QString& path) {
//        const qint64 fileSize = 1024 * 1024 * 10; // 10 MB
//        const QString testFileName = path + "/stress_test_file.bin";

//        QFile testFile(testFileName);

//        while (!isInterruptionRequested()) {
//            // Write test
//            if (testFile.open(QIODevice::WriteOnly)) {
//                QByteArray data(fileSize, 'A');
//                testFile.write(data);
//                testFile.close();
//            } else {
//                qDebug() << "Failed to open file for writing:" << testFileName;
//                return;
//            }

//            // Read test
//            if (testFile.open(QIODevice::ReadOnly)) {
//                testFile.readAll();
//                testFile.close();
//            } else {
//                qDebug() << "Failed to open file for reading:" << testFileName;
//                return;
//            }

//            // Delete test file
//            if (!testFile.remove()) {
//                qDebug() << "Failed to delete test file:" << testFileName;
//                return;
//            }

//            QThread::msleep(10); // Имитация нагрузки
//        }
//    }
//};

class LocalDiskStressTester : public QThread {
    Q_OBJECT
public:
    explicit LocalDiskStressTester(const QString &rootPath, QObject *parent = nullptr)
        : QThread(parent), rootPath(rootPath) {}

    void run() override;

private:
    QString rootPath;

    void stressTestDisk(const QString& path);
};

#endif // LOCALDISKSTRESSTESTER_H
