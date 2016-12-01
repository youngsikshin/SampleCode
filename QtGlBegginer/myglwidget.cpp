#include <QtWidgets>
#include <QtOpenGL>

#include "myglwidget.h"

const float GL_PI = 3.141592;

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
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

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}

void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

//    glColor3f(0.0f, 1.0f, 0.0f);
//    glShadeModel(GL_FLAT);

//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//    glShadeModel(GL_SMOOTH);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);

//    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    glTranslatef(0.0, 0.0, -10.0);
//    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
//    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
//    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);

//    draw_spiral();
//    draw_lineramble();
//    draw_linestrip();
//    draw_multiple_linewidth();
//    draw_linestipple();
//    draw_triangleculling();
//    draw_polygon_stippling();
//    draw_outline();
//    draw_scissor_test();
    draw_stencil_ex();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
//    glViewport((width - side) / 2, (height - side) / 2, side, side);
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

//    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
    GLfloat aspectRatio = (GLfloat) width/ (GLfloat) height;
    if (width <= height) glOrtho(-100.0, 100.0, -100.0/aspectRatio, 100.0/aspectRatio, 100.0, -100.0);
    else glOrtho(-100.0*aspectRatio, 100.0*aspectRatio, -100.0, 100.0, -100.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::draw_spiral()
{
    GLfloat x, y, z, angle;

    glPushMatrix();
    glRotatef(xRot, 1.0, 0.0, 0.0);
    glRotatef(yRot, 0.0, 1.0, 0.0);
    glRotatef(zRot, 0.0, 0.0, 1.0);

    glBegin(GL_POINTS);

    z = -50.0f;

    for (angle = 0.0f; angle <= (2.0f*GL_PI)*3.0f; angle += 0.1f) {
        x = 50.0f * sin(angle);
        y = 50.0f * cos(angle);

        glVertex3f (x, y, z);
        z += 0.5f;
    }

    glEnd();

    glPopMatrix();

    glFlush();

}

void MyGLWidget::draw_lineramble()
{
    GLfloat x, y, z, angle;

    glBegin(GL_LINES);

    z = 0.0f;

    for (angle = 0.0f; angle <= GL_PI; angle += (GL_PI/20.0f)) {
        x = 50.0f * sin(angle);
        y = 50.0f * cos(angle);
        glVertex3f (x, y, z);

        x = 50.0f*sin(angle+GL_PI);
        y = 50.0f*cos(angle+GL_PI);
        glVertex3f (x, y, z);
    }

    glEnd();
}

void MyGLWidget::draw_linestrip()
{
    GLfloat x, y, z, angle;

    glBegin(GL_LINE_STRIP);

    z = -50.0f;

    for (angle = 0.0f; angle <= 2.0f*GL_PI*3.0f; angle += 0.1f) {
        x = 50.0f * sin(angle);
        y = 50.0f * cos(angle);

        glVertex3f (x, y, z);
        z += 0.5f;
    }

    glEnd();
}

void MyGLWidget::draw_multiple_linewidth()
{
    GLfloat y;
    GLfloat fSizes[2];
    GLfloat fCurrSize;

    glGetFloatv(GL_LINE_WIDTH_RANGE, fSizes);
    fCurrSize = fSizes[0];

    for (y=-90.0f; y < 90.0f; y+=20.0f) {
        glLineWidth (fCurrSize);

        glBegin(GL_LINES);
            glVertex2f(-80.0f, y);
            glVertex2f(80.0f, y);
        glEnd();

        fCurrSize +=1.0f;
    }
}

void MyGLWidget::draw_linestipple()
{
    GLfloat y;
    GLint factor = 1;
    GLushort pattern = 0x5555;

    glEnable(GL_LINE_STIPPLE);

    for(y = -90.0f; y < 90.0f; y+=20.0f) {
        glLineStipple(factor, pattern);

        glBegin(GL_LINES);
            glVertex2f (-80.0f, y);
            glVertex2f (80.0f, y);
        glEnd();

        factor++;
    }
}

void MyGLWidget::draw_triangleculling()
{
    GLfloat x, y, angle;
    int iPivot = 1;

    bool bCull = false;
    bool bDepth = false;
    bool bOutline = true;

    if(bCull)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);

    if(bDepth)
        glEnable(GL_DEPTH_TEST);
    else
        glDisable(GL_DEPTH_TEST);

    if(bOutline)
        glPolygonMode (GL_BACK, GL_LINE);
    else
        glPolygonMode (GL_BACK, GL_FILL);

    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);

    glFrontFace(GL_CW);

    glBegin(GL_TRIANGLE_FAN);

    glVertex3f(0.0f, 0.0f, 75.0f);

    for (angle=0.0f; angle<(2.001f*GL_PI); angle+=(GL_PI/8.0f)) {
        x = 50.0f*sin(angle);
        y = 50.0f*cos(angle);

        if((iPivot%2)==0)
            glColor3f(0.0f, 1.0f, 0.0f);
        else
            glColor3f(1.0f, 0.0f, 0.0f);

        iPivot++;

        glVertex2f (x, y);
    }

    glEnd();

