#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class Logger : public QObject
{
    Q_OBJECT

public:
    explicit Logger(QObject *parent = nullptr);

    void addLog(const QString &message);
    bool saveLogsToFile(const QString &fileName);

    const QStringList& getLogs() const;

signals:
    void logUpdated(const QString &log);

private:
    QStringList logs;
};

#endif // LOGGER_H
