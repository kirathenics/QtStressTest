QT       += core gui opengl openglwidgets charts widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17 precompile_header
PRECOMPILED_HEADER = libs.h

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractstresstester.cpp \
    cachestresstester.cpp \
    cpucorestresstester.cpp \
    cpustresstester.cpp \
    disktestermanager.cpp \
    fpustresstester.cpp \
    gpustresstester.cpp \
    localdiskstresstester.cpp \
    logger.cpp \
    main.cpp \
    ramstresstester.cpp \
    stresstestapp.cpp

HEADERS += \
    abstractstresstester.h \
    cachestresstester.h \
    cpucorestresstester.h \
    cpustresstester.h \
    disktestermanager.h \
    fpustresstester.h \
    gpustresstester.h \
    libs.h \
    localdiskstresstester.h \
    logger.h \
    ramstresstester.h \
    stresstestapp.h

FORMS += \
    stresstestapp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -lopengl32 #-lole32 -lwbemuuid -loleaut32
