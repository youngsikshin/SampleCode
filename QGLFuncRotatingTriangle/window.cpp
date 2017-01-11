#include <QtWidgets>
#include "window.h"
#include "ui_window.h"

#include "myglwidget.h"

window::window(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);

    _timer = new QTimer(this);
    connect(_timer, SIGNAL(timeout()), this, SLOT(onTimer()));

    _delay_msec = 33;
    _timer->start(_delay_msec);

    _elapsed_timer.start();
}

window::~window()
{
    delete ui;
}

void window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();
    else
        QWidget::keyPressEvent(e);
}

void window::onTimer()
{
    ui->myGLWidget->cur_time = _elapsed_timer.elapsed();

    ui->myGLWidget->update();
}
