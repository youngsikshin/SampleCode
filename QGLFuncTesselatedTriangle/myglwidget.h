#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

//#include <QGLWidget>
#include <QOpenGLWidget>
#include <QVector>
#include <QOpenGLShaderProgram>
#include <QMouseEvent>
#include <QPoint>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLContext>

#include <string>
#include <iostream>
#include <fstream>

class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();

signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;


private:
    QOpenGLShaderProgram shaderProgram;
    void draw_lineramble();
};

#endif // MYGLWIDGET_H
