/********************************************************************************
** Form generated from reading UI file 'gamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEWINDOW_H
#define UI_GAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameWindow
{
public:
    QWidget *centralwidget;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *GameWindow)
    {
        if (GameWindow->objectName().isEmpty())
            GameWindow->setObjectName(QString::fromUtf8("GameWindow"));
        GameWindow->resize(985, 600);
        centralwidget = new QWidget(GameWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        GameWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(GameWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        GameWindow->addToolBar(Qt::RightToolBarArea, toolBar);
        toolBar_2 = new QToolBar(GameWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        GameWindow->addToolBar(Qt::BottomToolBarArea, toolBar_2);

        toolBar->addSeparator();
        toolBar_2->addSeparator();

        retranslateUi(GameWindow);

        QMetaObject::connectSlotsByName(GameWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GameWindow)
    {
        GameWindow->setWindowTitle(QCoreApplication::translate("GameWindow", "MainWindow", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("GameWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("GameWindow", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameWindow: public Ui_GameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEWINDOW_H
