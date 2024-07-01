/********************************************************************************
** Form generated from reading UI file 'stresstestapp.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRESSTESTAPP_H
#define UI_STRESSTESTAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StressTestApp
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *buttons_horizontalLayout;
    QPushButton *start_pushButton;
    QPushButton *stop_pushButton;
    QPushButton *clear_pushButton;
    QPushButton *saveLogs_pushButton;
    QTabWidget *tabWidget;
    QWidget *temperatures;
    QWidget *coolingFans;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *time_horizontalLayout;
    QLabel *testStarted_label;
    QLabel *currentDateTime_label;
    QLabel *elapsedTime_label;
    QLabel *timer_label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *checkBoxes_verticalLayout;
    QCheckBox *cpu_checkBox;
    QCheckBox *fpu_checkBox;
    QCheckBox *cache_checkBox;
    QCheckBox *ram_checkBox;
    QCheckBox *localDisk_checkBox;
    QCheckBox *gpu_checkBox;
    QTableWidget *logs_tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StressTestApp)
    {
        if (StressTestApp->objectName().isEmpty())
            StressTestApp->setObjectName(QString::fromUtf8("StressTestApp"));
        StressTestApp->resize(800, 700);
        centralwidget = new QWidget(StressTestApp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 590, 401, 41));
        buttons_horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        buttons_horizontalLayout->setObjectName(QString::fromUtf8("buttons_horizontalLayout"));
        buttons_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        start_pushButton = new QPushButton(horizontalLayoutWidget);
        start_pushButton->setObjectName(QString::fromUtf8("start_pushButton"));

        buttons_horizontalLayout->addWidget(start_pushButton);

        stop_pushButton = new QPushButton(horizontalLayoutWidget);
        stop_pushButton->setObjectName(QString::fromUtf8("stop_pushButton"));

        buttons_horizontalLayout->addWidget(stop_pushButton);

        clear_pushButton = new QPushButton(horizontalLayoutWidget);
        clear_pushButton->setObjectName(QString::fromUtf8("clear_pushButton"));

        buttons_horizontalLayout->addWidget(clear_pushButton);

        saveLogs_pushButton = new QPushButton(horizontalLayoutWidget);
        saveLogs_pushButton->setObjectName(QString::fromUtf8("saveLogs_pushButton"));

        buttons_horizontalLayout->addWidget(saveLogs_pushButton);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(70, 220, 671, 281));
        temperatures = new QWidget();
        temperatures->setObjectName(QString::fromUtf8("temperatures"));
        tabWidget->addTab(temperatures, QString());
        coolingFans = new QWidget();
        coolingFans->setObjectName(QString::fromUtf8("coolingFans"));
        tabWidget->addTab(coolingFans, QString());
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(80, 530, 401, 41));
        time_horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_2);
        time_horizontalLayout->setObjectName(QString::fromUtf8("time_horizontalLayout"));
        time_horizontalLayout->setContentsMargins(0, 0, 0, 0);
        testStarted_label = new QLabel(horizontalLayoutWidget_2);
        testStarted_label->setObjectName(QString::fromUtf8("testStarted_label"));
        testStarted_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        time_horizontalLayout->addWidget(testStarted_label);

        currentDateTime_label = new QLabel(horizontalLayoutWidget_2);
        currentDateTime_label->setObjectName(QString::fromUtf8("currentDateTime_label"));
        currentDateTime_label->setMinimumSize(QSize(125, 0));
        currentDateTime_label->setAlignment(Qt::AlignCenter);

        time_horizontalLayout->addWidget(currentDateTime_label);

        elapsedTime_label = new QLabel(horizontalLayoutWidget_2);
        elapsedTime_label->setObjectName(QString::fromUtf8("elapsedTime_label"));
        elapsedTime_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        time_horizontalLayout->addWidget(elapsedTime_label);

        timer_label = new QLabel(horizontalLayoutWidget_2);
        timer_label->setObjectName(QString::fromUtf8("timer_label"));
        timer_label->setAlignment(Qt::AlignCenter);

        time_horizontalLayout->addWidget(timer_label);

        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 20, 191, 164));
        checkBoxes_verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        checkBoxes_verticalLayout->setObjectName(QString::fromUtf8("checkBoxes_verticalLayout"));
        checkBoxes_verticalLayout->setContentsMargins(0, 0, 0, 0);
        cpu_checkBox = new QCheckBox(verticalLayoutWidget);
        cpu_checkBox->setObjectName(QString::fromUtf8("cpu_checkBox"));

        checkBoxes_verticalLayout->addWidget(cpu_checkBox);

        fpu_checkBox = new QCheckBox(verticalLayoutWidget);
        fpu_checkBox->setObjectName(QString::fromUtf8("fpu_checkBox"));

        checkBoxes_verticalLayout->addWidget(fpu_checkBox);

        cache_checkBox = new QCheckBox(verticalLayoutWidget);
        cache_checkBox->setObjectName(QString::fromUtf8("cache_checkBox"));

        checkBoxes_verticalLayout->addWidget(cache_checkBox);

        ram_checkBox = new QCheckBox(verticalLayoutWidget);
        ram_checkBox->setObjectName(QString::fromUtf8("ram_checkBox"));

        checkBoxes_verticalLayout->addWidget(ram_checkBox);

        localDisk_checkBox = new QCheckBox(verticalLayoutWidget);
        localDisk_checkBox->setObjectName(QString::fromUtf8("localDisk_checkBox"));

        checkBoxes_verticalLayout->addWidget(localDisk_checkBox);

        gpu_checkBox = new QCheckBox(verticalLayoutWidget);
        gpu_checkBox->setObjectName(QString::fromUtf8("gpu_checkBox"));

        checkBoxes_verticalLayout->addWidget(gpu_checkBox);

        logs_tableWidget = new QTableWidget(centralwidget);
        logs_tableWidget->setObjectName(QString::fromUtf8("logs_tableWidget"));
        logs_tableWidget->setGeometry(QRect(330, 20, 411, 171));
        StressTestApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StressTestApp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        StressTestApp->setMenuBar(menubar);
        statusbar = new QStatusBar(StressTestApp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StressTestApp->setStatusBar(statusbar);

        retranslateUi(StressTestApp);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StressTestApp);
    } // setupUi

    void retranslateUi(QMainWindow *StressTestApp)
    {
        StressTestApp->setWindowTitle(QCoreApplication::translate("StressTestApp", "StressTestApp", nullptr));
        start_pushButton->setText(QCoreApplication::translate("StressTestApp", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        stop_pushButton->setText(QCoreApplication::translate("StressTestApp", "\320\241\321\202\320\276\320\277", nullptr));
        clear_pushButton->setText(QCoreApplication::translate("StressTestApp", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        saveLogs_pushButton->setText(QCoreApplication::translate("StressTestApp", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(temperatures), QCoreApplication::translate("StressTestApp", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\321\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(coolingFans), QCoreApplication::translate("StressTestApp", "\320\222\320\265\320\275\321\202\320\270\320\273\321\217\321\202\320\276\321\200\321\213", nullptr));
        testStarted_label->setText(QCoreApplication::translate("StressTestApp", "\320\242\320\265\321\201\321\202 \320\275\320\260\321\207\320\260\320\273\321\201\321\217:", nullptr));
        currentDateTime_label->setText(QString());
        elapsedTime_label->setText(QCoreApplication::translate("StressTestApp", "\320\237\321\200\320\276\321\210\320\273\320\276 \320\262\321\200\320\265\320\274\320\265\320\275\320\270:", nullptr));
        timer_label->setText(QCoreApplication::translate("StressTestApp", "00:00:00", nullptr));
        cpu_checkBox->setText(QCoreApplication::translate("StressTestApp", "CPU", nullptr));
        fpu_checkBox->setText(QCoreApplication::translate("StressTestApp", "FPU", nullptr));
        cache_checkBox->setText(QCoreApplication::translate("StressTestApp", "Cache", nullptr));
        ram_checkBox->setText(QCoreApplication::translate("StressTestApp", "RAM", nullptr));
        localDisk_checkBox->setText(QCoreApplication::translate("StressTestApp", "Local disk(s)", nullptr));
        gpu_checkBox->setText(QCoreApplication::translate("StressTestApp", "GPU(s)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StressTestApp: public Ui_StressTestApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRESSTESTAPP_H
