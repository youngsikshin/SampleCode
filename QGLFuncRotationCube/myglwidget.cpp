#include <QtWidgets>
#include <QtOpenGL>
#include <QVector3D>
#include <iostream>

#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    alpha = 25;
    beta = -25;
    distance = 2.5;
    cam_translationX = 1.5;
    cam_translationY = 1.5;
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

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) {
        lastLeftMousePosition = event->pos();
    }
    else if (event->buttons() & Qt::RightButton) {
        lastRightMousePosition = event->pos();
    }


    event->accept();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton) {
        int deltaX = event->x() - lastLeftMousePosition.x();
        int deltaY = event->y() - lastLeftMousePosition.y();

        alpha -= deltaX;
        while (alpha < 0) {
            alpha += 360;
        }

        while (alpha >= 360) {
            alpha -= 360;
        }

        beta -= deltaY;
        if (beta < -90) {
            beta = -90;
        }
        if (beta > 90) {
            beta = 90;
        }

        updateGL();

        lastLeftMousePosition = event->pos();
    }    
    else if(event->buttons() & Qt::RightButton) {
        int deltaX = event->x() - lastRightMousePosition.x();
        int deltaY = event->y() - lastRightMousePosition.y();

        if (deltaX < 0) cam_translationX += 0.1;
        else if(deltaX > 0) cam_translationX -= 0.1;

        if (deltaY < 0) cam_translationY *= 1.1;
        else if(deltaY > 0) cam_translationY *= 0.9;

        updateGL();
    }

    event->accept();
}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();

    if (event->orientation() == Qt::Vertical) {
        if (delta < 0) {
            distance *= 1.1;
        }
        else if (delta > 0) {
            distance *= 0.9;
        }

        updateGL();
    }

    event->accept();
}

void MyGLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    qglClearColor(Qt::black);

    shaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/resources/vertexShader.vsh");
    shaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/resources/fragmentShader.fsh");
    shaderProgram.link();

    vertices << QVector3D(-0.5, -0.5,  0.5)*0.1 << QVector3D( 0.5, -0.5,  0.5)*0.1 << QVector3D( 0.5,  0.5,  0.5)*0.1 // Front
             << QVector3D( 0.5,  0.5,  0.5)*0.1 << QVector3D(-0.5,  0.5,  0.5)*0.1 << QVector3D(-0.5, -0.5,  0.5)*0.1
             << QVector3D( 0.5, -0.5, -0.5)*0.1 << QVector3D(-0.5, -0.5, -0.5)*0.1 << QVector3D(-0.5,  0.5, -0.5)*0.1 // Back
             << QVector3D(-0.5,  0.5, -0.5)*0.1 << QVector3D( 0.5,  0.5, -0.5)*0.1 << QVector3D( 0.5, -0.5, -0.5)*0.1
             << QVector3D(-0.5, -0.5, -0.5)*0.1 << QVector3D(-0.5, -0.5,  0.5)*0.1 << QVector3D(-0.5,  0.5,  0.5)*0.1 // Left
             << QVector3D(-0.5,  0.5,  0.5)*0.1 << QVector3D(-0.5,  0.5, -0.5)*0.1 << QVector3D(-0.5, -0.5, -0.5)*0.1
             << QVector3D( 0.5, -0.5,  0.5)*0.1 << QVector3D( 0.5, -0.5, -0.5)*0.1 << QVector3D( 0.5,  0.5, -0.5)*0.1 // Right
             << QVector3D( 0.5,  0.5, -0.5)*0.1 << QVector3D( 0.5,  0.5,  0.5)*0.1 << QVector3D( 0.5, -0.5,  0.5)*0.1
             << QVector3D(-0.5,  0.5,  0.5)*0.1 << QVector3D( 0.5,  0.5,  0.5)*0.1 << QVector3D( 0.5,  0.5, -0.5)*0.1 // Top
             << QVector3D( 0.5,  0.5, -0.5)*0.1 << QVector3D(-0.5,  0.5, -0.5)*0.1 << QVector3D(-0.5,  0.5,  0.5)*0.1
             << QVector3D(-0.5, -0.5, -0.5)*0.1 << QVector3D( 0.5, -0.5, -0.5)*0.1 << QVector3D( 0.5, -0.5,  0.5)*0.1 // Bottom
             << QVector3D( 0.5, -0.5,  0.5)*0.1 << QVector3D(-0.5, -0.5,  0.5)*0.1 << QVector3D(-0.5, -0.5, -0.5)*0.1;

    shaderProgram.setAttributeArray("position", vertices.constData());
    shaderProgram.enableAttributeArray("position");

}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;

    QMatrix4x4 cameraTransformation;
    cameraTransformation.rotate(alpha, 0, 1, 0);
    cameraTransformation.rotate(beta, 1, 0, 0);

    QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
    QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);

    vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);





    for(int i=0; i < 10000; i++) {

        mMatrix.translate(QVector3D(sin(i*360/3.141592), cos(i*360/3.141592), 0));

        shaderProgram.bind();

        shaderProgram.setUniformValue("mv_matrix", vMatrix*mMatrix);
        shaderProgram.setUniformValue("proj_matrix", pMatrix);



        glDrawArrays(GL_TRIANGLES, 0, vertices.size());


        shaderProgram.disableAttributeArray("position");

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
