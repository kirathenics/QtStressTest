#ifndef ABSTRACTSTRESSTESTER_H
#define ABSTRACTSTRESSTESTER_H

#include "libs.h"

class AbstractStressTester : public QThread
{
    Q_OBJECT

public:
    explicit AbstractStressTester(QObject *parent = nullptr);

    void run() override;

    void stop();

signals:
    void logMessage(const QString &message);
};

#endif // ABSTRACTSTRESSTESTER_H
