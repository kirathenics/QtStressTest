#include "stresstestapp.h"
#include "ui_stresstestapp.h"

#include <QProcess>
#include <QDebug>

#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

StressTestApp::StressTestApp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StressTestApp)
    , cpuStressTester(nullptr)
    , fpuStressTester(nullptr)
    , cacheStressTester(nullptr)
    , ramStressTester(nullptr)
    , diskTesterManager(nullptr)
    , gpuStressTester(nullptr)
    //, key(0)
{
    ui->setupUi(this);

    // Настройка таблицы логов
    ui->logs_tableWidget->setColumnCount(2);
    QStringList tableHeaders;
    tableHeaders << "Дата/Время" << "Событие";
    ui->logs_tableWidget->setHorizontalHeaderLabels(tableHeaders);
    ui->logs_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Убираем вертикальные заголовки
    ui->logs_tableWidget->verticalHeader()->setVisible(false);

    // Устанавливаем фиксированную ширину для колонки "Дата/Время" и динамическую ширину для "Событие"
    ui->logs_tableWidget->setColumnWidth(0, 125);
    ui->logs_tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);


    /*//tab
    // Внутри конструктора StressTestApp или соответствующего метода
    QWidget *voltageTab = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(voltageTab);

    QTableWidget *voltageTable = new QTableWidget();
    voltageTable->setColumnCount(4);
    QStringList voltageHeaders;
    voltageHeaders << "Текущие" << "Минимальные" << "Максимальные" << "Средние";
    voltageTable->setHorizontalHeaderLabels(voltageHeaders);
    voltageTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    layout->addWidget(voltageTable);
    ui->tabWidget->addTab(voltageTab, "Напряжения");

    // Сохраните указатель на таблицу для последующего использования
    this->voltageTable = voltageTable;

    // Инициализация таймера для обновления информации о напряжениях
    QTimer *voltageUpdateTimer = new QTimer(this);
    connect(voltageUpdateTimer, &QTimer::timeout, this, &StressTestApp::updateVoltageInfo);
    voltageUpdateTimer->start(1000); // Обновление каждые 1 секунд

    // Первоначальное обновление информации о напряжениях
    updateVoltageInfo();*/

    ui->currentDateTime_label->setText("");
    ui->timer_label->setText("00:00:00");

    timer = new QTimer(this);
    timer->setInterval(1000);
    time = new QTime(0, 0, 0);

    /*cpuLoadTimer = new QTimer(this);
    connect(cpuLoadTimer, &QTimer::timeout, this, &StressTestApp::updateCpuLoadGraph);
    cpuLoadTimer->start(1000);

    setupCpuLoadGraph();*/

    ui->cpu_checkBox->setChecked(false);
    ui->fpu_checkBox->setChecked(true);
    ui->cache_checkBox->setChecked(false);
    ui->ram_checkBox->setChecked(false);
    ui->localDisk_checkBox->setChecked(false);
    ui->gpu_checkBox->setChecked(false);

    ui->stop_pushButton->setEnabled(false);

    connect(timer, &QTimer::timeout, this, &StressTestApp::updateTimerLabel);
}

StressTestApp::~StressTestApp()
{
    /*if (cpuStressTester) {
        cpuStressTester->stop();
        delete cpuStressTester;
    }

    if (fpuStressTester) {
        fpuStressTester->stop();
        delete fpuStressTester;
    }

    if (cacheStressTester) {
        cacheStressTester->stop();
        delete cacheStressTester;
    }

    if (ramStressTester) {
        ramStressTester->stop();
        delete ramStressTester;
    }

    if (diskTesterManager) {
        diskTesterManager->stop();
        delete diskTesterManager;
    }

    if (gpuStressTester) {
        gpuStressTester->stop();
        delete gpuStressTester;
    }*/

    auto stopAndDeleteTester = [](auto* tester) {
        if (tester) {
            tester->stop();
            delete tester;
        }
    };

    stopAndDeleteTester(cpuStressTester);
    stopAndDeleteTester(fpuStressTester);
    stopAndDeleteTester(cacheStressTester);
    stopAndDeleteTester(ramStressTester);
    stopAndDeleteTester(diskTesterManager);
    stopAndDeleteTester(gpuStressTester);

    qDebug() << "Program closed";

    delete ui;
}


