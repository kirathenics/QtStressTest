#ifndef ABSTRACTSTRESSTESTER_H
#define ABSTRACTSTRESSTESTER_H

#include "libs.h"

class AbstractStressTester : public QThread
{
public:
    void run() override;

    void stop();
};

#endif // ABSTRACTSTRESSTESTER_H