//    glFrontFace(GL_CCW);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0.0f, 0.0f);

    for(angle = 0.0f; angle <(2.001f*GL_PI); angle+=(GL_PI/8.0f)) {
        x = 50.0f*sin(angle);
        y = 50.0f*cos(angle);

        if((iPivot)%2 == 0)
            glColor3f(0.0f, 1.0f, 0.0f);
        else
            glColor3f(1.0f, 0.0f, 0.0f);

        iPivot++;

        glVertex2f(x,y);
    }

    glEnd();

    glPopMatrix();

//    glFlush();
}

void MyGLWidget::draw_polygon_stippling()
{
    GLubyte fire[] = {0x00, 0x00, 0x00, 0x00,
                      0x00, 0x00, 0x00, 0x00,
                      0x00, 0x00, 0x00, 0x00,
                      0x00, 0x00, 0x00, 0x00,
                      0x00, 0x00, 0x00, 0x00,
                      0x00, 0x00, 0x00, 0x00,
                      0x00, 0x00, 0x00, 0xc0,
                      0x00, 0x00, 0x01, 0xf0,
                      0x00, 0x00, 0x07, 0xf0,
                      0x0f, 0x00, 0x1f, 0xe0,
                      0x1f, 0x80, 0x1f, 0xc0,
                      0x0f, 0xc0, 0x3f, 0x80,
                      0x07, 0xe0, 0x7e, 0x00,
                      0x03, 0xf0, 0xff, 0x80,
                      0x03, 0xf5, 0xff, 0xe0,
                      0x07, 0xfd, 0xff, 0xe8};

    glEnable(GL_POLYGON_STIPPLE);
    glPolygonStipple(fire);

    glBegin(GL_POLYGON);
        glVertex2f(-20.0f, 50.0f);
        glVertex2f(20.0f, 50.0f);
        glVertex2f(50.0f, 20.0f);
        glVertex2f(50.0f, -20.0f);
        glVertex2f(20.0f, -50.0f);
        glVertex2f(-20.0f, -50.0f);
        glVertex2f(-50.0f, -20.0f);
        glVertex2f(-50.0f, 20.0f);
    glEnd();

}

void MyGLWidget::draw_outline()
{
    bool bEdgeFlag = true;

    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_TRIANGLES);


    glEdgeFlag(bEdgeFlag);
    glVertex2f(-20.0f, 0.0f);
    glEdgeFlag(true);
    glVertex2f(20.0f, 0.0f);
    glVertex2f(0.0f, 40.0f);

    glVertex2f(-20.0f, 0.0f);
    glVertex2f(-60.0f, -20.0f);
    glEdgeFlag(bEdgeFlag);
    glVertex2f(-20.0f, -40.0f);
    glEdgeFlag(true);

    glVertex2f(-20.0f, -40.0f);
    glVertex2f(0.0f, -80.0f);
    glEdgeFlag(bEdgeFlag);
    glVertex2f(20.0f, -40.0f);
    glEdgeFlag(true);

    glVertex2f(20.0f, -40.0f);
    glVertex2f(60.0f, -20.0f);
    glEdgeFlag(bEdgeFlag);
    glVertex2f(20.0f, 0.0f);
    glEdgeFlag(true);

    glEdgeFlag(bEdgeFlag);
    glVertex2f(-20.0f, 0.0f);
    glVertex2f(-20.0f, -40.0f);
    glVertex2f(20.0f, 0.0f);

    glVertex2f(-20.0f, -40.0f);
    glVertex2f(20.0f, -40.0f);
    glVertex2f(20.0f, 0.0f);
    glEdgeFlag(true);

    glEnd();
}

void MyGLWidget::draw_scissor_test()
{
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    glScissor(100, 100, 600, 400);
    glEnable(GL_SCISSOR_TEST);
    glClear(GL_COLOR_BUFFER_BIT);

    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glScissor (200, 200, 400, 200);
    glClear (GL_COLOR_BUFFER_BIT);

    glDisable(GL_SCISSOR_TEST);

//    glutSwapBuffers();
}

void MyGLWidget::draw_stencil_ex()
{
     GLdouble dRadius = 0.1;
     GLdouble dAngle;

     glClearColor(0.5f, 0.0f, 1.0f, 0.0f);

     glClearStencil(0.0f);
     glEnable(GL_STENCIL_TEST);

     glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

     glStencilFunc(GL_NEVER, 0x0, 0x0);
     glStencilOp(GL_INCR, GL_INCR, GL_INCR);

     glColor3f(1.0f, 1.0f, 1.0f);
     glBegin(GL_LINE_STRIP);
        for(dAngle = 0; dAngle < 400.0; dAngle += 0.1) {
            glVertex2d(dRadius * cos(dAngle), dRadius*sin(dAngle));
            dRadius *= 1.002;
        }
    glEnd();

    glStencilFunc(GL_NOTEQUAL, 0x1, 0x1);
//    glStencilOp(GL_INCR, GL_INCR, GL_INCR);
//    glStencilFunc(GL_NOTEQUAL, 0x2, 0x2);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    glColor3f(1.0f, 0.0f, 0.0f);
    GLfloat x=20, y=20;
    GLfloat rsize=100;
    glRectf(x, y, x+rsize, y-rsize);
}
