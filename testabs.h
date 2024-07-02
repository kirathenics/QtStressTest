#ifndef TESTABS_H
#define TESTABS_H

#include "libs.h"

class testabs : public QThread
{
    Q_OBJECT

public:
    explicit testabs(QObject *parent = nullptr);

    void run() override;

    void stop();

signals:
    void logMessage(const QString &message);
};

#endif // TESTABS_H
