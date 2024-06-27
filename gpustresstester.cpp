#include "gpustresstester.h"

void GPUStressTester::run() {
    QOpenGLContext context;
    context.create();
    if (!context.isValid()) {
        qDebug() << "Failed to create OpenGL context";
        return;
    }

    QOffscreenSurface surface;
    surface.create();
    if (!surface.isValid()) {
        qDebug() << "Failed to create offscreen surface";
        return;
    }

    context.makeCurrent(&surface);
    initializeOpenGLFunctions();

    qDebug() << "Starting GPU stress test";
    while (!isInterruptionRequested()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        for (int i = 0; i < 100000; ++i) {
            glBegin(GL_TRIANGLES);
            glVertex2f(-0.5f, -0.5f);
            glVertex2f(0.5f, -0.5f);
            glVertex2f(0.0f, 0.5f);
            glEnd();
        }
        context.swapBuffers(&surface);
        QThread::msleep(10); // Имитация нагрузки
    }
    qDebug() << "GPU stress test stopped";
}
