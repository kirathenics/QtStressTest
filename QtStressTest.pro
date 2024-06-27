QT       += core gui opengl openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cachestresstester.cpp \
    cpucorestresstester.cpp \
    cpustresstester.cpp \
    disktestermanager.cpp \
    fpustresstester.cpp \
    gpustresstester.cpp \
    localdiskstresstester.cpp \
    main.cpp \
    ramstresstester.cpp \
    stresstestapp.cpp

HEADERS += \
    cachestresstester.h \
    cpucorestresstester.h \
    cpustresstester.h \
    disktestermanager.h \
    fpustresstester.h \
    gpustresstester.h \
    libs.h \
    localdiskstresstester.h \
    ramstresstester.h \
    stresstestapp.h

FORMS += \
    stresstestapp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -lopengl32
