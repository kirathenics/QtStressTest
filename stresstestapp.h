#ifndef STRESSTESTAPP_H
#define STRESSTESTAPP_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QTime>

#include <QThread>
#include <QDebug>
#include <QtMath>
#include <QRandomGenerator>

#include <QThreadPool>
#include <QThread>
#include <QThreadPool>
#include <QRunnable>
#include <QAtomicInt>

#include <windows.h>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class StressTestApp; }
QT_END_NAMESPACE


class CPURunnable : public QRunnable {
public:
    CPURunnable(QAtomicInt* stopFlag) : stopFlag(stopFlag) {}
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
};

class CPUCoresStressTester {
public:
    CPUCoresStressTester() : stopFlag(0) {}
    void start();
    void stop();

private:
    QThreadPool threadPool;
    QAtomicInt stopFlag;
};

//class CPUStressTester : public QThread {
//public:
//    void run() override {
//        qDebug() << "Starting CPU stress test";
//        double result = 0;
//        while (!isInterruptionRequested()) {
//            for (int i = 0; i < 1000000; ++i) {
//                result += qSin(QRandomGenerator::global()->generate());
//            }
//            QThread::msleep(10); // Имитация нагрузки
//        }
//        qDebug() << "CPU stress test stopped";
//    }
//};

class FPUStressTester : public QThread {
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
};

class CacheStressTester : public QThread {
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
};

class RAMStressTester : public QThread {
public:
    void run() override {
        MEMORYSTATUSEX status;
        status.dwLength = sizeof(status);
        GlobalMemoryStatusEx(&status);
        unsigned long long totalMemory = status.ullTotalPhys;
        unsigned long long availableMemory = status.ullAvailPhys;

        qDebug() << "Starting RAM stress test for available memory size" << availableMemory << "bytes";

        if (totalMemory <= 0) {
            qDebug() << "Error! Unable to determine total memory size!";
            return;
        }

        char* data = new char[availableMemory];
        for (unsigned long long i = 0; i < availableMemory; ++i) {
            data[i] = rand() % 256;
        }
        delete[] data;

        qDebug() << "RAM stress test stopped";
    }
};

class LocalDiskStressTester : public QThread {
public:
    void run() override {
        // Получаем список всех локальных дисков
        std::vector<QString> drives;
        DWORD drivesMask = GetLogicalDrives();
        for (char i = 'A'; i <= 'Z'; ++i) {
            if (drivesMask & 1) {
                QString drive = QString(i) + ":/";
                drives.push_back(drive);
            }
            drivesMask >>= 1;
        }

        // Проходимся по каждому диску и тестируем его
        for (const QString& drive : drives) {
            qDebug() << "Starting disk stress test for drive" << drive;

            // Открываем диск для записи
            //HANDLE hDrive = CreateFile(drive.toStdWString().c_str(), GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
            HANDLE hDrive = CreateFile(drive.toStdWString().c_str(), GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hDrive == INVALID_HANDLE_VALUE) {
                qDebug() << "Unable to open drive for write" << drive;
                continue;
            }

            // Генерируем и записываем тестовые данные на диск
            const int dataSize = 1024 * 1024; // 1 MB
            std::vector<char> data(dataSize, 0);
            DWORD bytesWritten;
            if (!WriteFile(hDrive, data.data(), dataSize, &bytesWritten, NULL)) {
                qDebug() << "Error writing test data to drive" << drive;
            }

            // Закрываем диск
            CloseHandle(hDrive);

            qDebug() << "Disk stress test for drive" << drive << "stopped";
        }
    }
};


class StressTestApp : public QMainWindow
{
    Q_OBJECT

public:
    StressTestApp(QWidget *parent = nullptr);
    ~StressTestApp();

private slots:
    void on_start_pushButton_clicked();
    void on_stop_pushButton_clicked();

private:
    Ui::StressTestApp *ui;
    QTimer* timer;
    QTime* time;

    CPUCoresStressTester cpuStressTester;
//    CPUStressTester* cpuStressTester;
    FPUStressTester* fpuStressTester;
    CacheStressTester* cacheStressTester;
    RAMStressTester* ramStressTester;
    LocalDiskStressTester* localDiskStressTester;

    void updateCurrentDateTime();
    void startOrResumeTimer();
    void stopTimer();
    void updateTimerLabel();

    //unsigned long long FibonacciFunction(int n);
};
#endif // STRESSTESTAPP_H
