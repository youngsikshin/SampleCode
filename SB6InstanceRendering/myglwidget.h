#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include <QVector>
#include <QGLShaderProgram>
#include <QMouseEvent>
#include <QPoint>
#include <QGLBuffer>

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

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QMatrix4x4 pMatrix;
    QGLShaderProgram shaderProgram;

    QVector<QVector4D> square_vertices;
    QVector<QVector4D> instance_colors;
    QVector<QVector4D> instance_positions;

    QGLBuffer square_buf;

    double alpha;
    double beta;
    double distance;
    QPoint lastMousePosition;
};

#endif // MYGLWIDGET_H
