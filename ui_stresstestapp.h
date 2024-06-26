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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StressTestApp
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *cpu_checkBox;
    QCheckBox *fpu_checkBox;
    QCheckBox *cache_checkBox;
    QCheckBox *ram_checkBox;
    QCheckBox *localDisk_checkBox;
    QCheckBox *gpu_checkBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *start_pushButton;
    QPushButton *stop_pushButton;
    QPushButton *clear_pushButton;
    QLabel *label;
    QLabel *currentDateTime_label;
    QLabel *label_2;
    QLabel *timer_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StressTestApp)
    {
        if (StressTestApp->objectName().isEmpty())
            StressTestApp->setObjectName(QString::fromUtf8("StressTestApp"));
        StressTestApp->resize(800, 600);
        centralwidget = new QWidget(StressTestApp);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 80, 160, 164));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cpu_checkBox = new QCheckBox(verticalLayoutWidget);
        cpu_checkBox->setObjectName(QString::fromUtf8("cpu_checkBox"));

        verticalLayout->addWidget(cpu_checkBox);

        fpu_checkBox = new QCheckBox(verticalLayoutWidget);
        fpu_checkBox->setObjectName(QString::fromUtf8("fpu_checkBox"));

        verticalLayout->addWidget(fpu_checkBox);

        cache_checkBox = new QCheckBox(verticalLayoutWidget);
        cache_checkBox->setObjectName(QString::fromUtf8("cache_checkBox"));

        verticalLayout->addWidget(cache_checkBox);

        ram_checkBox = new QCheckBox(verticalLayoutWidget);
        ram_checkBox->setObjectName(QString::fromUtf8("ram_checkBox"));

        verticalLayout->addWidget(ram_checkBox);

        localDisk_checkBox = new QCheckBox(verticalLayoutWidget);
        localDisk_checkBox->setObjectName(QString::fromUtf8("localDisk_checkBox"));

        verticalLayout->addWidget(localDisk_checkBox);

        gpu_checkBox = new QCheckBox(verticalLayoutWidget);
        gpu_checkBox->setObjectName(QString::fromUtf8("gpu_checkBox"));

        verticalLayout->addWidget(gpu_checkBox);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(137, 319, 551, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        start_pushButton = new QPushButton(horizontalLayoutWidget);
        start_pushButton->setObjectName(QString::fromUtf8("start_pushButton"));

        horizontalLayout->addWidget(start_pushButton);

        stop_pushButton = new QPushButton(horizontalLayoutWidget);
        stop_pushButton->setObjectName(QString::fromUtf8("stop_pushButton"));

        horizontalLayout->addWidget(stop_pushButton);

        clear_pushButton = new QPushButton(horizontalLayoutWidget);
        clear_pushButton->setObjectName(QString::fromUtf8("clear_pushButton"));

        horizontalLayout->addWidget(clear_pushButton);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        currentDateTime_label = new QLabel(horizontalLayoutWidget);
        currentDateTime_label->setObjectName(QString::fromUtf8("currentDateTime_label"));
        currentDateTime_label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(currentDateTime_label);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        timer_label = new QLabel(horizontalLayoutWidget);
        timer_label->setObjectName(QString::fromUtf8("timer_label"));
        timer_label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(timer_label);

        StressTestApp->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StressTestApp);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        StressTestApp->setMenuBar(menubar);
        statusbar = new QStatusBar(StressTestApp);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StressTestApp->setStatusBar(statusbar);

        retranslateUi(StressTestApp);

        QMetaObject::connectSlotsByName(StressTestApp);
    } // setupUi

    void retranslateUi(QMainWindow *StressTestApp)
    {
        StressTestApp->setWindowTitle(QCoreApplication::translate("StressTestApp", "StressTestApp", nullptr));
        cpu_checkBox->setText(QCoreApplication::translate("StressTestApp", "CPU", nullptr));
        fpu_checkBox->setText(QCoreApplication::translate("StressTestApp", "FPU", nullptr));
        cache_checkBox->setText(QCoreApplication::translate("StressTestApp", "Cache", nullptr));
        ram_checkBox->setText(QCoreApplication::translate("StressTestApp", "RAM", nullptr));
        localDisk_checkBox->setText(QCoreApplication::translate("StressTestApp", "Local disk(s)", nullptr));
        gpu_checkBox->setText(QCoreApplication::translate("StressTestApp", "GPU(s)", nullptr));
        start_pushButton->setText(QCoreApplication::translate("StressTestApp", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        stop_pushButton->setText(QCoreApplication::translate("StressTestApp", "\320\241\321\202\320\276\320\277", nullptr));
        clear_pushButton->setText(QCoreApplication::translate("StressTestApp", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("StressTestApp", "\320\235\320\260\321\207\320\260\320\273\321\201\321\217:", nullptr));
        currentDateTime_label->setText(QCoreApplication::translate("StressTestApp", "currentDateTime", nullptr));
        label_2->setText(QCoreApplication::translate("StressTestApp", "\320\237\321\200\320\276\321\210\320\273\320\276:", nullptr));
        timer_label->setText(QCoreApplication::translate("StressTestApp", "00:00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StressTestApp: public Ui_StressTestApp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRESSTESTAPP_H
