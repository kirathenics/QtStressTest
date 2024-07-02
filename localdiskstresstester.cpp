#include "localdiskstresstester.h"

LocalDiskStressTester::LocalDiskStressTester(const QString &rootPath, QObject *parent)
    : AbstractStressTester(parent)
    , rootPath(rootPath)
{
}

void LocalDiskStressTester::run()
{
    qDebug() << "Starting disk stress test on" << rootPath;
    emit logMessage("Тест на диске " + rootPath + " начался.");

    QDir testDir(rootPath + "/StressTest");
    if (!testDir.exists()) {
        testDir.mkpath(".");
    }

    stressTestDisk(testDir.absolutePath());

    // Удаление тестовой папки после завершения теста
    if (testDir.exists()) {
        if (!testDir.removeRecursively()) {
            qDebug() << "Failed to remove test directory:" << testDir.absolutePath();
            emit logMessage("Ошибка! Не удалось удалить тестовую папку: " + testDir.absolutePath());
        }
    }

    qDebug() << "Disk stress test stopped on" << rootPath;
    emit logMessage("Тест на диске " + rootPath + " завершился.");
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
            emit logMessage("Ошибка! Не удалось открыть файл на запись: " + testFileName);
            return;
        }

        // Read test
        if (testFile.open(QIODevice::ReadOnly)) {
            testFile.readAll();
            testFile.close();
        } else {
            qDebug() << "Failed to open file for reading:" << testFileName;
            emit logMessage("Ошибка! Не удалось открыть файл на чтение: " + testFileName);
            return;
        }

        // Delete test file
        if (!testFile.remove()) {
            qDebug() << "Failed to delete test file:" << testFileName;
            emit logMessage("Ошибка! Не удалось удалить тестовый файл: " + testFileName);
            return;
        }

        QThread::msleep(10); // Имитация нагрузки
    }
}
