#ifndef STRESSTESTAPP_H
#define STRESSTESTAPP_H

#include "libs.h"
#include "cpustresstester.h"
#include "fpustresstester.h"
#include "cachestresstester.h"
#include "ramstresstester.h"
#include "disktestermanager.h"
#include "gpustresstester.h"

#include <QTableWidgetItem>
#include <QStringList>
#include <QAbstractItemView>

#include <QVBoxLayout>
#include <QTimer>
#include <QTime>
#include <QTableWidget>
#include <QHeaderView>

#include <QStringList>
#include <QFileDialog>
#include <QMessageBox>

#include <QTabWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

/*#include <comdef.h>
#include <Wbemidl.h>

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "wbemuuid.lib")
#pragma comment(lib, "oleaut32.lib")
#pragma comment(lib, "comsuppw.lib")*/

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

    void updateCpuLoadGraph();

    void on_saveLogs_pushButton_clicked();
    void handleLogMessage(const QString &message);

private:
    Ui::StressTestApp *ui;
    QTimer* testingTimer;
    QTime* testingTime;

    CPUStressTester* cpuStressTester;
    FPUStressTester* fpuStressTester;
    CacheStressTester* cacheStressTester;
    RAMStressTester* ramStressTester;
    DiskTesterManager* diskTesterManager;
    GPUStressTester *gpuStressTester;
    Logger* logger;

    QTimer *cpuLoadTimer;
    int key;

    QLineSeries *cpuSeries;
    QChart *cpuChart;
    QChartView *cpuChartView;
    QValueAxis *axisX;
    QValueAxis *axisY;

    void updateCurrentDateTime();
    void startOrResumeTimer();
    void stopTimer();
    void updateTimerLabel();
    void addLogEntry(const QString &action);

    void setupCpuLoadGraph();

    QTableWidget* cpuInfoTable;
    double getCPULoad();


    /*QTableWidget *voltageTable;

    QString fromBSTR(BSTR bstr);
    void updateVoltageInfo();*/

};

#endif // STRESSTESTAPP_H
