#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QSlider>
#include <QElapsedTimer>

namespace Ui {
class window;
}

class window : public QWidget
{
    Q_OBJECT

public:
    explicit window(QWidget *parent = 0);
    ~window();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void onTimer();

private:
    Ui::window *ui;

    QTimer *_timer;
    int _delay_msec;

    QElapsedTimer _elapsed_timer;
};

#endif // WINDOW_H
