#ifndef STRESSTESTAPP_H
#define STRESSTESTAPP_H

#include "libs.h"
#include "cpucorestresstester.h"
#include "cpustresstester.h"
#include "fpustresstester.h"
#include "cachestresstester.h"
#include "ramstresstester.h"
#include "localdiskstresstester.h"
#include "disktestermanager.h"
#include "gpustresstester.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StressTestApp; }
QT_END_NAMESPACE


/*class CPUCoreStressTester : public QRunnable {
public:
    CPUCoreStressTester(QAtomicInt* stopFlag) : stopFlag(stopFlag) {}
    void run() override {
        qDebug() << "Starting CPU stress test on thread" << QThread::currentThread();
        double result = 0;
        while (!stopFlag->loadAcquire()) {
            for (int i = 0; i < 1000000; ++i) {
                result += qSin(QRandomGenerator::global()->generate());
            }
        }
        qDebug() << "CPU stress test stopped on thread" << QThread::currentThread();
    }

private:
    QAtomicInt* stopFlag;
};*/

/*class CPUStressTester {
public:
    CPUStressTester() : stopFlag(0) {}
    void start();
    void stop();

private:
    QThreadPool threadPool;
    QAtomicInt stopFlag;
};*/

/*class FPUStressTester : public QThread {
public:
    void run() override {
        qDebug() << "Starting FPU stress test";
        double result = 0;
        while (!isInterruptionRequested()) {
            for (int i = 0; i < 1000000; ++i) {
                result += qSqrt(QRandomGenerator::global()->generate());
            }
            QThread::msleep(10); // Имитация нагрузки
        }
        qDebug() << "FPU stress test stopped";
    }
};*/

/*class CacheStressTester : public QThread {
public:
    void run() override {
        int cacheSize = 0;

        __asm__ (
            "mov $0x80000005, %%eax\n\t"
            "cpuid\n\t"
            "mov %%ecx, %0\n\t"
            "and $0xFFFF0000, %0\n\t"
            "shr $16, %0"
            : "=r" (cacheSize)
            :
            : "eax", "ebx", "ecx", "edx"
            );

        qDebug() << "Starting cache stress test for L1 cache size" << cacheSize << "KB";

        if (cacheSize <= 0) {
            qDebug() << "Error! Unable to determine L1 cache size!";
            return;
        }

        char* data = new char[cacheSize * 1024];
        for (int i = 0; i < cacheSize * 1024; ++i) {
            data[i] = rand() % 256;
        }
        delete[] data;

        qDebug() << "Cache stress test stopped";
    }
};*/

/*class RAMStressTester : public QThread {
public:
    void run() override {
        qDebug() << "Starting RAM stress test";
        const int arraySize = 1024 * 1024 * 100; // 100 MB

        while (!isInterruptionRequested()) {
            int* array = new int[arraySize];

            for (int i = 0; i < arraySize; ++i) {
                array[i] = QRandomGenerator::global()->generate();
            }
            for (int i = 0; i < arraySize; ++i) {
                array[i] ^= QRandomGenerator::global()->generate();
            }
            QThread::msleep(10); // Имитация нагрузки

            delete[] array;
        }

        qDebug() << "RAM stress test stopped";
    }
};*/

/*class LocalDiskStressTester : public QThread {
    Q_OBJECT
public:
    explicit LocalDiskStressTester(const QString &rootPath, QObject *parent = nullptr)
        : QThread(parent), rootPath(rootPath) {}

    void run() override {
        qDebug() << "Starting Disk stress test on" << rootPath;

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

        qDebug() << "Disk stress test completed on" << rootPath;
    }

private:
    QString rootPath;

    void stressTestDisk(const QString& path) {
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
};*/

/*class DiskTesterManager {
public:
    DiskTesterManager() = default;

    ~DiskTesterManager() {
        stopAllTests();
    }

    void startAllTests() {
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

    void stopAllTests() {
        for (LocalDiskStressTester* tester : diskStressTesters) {
            tester->requestInterruption();
            tester->wait();
            delete tester;
        }
        diskStressTesters.clear();
    }

private:
    QList<LocalDiskStressTester*> diskStressTesters;
};*/


/*class GPUStressTester : public QThread, protected QOpenGLFunctions {
public:
    void run() override {
        QOpenGLContext context;
        context.create();
        if (!context.isValid()) {
            qDebug() << "Failed to create OpenGL context";
            return;
        }

        QOffscreenSurface surface;
        surface.create();
        if (!surface.isValid()) {
            qDebug() << "Failed to create offscreen surface";
            return;
        }

        context.makeCurrent(&surface);
        initializeOpenGLFunctions();

        qDebug() << "Starting GPU stress test";
        while (!isInterruptionRequested()) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            for (int i = 0; i < 100000; ++i) {
                glBegin(GL_TRIANGLES);
                glVertex2f(-0.5f, -0.5f);
                glVertex2f(0.5f, -0.5f);
                glVertex2f(0.0f, 0.5f);
                glEnd();
            }
            context.swapBuffers(&surface);
            QThread::msleep(10); // Имитация нагрузки
        }
        qDebug() << "GPU stress test stopped";
    }
};*/


class StressTestApp : public QMainWindow
{
    Q_OBJECT

public:
    StressTestApp(QWidget *parent = nullptr);
    ~StressTestApp();

private slots:
    void on_start_pushButton_clicked();
    void on_stop_pushButton_clicked();
    void on_clear_pushButton_clicked();

private:
    Ui::StressTestApp *ui;
    QTimer* timer;
    QTime* time;

    //CPUStressTester cpuStressTester;
    CPUStressTester* cpuStressTester;
    FPUStressTester* fpuStressTester;
    CacheStressTester* cacheStressTester;
    RAMStressTester* ramStressTester;
    DiskTesterManager* diskTesterManager;
    GPUStressTester *gpuStressTester;

    void updateCurrentDateTime();
    void startOrResumeTimer();
    void stopTimer();
    void updateTimerLabel();
};

#endif // STRESSTESTAPP_H
