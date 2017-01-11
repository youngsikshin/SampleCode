#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QVector>
#include <QGLShaderProgram>
#include <QMouseEvent>
#include <QPoint>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLContext>

class MyGLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
    int cur_time;

signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;


private:
    QGLShaderProgram shaderProgram;
};

#endif // MYGLWIDGET_H
