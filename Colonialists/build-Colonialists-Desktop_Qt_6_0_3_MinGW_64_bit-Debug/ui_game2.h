/********************************************************************************
** Form generated from reading UI file 'game2.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME2_H
#define UI_GAME2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(800, 600);
        menubar = new QMenuBar(Game);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        Game->setMenuBar(menubar);
        centralwidget = new QWidget(Game);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Game->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Game);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Game->setStatusBar(statusbar);

        retranslateUi(Game);

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QMainWindow *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME2_H
