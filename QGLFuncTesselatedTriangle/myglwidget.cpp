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

    f->glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, ":/resources/vertexShader.vsh");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::TessellationControl, ":/resources/tesselationControlShader.tcsh");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::TessellationEvaluation, ":/resources/tesselationEvalShader.tesh");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, ":/resources/fragmentShader.fsh");

    shaderProgram.link();

    g->glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void MyGLWidget::paintGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram.bind();
    f->glDrawArrays(GL_PATCHES, 0, 3);
    shaderProgram.release();

//    draw_lineramble();
//    f->glFlush();
}

void MyGLWidget::resizeGL(int width, int height)
{

    if (height == 0) {
        height = 1;
    }

    qDebug() << width << ", " << height;
    glViewport(0, 0, width, height);
}

void MyGLWidget::draw_lineramble()
{
    GLfloat x, y, z, angle;

    glBegin(GL_LINES);

    z = 0.0f;

    for (angle = 0.0f; angle <= 3.141592; angle += (3.141592/20.0f)) {
        x = 50.0f * sin(angle);
        y = 50.0f * cos(angle);
        glVertex3f (x, y, z);

        x = 50.0f*sin(angle+3.141592);
        y = 50.0f*cos(angle+3.141592);
        glVertex3f (x, y, z);
    }

    glEnd();
}
