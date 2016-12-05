#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QVector>
#include <QGLShaderProgram>

class MyGLWidget : public QGLWidget
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
    QMatrix4x4 pMatrix;
    QGLShaderProgram shaderProgram;
    QVector<QVector3D> vertices;
};

#endif // MYGLWIDGET_H