void StressTestApp::updateCurrentDateTime() {
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
    ui->currentDateTime_label->setText(dateTimeString);
}

void StressTestApp::startOrResumeTimer() {
    if (!timer->isActive()) {
        timer->start();
    }
}

void StressTestApp::stopTimer() {
    if (timer->isActive()) {
        timer->stop();
    }
}

void StressTestApp::updateTimerLabel() {
    *time = time->addSecs(1);
    ui->timer_label->setText(time->toString("HH:mm:ss"));
}



void StressTestApp::on_start_pushButton_clicked()
{
    ui->start_pushButton->setEnabled(false);
    ui->stop_pushButton->setEnabled(true);

    updateCurrentDateTime();
    startOrResumeTimer();

    qDebug() << "System test started";
    addLogEntry("Тест системы начался!");

//    // Лямбда-функция для управления тестерами
//    auto startTester = [](auto*& tester, auto* newTester) {
//        if (tester) {
//            tester->stop();
//            delete tester;
//        }
//        tester = newTester;
//        if (tester) {
//            tester->run();
//        }
//    };

//    // Управление тестерами
//    if (ui->cpu_checkBox->isChecked()) {
//        startTester(cpuStressTester, new CPUStressTester());
//    }
//    if (ui->fpu_checkBox->isChecked()) {
//        startTester(fpuStressTester, new FPUStressTester());
//    }
//    if (ui->cache_checkBox->isChecked()) {
//        startTester(cacheStressTester, new CacheStressTester());
//    }
//    if (ui->ram_checkBox->isChecked()) {
//        startTester(ramStressTester, new RAMStressTester());
//    }
//    if (ui->localDisk_checkBox->isChecked()) {
//        startTester(diskTesterManager, new DiskTesterManager());
//    }
//    if (ui->gpu_checkBox->isChecked()) {
//        startTester(gpuStressTester, new GPUStressTester());
//    }

    if (ui->cpu_checkBox->isChecked()) {
        if (cpuStressTester) {
            cpuStressTester->stop();
            delete cpuStressTester;
        }
        cpuStressTester = new CPUStressTester();
        cpuStressTester->run();
    }

    if (ui->fpu_checkBox->isChecked()) {
        if (fpuStressTester) {
            fpuStressTester->stop();
            delete fpuStressTester;
        }
        fpuStressTester = new FPUStressTester();
        fpuStressTester->start();
    }

    if (ui->cache_checkBox->isChecked()) {
        if (cacheStressTester) {
            cacheStressTester->stop();
            delete cacheStressTester;
        }
        cacheStressTester = new CacheStressTester();
        cacheStressTester->start();
    }

    if (ui->ram_checkBox->isChecked()) {
        if (ramStressTester) {
            ramStressTester->stop();
            delete ramStressTester;
        }
        ramStressTester = new RAMStressTester();
        ramStressTester->start();
    }

    if (ui->localDisk_checkBox->isChecked()) {
        if (diskTesterManager) {
            diskTesterManager->stop();
            delete diskTesterManager;
        }
        diskTesterManager = new DiskTesterManager();
        diskTesterManager->run();
    }

    if (ui->gpu_checkBox->isChecked()) {
        if (gpuStressTester) {
            gpuStressTester->stop();
            delete gpuStressTester;
        }
        gpuStressTester = new GPUStressTester();
        gpuStressTester->start();
    }
}


