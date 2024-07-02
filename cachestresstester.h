#ifndef CACHESTRESSTESTER_H
#define CACHESTRESSTESTER_H

#include "libs.h"

class CacheStressTester : public AbstractStressTester
{
    Q_OBJECT

public:
    explicit CacheStressTester(QObject *parent = nullptr);

    void run() override;
};

#endif // CACHESTRESSTESTER_H
