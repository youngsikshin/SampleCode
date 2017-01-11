#include <QtWidgets>
#include <QtOpenGL>
#include <QVector3D>
#include <iostream>
#include <QSurfaceFormat>
#include <QWindow>
#include <QOpenGLFunctions_3_3_Core>

#include <vector>

#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}


void MyGLWidget::initializeGL()
{
    // Set up the rendering context, load shaders and other resources, etc.:
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

    QOpenGLFunctions_3_3_Core *g = QOpenGLContext::currentContext()->versionFunctions<QOpenGLFunctions_3_3_Core>();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);


    f->glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/vertexShader.vsh");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/resources/fragmentShader.fsh");
    shaderProgram.link();

    static const GLfloat vertex_positions[] =
    {
        -0.25f,  0.25f, -0.25f,
        -0.25f, -0.25f, -0.25f,
         0.25f, -0.25f, -0.25f,

         0.25f, -0.25f, -0.25f,
         0.25f,  0.25f, -0.25f,
        -0.25f,  0.25f, -0.25f,

         0.25f, -0.25f, -0.25f,
         0.25f, -0.25f,  0.25f,
         0.25f,  0.25f, -0.25f,

         0.25f, -0.25f,  0.25f,
         0.25f,  0.25f,  0.25f,
         0.25f,  0.25f, -0.25f,

         0.25f, -0.25f,  0.25f,
        -0.25f, -0.25f,  0.25f,
         0.25f,  0.25f,  0.25f,

        -0.25f, -0.25f,  0.25f,
        -0.25f,  0.25f,  0.25f,
         0.25f,  0.25f,  0.25f,

        -0.25f, -0.25f,  0.25f,
        -0.25f, -0.25f, -0.25f,
        -0.25f,  0.25f,  0.25f,

        -0.25f, -0.25f, -0.25f,
        -0.25f,  0.25f, -0.25f,
        -0.25f,  0.25f,  0.25f,

        -0.25f, -0.25f,  0.25f,
         0.25f, -0.25f,  0.25f,
         0.25f, -0.25f, -0.25f,

         0.25f, -0.25f, -0.25f,
        -0.25f, -0.25f, -0.25f,
        -0.25f, -0.25f,  0.25f,

        -0.25f,  0.25f, -0.25f,
         0.25f,  0.25f, -0.25f,
         0.25f,  0.25f,  0.25f,

         0.25f,  0.25f,  0.25f,
        -0.25f,  0.25f,  0.25f,
        -0.25f,  0.25f, -0.25f
    };

    _mv_location = g->glGetUniformLocation(shaderProgram.programId(), "mv_matrix");
    _proj_location = g->glGetUniformLocation(shaderProgram.programId(), "proj_matrix");

    g->glGenVertexArrays(1, &_vao);
    g->glBindVertexArray(_vao);

    g->glGenBuffers(1, &_buffer);
    g->glBindBuffer(GL_ARRAY_BUFFER, _buffer);
    g->glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_positions), vertex_positions, GL_STATIC_DRAW);

    g->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    g->glEnableVertexAttribArray(0);
}

void MyGLWidget::paintGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

for (int i=0; i<36; i++) {
    float period = (float) cur_time * 0.0003f + 0.5*i;

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;

    mMatrix.translate(0.0f, 0.0f, -2.0f);
    vMatrix.translate(sinf(2.1f * period) * 2.5f,
                      cosf(1.7f * period) * 2.5f,
                      sinf(1.3f * period) * cosf(1.5f * period) * 2.40f);
    mMatrix.rotate((float)cur_time*0.045f, 0.0, 1.0, 0.0);
    vMatrix.rotate((float)cur_time*0.081f, 1.0, 0.0, 0.0);

//    QMatrix4x4 mMatrix;
//    QMatrix4x4 vMatrix;
//    vMatrix.lookAt(QVector3D(0, 0, 5), QVector3D(0, 0, 0), QVector3D(0, 1, 0));


    shaderProgram.bind();

    f->glUniformMatrix4fv(_mv_location, 1, GL_FALSE, (mMatrix*vMatrix).constData());
    f->glUniformMatrix4fv(_proj_location, 1, GL_FALSE, pMatrix.constData());
    f->glDrawArrays(GL_TRIANGLES, 0, 36);
    shaderProgram.release();
}
}

void MyGLWidget::resizeGL(int width, int height)
{

    if (height == 0) {
        height = 1;
    }

    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float) width / (float) height, 0.001, 1000);

    glViewport(0, 0, width, height);
}