void StressTestApp::on_stop_pushButton_clicked()
{
    ui->start_pushButton->setEnabled(true);
    ui->stop_pushButton->setEnabled(false);
    stopTimer();

    /*if (cpuStressTester) {
        cpuStressTester->stop();
        delete cpuStressTester;
        cpuStressTester = nullptr;
    }

    if (fpuStressTester) {
        fpuStressTester->stop();
        delete fpuStressTester;
        fpuStressTester = nullptr;
    }

    if (cacheStressTester) {
        cacheStressTester->stop();
        delete cacheStressTester;
        cacheStressTester = nullptr;
    }

    if (ramStressTester) {
        ramStressTester->stop();
        delete ramStressTester;
        ramStressTester = nullptr;
    }

    if (diskTesterManager) {
        diskTesterManager->stop();
        delete diskTesterManager;
        diskTesterManager = nullptr;
    }

    if (gpuStressTester) {
        gpuStressTester->stop();
        delete gpuStressTester;
        gpuStressTester = nullptr;
    }*/

    // Лямбда-функция для остановки и удаления тестеров
    auto stopAndDeleteTester = [](auto*& tester) {
        if (tester) {
            tester->stop();
            delete tester;
            tester = nullptr;
        }
    };

    // Остановка и удаление тестеров
    stopAndDeleteTester(cpuStressTester);
    stopAndDeleteTester(fpuStressTester);
    stopAndDeleteTester(cacheStressTester);
    stopAndDeleteTester(ramStressTester);
    stopAndDeleteTester(diskTesterManager);
    stopAndDeleteTester(gpuStressTester);

    qDebug() << "System test stopped";
    addLogEntry("Тест системы завершился!");
}

void StressTestApp::on_clear_pushButton_clicked()
{
    //TODO: clear graphs
    ui->logs_tableWidget->setRowCount(0); // Очищаем таблицу логов

    if (ui->start_pushButton->isEnabled()) {
        ui->currentDateTime_label->setText("");
        ui->timer_label->setText("00:00:00");
        time = new QTime(0, 0, 0);
    }
}

void StressTestApp::addLogEntry(const QString &action)
{
    int row = ui->logs_tableWidget->rowCount();
    ui->logs_tableWidget->insertRow(row);

    QTableWidgetItem *dateTimeItem = new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    QTableWidgetItem *actionItem = new QTableWidgetItem(action);

    ui->logs_tableWidget->setItem(row, 0, dateTimeItem);
    ui->logs_tableWidget->setItem(row, 1, actionItem);
}

/*void StressTestApp::setupCpuLoadGraph()
{
    ui->cpuLoad_Plot->addGraph();
    cpuLoadGraph = ui->cpuLoad_Plot->graph(0);
    cpuLoadGraph->setPen(QPen(Qt::blue));
    ui->cpuLoad_Plot->xAxis->setLabel("Время, с");
    ui->cpuLoad_Plot->yAxis->setLabel("Загрузка ЦП (%)");
    ui->cpuLoad_Plot->yAxis->setRange(0, 100);
    ui->cpuLoad_Plot->xAxis->setRange(0, 60);
}

void StressTestApp::updateCpuLoadGraph()
{
    double cpuLoad = getCpuLoad();
    key += 1;

    cpuLoadGraph->addData(key, cpuLoad);
    //cpuLoadGraph->removeDataBefore(key - 60);
    cpuLoadGraph->data().clear();
    ui->cpuLoad_Plot->rescaleAxes();
    ui->cpuLoad_Plot->replot();
}*/


double StressTestApp::getCPULoad() {
    static FILETIME prevIdleTime = { 0, 0 };
    static FILETIME prevKernelTime = { 0, 0 };
    static FILETIME prevUserTime = { 0, 0 };

    FILETIME idleTime, kernelTime, userTime;
    if (!GetSystemTimes(&idleTime, &kernelTime, &userTime)) {
        return 0.0;
    }

    ULARGE_INTEGER ulPrevIdleTime, ulPrevKernelTime, ulPrevUserTime;
    ulPrevIdleTime.LowPart = prevIdleTime.dwLowDateTime;
    ulPrevIdleTime.HighPart = prevIdleTime.dwHighDateTime;
    ulPrevKernelTime.LowPart = prevKernelTime.dwLowDateTime;
    ulPrevKernelTime.HighPart = prevKernelTime.dwHighDateTime;
    ulPrevUserTime.LowPart = prevUserTime.dwLowDateTime;
    ulPrevUserTime.HighPart = prevUserTime.dwHighDateTime;

    ULARGE_INTEGER ulIdleTime, ulKernelTime, ulUserTime;
    ulIdleTime.LowPart = idleTime.dwLowDateTime;
    ulIdleTime.HighPart = idleTime.dwHighDateTime;
    ulKernelTime.LowPart = kernelTime.dwLowDateTime;
    ulKernelTime.HighPart = kernelTime.dwHighDateTime;
    ulUserTime.LowPart = userTime.dwLowDateTime;
    ulUserTime.HighPart = userTime.dwHighDateTime;

    ULONGLONG diffIdleTime = ulIdleTime.QuadPart - ulPrevIdleTime.QuadPart;
    ULONGLONG diffKernelTime = ulKernelTime.QuadPart - ulPrevKernelTime.QuadPart;
    ULONGLONG diffUserTime = ulUserTime.QuadPart - ulPrevUserTime.QuadPart;
    ULONGLONG diffTotalTime = diffKernelTime + diffUserTime;

    prevIdleTime = idleTime;
    prevKernelTime = kernelTime;
    prevUserTime = userTime;

    int cpuLoad = (diffTotalTime - diffIdleTime) * 100.0 / diffTotalTime;
    return cpuLoad;
}

