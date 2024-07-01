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
    /*using CPUInfo = SYSTEM_LOGICAL_PROCESSOR_INFORMATION;
    DWORD len = 0;
    CPUInfo* buffer = nullptr;

    // Determine required length of a buffer
    if ((GetLogicalProcessorInformation(buffer, &len) == FALSE) && (GetLastError() == ERROR_INSUFFICIENT_BUFFER))
    {
        // Allocate buffer of required size
        buffer = new (std::nothrow) CPUInfo[len]{ };

        if (buffer == nullptr)
        {
            qDebug() << "Buffer allocation of " << len << " bytes failed";
        }
        else if (GetLogicalProcessorInformation(buffer, &len) != FALSE)
        {
            const DWORD count = len / sizeof(CPUInfo);
            for (DWORD i = 0; i < count; ++i)
            {
                // This will be true for multiple returned caches, we need just one
                if (buffer[i].Relationship == RelationCache)
                {
                    qDebug() << "Cache line size is: " << buffer[i].Cache.LineSize << " bytes";
                    break;
                }
            }
        }
        else
        {
            qDebug() << "ERROR: " << GetLastError();
        }

        delete[] buffer;
    }*/

    char* data = new char[cacheSize * 1024];
    for (int i = 0; i < cacheSize * 1024; ++i) {
        data[i] = rand() % 256;
    }
    delete[] data;

    qDebug() << "Cache stress test stopped";
}
