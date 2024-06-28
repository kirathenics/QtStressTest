#ifndef STRESSTESTAPP_H
#define STRESSTESTAPP_H

#include "libs.h"
#include "cpucorestresstester.h"
#include "cpustresstester.h"
#include "fpustresstester.h"
#include "cachestresstester.h"
#include "ramstresstester.h"
#include "localdiskstresstester.h"
#include "disktestermanager.h"
#include "gpustresstester.h"

#include <QTableWidgetItem>
#include <QStringList>
#include <QAbstractItemView>

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
    void on_clear_pushButton_clicked();

private:
    Ui::StressTestApp *ui;
    QTimer* timer;
    QTime* time;

    CPUStressTester* cpuStressTester;
    FPUStressTester* fpuStressTester;
    CacheStressTester* cacheStressTester;
    RAMStressTester* ramStressTester;
    DiskTesterManager* diskTesterManager;
    GPUStressTester *gpuStressTester;

    void updateCurrentDateTime();
    void startOrResumeTimer();
    void stopTimer();
    void updateTimerLabel();
    void addLogEntry(const QString &action);
};

#endif // STRESSTESTAPP_H
