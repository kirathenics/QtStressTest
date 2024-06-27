#include "cachestresstester.h"

void CacheStressTester::run() {
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
