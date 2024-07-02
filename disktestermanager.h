#ifndef DISKTESTERMANAGER_H
#define DISKTESTERMANAGER_H

#include "localdiskstresstester.h"

class DiskTesterManager : public QObject
{
    Q_OBJECT

public:
    explicit DiskTesterManager(QObject *parent = nullptr);

    ~DiskTesterManager();

    void start();
    void stop();

signals:
    void logMessage(const QString &message);

private:
    QList<LocalDiskStressTester*> diskStressTesters;
};

#endif // DISKTESTERMANAGER_H
