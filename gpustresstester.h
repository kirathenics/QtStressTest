#ifndef GPUSTRESSTESTER_H
#define GPUSTRESSTESTER_H

#include "libs.h"
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QtOpenGLWidgets/QtOpenGLWidgets>
#include <QtOpenGL>

class GPUStressTester : public QThread, protected QOpenGLFunctions {
public:
    void run() override;
};

#endif // GPUSTRESSTESTER_H
