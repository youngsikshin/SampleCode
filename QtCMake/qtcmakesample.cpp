#include "qtcmakesample.h"
#include "ui_qtcmakesample.h"

QtCMakeSample::QtCMakeSample(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QtCMakeSample)
{
    ui->setupUi(this);
}

QtCMakeSample::~QtCMakeSample()
{
    delete ui;
}
