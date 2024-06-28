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

    QOpenGLShaderProgram shaderProgram;
    if (!shaderProgram.addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource)) {
        qDebug() << "Failed to compile vertex shader:" << shaderProgram.log();
        return;
    }
    if (!shaderProgram.addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource)) {
        qDebug() << "Failed to compile fragment shader:" << shaderProgram.log();
        return;
    }
    if (!shaderProgram.link()) {
        qDebug() << "Failed to link shader program:" << shaderProgram.log();
        return;
    }

    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    QOpenGLVertexArrayObject vao;
    vao.create();
    vao.bind();

    QOpenGLBuffer vbo(QOpenGLBuffer::VertexBuffer);
    vbo.create();
    vbo.bind();
    vbo.allocate(vertices, sizeof(vertices));

    shaderProgram.enableAttributeArray(0);
    shaderProgram.setAttributeBuffer(0, GL_FLOAT, 0, 3, 3 * sizeof(float));

    qDebug() << "Starting GPU stress test";

    while (!isInterruptionRequested()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.bind();
        vao.bind();

        // Рендерим множество треугольников для нагрузки на GPU
        for (int i = 0; i < 1000000; ++i) {
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }

        context.swapBuffers(&surface);
        // Убираем задержку, чтобы не снижать нагрузку на GPU
    }

    vao.release();
    vbo.release();
    shaderProgram.release();

    qDebug() << "GPU stress test stopped";
}
