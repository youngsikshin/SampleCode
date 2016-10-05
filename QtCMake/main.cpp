#include "qtcmakesample.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtCMakeSample w;
    w.show();

    return a.exec();
}
