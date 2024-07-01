#ifndef GPUSTRESSTESTER_H
#define GPUSTRESSTESTER_H

#include "libs.h"
#include <QOpenGLFunctions>
#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class GPUStressTester : public AbstractStressTester, protected QOpenGLFunctions {
public:
    void run() override;

private:
    const char* vertexShaderSource = R"(
        #version 330 core
        layout(location = 0) in vec3 aPos;
        void main() {
            gl_Position = vec4(aPos, 1.0);
        }
    )";

    const char* fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;
        void main() {
            FragColor = vec4(0.5, 0.0, 0.5, 1.0);
        }
    )";
};

#endif // GPUSTRESSTESTER_H
