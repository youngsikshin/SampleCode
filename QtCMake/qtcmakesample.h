#ifndef QTCMAKESAMPLE_H
#define QTCMAKESAMPLE_H

#include <QMainWindow>

namespace Ui {
class QtCMakeSample;
}

class QtCMakeSample : public QMainWindow
{
    Q_OBJECT

public:
    explicit QtCMakeSample(QWidget *parent = 0);
    ~QtCMakeSample();

private:
    Ui::QtCMakeSample *ui;
};

#endif // QTCMAKESAMPLE_H
