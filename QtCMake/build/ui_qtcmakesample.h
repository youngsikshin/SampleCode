/********************************************************************************
** Form generated from reading UI file 'qtcmakesample.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCMAKESAMPLE_H
#define UI_QTCMAKESAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtCMakeSample
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtCMakeSample)
    {
        if (QtCMakeSample->objectName().isEmpty())
            QtCMakeSample->setObjectName(QStringLiteral("QtCMakeSample"));
        QtCMakeSample->resize(400, 300);
        menuBar = new QMenuBar(QtCMakeSample);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtCMakeSample->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtCMakeSample);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtCMakeSample->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtCMakeSample);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtCMakeSample->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtCMakeSample);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtCMakeSample->setStatusBar(statusBar);

        retranslateUi(QtCMakeSample);

        QMetaObject::connectSlotsByName(QtCMakeSample);
    } // setupUi

    void retranslateUi(QMainWindow *QtCMakeSample)
    {
        QtCMakeSample->setWindowTitle(QApplication::translate("QtCMakeSample", "QtCMakeSample", 0));
    } // retranslateUi

};

namespace Ui {
    class QtCMakeSample: public Ui_QtCMakeSample {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCMAKESAMPLE_H
