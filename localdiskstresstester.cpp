#include "localdiskstresstester.h"

void LocalDiskStressTester::run()
{
    qDebug() << "Starting disk stress test on" << rootPath;

    QDir testDir(rootPath + "/StressTest");
    if (!testDir.exists()) {
        testDir.mkpath(".");
    }

    stressTestDisk(testDir.absolutePath());

    // Удаление тестовой папки после завершения теста
    if (testDir.exists()) {
        if (!testDir.removeRecursively()) {
            qDebug() << "Failed to remove test directory:" << testDir.absolutePath();
        }
    }

    qDebug() << "Disk stress test stopped on" << rootPath;
}

void LocalDiskStressTester::stressTestDisk(const QString& path)
{
    const qint64 fileSize = 1024 * 1024 * 10; // 10 MB
    const QString testFileName = path + "/stress_test_file.bin";

    QFile testFile(testFileName);

    while (!isInterruptionRequested()) {
        // Write test
        if (testFile.open(QIODevice::WriteOnly)) {
            QByteArray data(fileSize, 'A');
            testFile.write(data);
            testFile.close();
        } else {
            qDebug() << "Failed to open file for writing:" << testFileName;
            return;
        }

        // Read test
        if (testFile.open(QIODevice::ReadOnly)) {
            testFile.readAll();
            testFile.close();
        } else {
            qDebug() << "Failed to open file for reading:" << testFileName;
            return;
        }

        // Delete test file
        if (!testFile.remove()) {
            qDebug() << "Failed to delete test file:" << testFileName;
            return;
        }

        QThread::msleep(10); // Имитация нагрузки
    }
}
