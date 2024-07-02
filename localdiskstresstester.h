#ifndef LOCALDISKSTRESSTESTER_H
#define LOCALDISKSTRESSTESTER_H

#include "libs.h"

class LocalDiskStressTester : public AbstractStressTester
{
    Q_OBJECT

public:
    explicit LocalDiskStressTester(const QString &rootPath, QObject *parent = nullptr);

    void run() override;

private:
    QString rootPath;

    void stressTestDisk(const QString& path);
};

#endif // LOCALDISKSTRESSTESTER_H
