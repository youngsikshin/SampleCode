#include <QtWidgets>
#include <QtOpenGL>
#include <QVector3D>
#include <iostream>
#include <QSurfaceFormat>
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

    f->glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/resources/vertexShader.vsh");
    shaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/resources/fragmentShader.fsh");
    shaderProgram.link();

}

void MyGLWidget::paintGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram.bind();

    GLfloat attrib[] = { (float)sin(cur_time/100.0) * 0.5f,
                         (float)cos(cur_time/100.0) * 0.6f,
                         0.0f,
                         0.0f};


    f->glVertexAttrib4fv(0, attrib);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    shaderProgram.release();

}

void MyGLWidget::resizeGL(int width, int height)
{

    if (height == 0) {
        height = 1;
    }

    qDebug() << width << ", " << height;
    glViewport(0, 0, width, height);
}
