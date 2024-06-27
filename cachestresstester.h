#ifndef CACHESTRESSTESTER_H
#define CACHESTRESSTESTER_H

#include "libs.h"

class CacheStressTester : public QThread {
public:
    void run() override;
};

#endif // CACHESTRESSTESTER_H
