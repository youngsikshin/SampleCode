#include <QtWidgets>
#include <QtOpenGL>
#include <QVector3D>

#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    alpha = 25;
    beta = -25;
    distance = 2.5;
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
    lastMousePosition = event->pos();

    event->accept();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if(event->buttons() & Qt::LeftButton) {
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
    }

    lastMousePosition = event->pos();

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

    square_vertices << QVector4D(-1.0,-1.0, 0.0, 0.0)
                    << QVector4D( 1.0,-1.0, 0.0, 0.0)
                    << QVector4D( 1.0, 1.0, 0.0, 0.0)
                    << QVector4D(-1.0, 1.0, 0.0, 0.0);

    instance_colors << QVector4D( 1.0, 0.0, 0.0, 1.0)
                    << QVector4D( 0.0, 1.0, 0.0, 1.0)
                    << QVector4D( 0.0, 0.0, 1.0, 1.0)
                    << QVector4D( 1.0, 1.0, 0.0, 1.0);

    instance_positions << QVector4D(-2.0,-2.0, 0.0, 0.0)
                       << QVector4D( 2.0,-2.0, 0.0, 0.0)
                       << QVector4D( 2.0, 2.0, 0.0, 0.0)
                       << QVector4D(-2.0, 2.0, 0.0, 0.0);

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

//    for (int i = 0; i < 4; i++) {

        shaderProgram.bind();

        shaderProgram.setUniformValue("mvpMatrix", pMatrix*vMatrix*mMatrix);

        shaderProgram.setAttributeArray("position", square_vertices.constData());
        shaderProgram.setAttributeArray("instance_color", instance_colors.constData());
        shaderProgram.setAttributeArray("instance_position", instance_positions.constData());

        shaderProgram.enableAttributeArray("position");
        shaderProgram.enableAttributeArray("instance_color");
        shaderProgram.enableAttributeArray("instance_position");

        glDrawArrays(GL_TRIANGLE_FAN, 0, square_vertices.size());

        shaderProgram.disableAttributeArray("position");
        shaderProgram.disableAttributeArray("instance_color");
        shaderProgram.disableAttributeArray("instance_position");

        shaderProgram.release();

//    }

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