/*QString StressTestApp::fromBSTR(BSTR bstr) {
    int wslen = SysStringLen(bstr);
    return QString::fromUtf16((const ushort*)bstr, wslen);
}

void StressTestApp::updateVoltageInfo() {
    HRESULT hres;

    // Initialize COM.
    hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        qDebug() << "Failed to initialize COM library.";
        return;
    }

    // Set general COM security levels.
    hres = CoInitializeSecurity(
        NULL,
        -1,
        NULL,
        NULL,
        RPC_C_AUTHN_LEVEL_DEFAULT,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE,
        NULL
        );

    if (FAILED(hres)) {
        qDebug() << "Failed to initialize security.";
        CoUninitialize();
        return;
    }

    // Obtain the initial locator to WMI.
    IWbemLocator *pLoc = NULL;
    hres = CoCreateInstance(
        CLSID_WbemLocator,
        0,
        CLSCTX_INPROC_SERVER,
        IID_IWbemLocator, (LPVOID *)&pLoc);

    if (FAILED(hres)) {
        qDebug() << "Failed to create IWbemLocator object.";
        CoUninitialize();
        return;
    }

    // Connect to WMI through the IWbemLocator::ConnectServer method.
    IWbemServices *pSvc = NULL;
    hres = pLoc->ConnectServer(
        _bstr_t(L"ROOT\\CIMV2"),
        NULL,
        NULL,
        0,
        NULL,
        0,
        0,
        &pSvc
        );

    if (FAILED(hres)) {
        qDebug() << "Could not connect to WMI namespace.";
        pLoc->Release();
        CoUninitialize();
        return;
    }

    // Set security levels on the proxy.
    hres = CoSetProxyBlanket(
        pSvc,
        RPC_C_AUTHN_WINNT,
        RPC_C_AUTHZ_NONE,
        NULL,
        RPC_C_AUTHN_LEVEL_CALL,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        NULL,
        EOAC_NONE
        );

    if (FAILED(hres)) {
        qDebug() << "Could not set proxy blanket.";
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return;
    }

    // Use the IWbemServices pointer to make requests of WMI.
    IEnumWbemClassObject* pEnumerator = NULL;
    hres = pSvc->ExecQuery(
        bstr_t("WQL"),
        bstr_t("SELECT * FROM Win32_Sensor"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        NULL,
        &pEnumerator
        );

    if (FAILED(hres)) {
        qDebug() << "Query for operating system name failed.";
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return;
    }

    // Secure the result.
    IWbemClassObject *pclsObj = NULL;
    ULONG uReturn = 0;

    while (pEnumerator) {
        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if (0 == uReturn) {
            break;
        }

        VARIANT vtProp;

        // Get the value of the SensorType property.
        hr = pclsObj->Get(L"SensorType", 0, &vtProp, 0, 0);
        qDebug() << "SensorType : " << fromBSTR(vtProp.bstrVal);
        VariantClear(&vtProp);

        pclsObj->Release();
    }

    // Cleanup.
    pSvc->Release();
    pLoc->Release();
    pEnumerator->Release();
    CoUninitialize();
}*/
