#include "logger.h"

Logger::Logger(QObject *parent)
    : QObject(parent)
{
}

void Logger::addLog(const QString &message)
{
    QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    QString log = "[" + dateTime + "] " + message;

    logs.append(log);
    emit logUpdated(log);
}

bool Logger::saveLogsToFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&file);
    for (const QString &log : logs) {
        out << log << "\n";
    }

    file.close();
    return true;
}

const QStringList& Logger::getLogs() const
{
    return logs;
}
