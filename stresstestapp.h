#ifndef STRESSTESTAPP_H
#define STRESSTESTAPP_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class StressTestApp; }
QT_END_NAMESPACE

class StressTestApp : public QMainWindow
{
    Q_OBJECT

public:
    StressTestApp(QWidget *parent = nullptr);
    ~StressTestApp();

private slots:
    void on_start_pushButton_clicked();
    void on_stop_pushButton_clicked();

private:
    Ui::StressTestApp *ui;
    QTimer* timer;
    QTime* time;

    void updateCurrentDateTime();
    void startOrResumeTimer();
    void stopTimer();
    void updateTimerLabel();

    unsigned long long FibonacciFunction(int n);
};
#endif // STRESSTESTAPP_H
