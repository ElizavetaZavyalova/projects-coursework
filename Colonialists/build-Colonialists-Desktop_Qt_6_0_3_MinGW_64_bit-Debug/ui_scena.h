/********************************************************************************
** Form generated from reading UI file 'scena.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENA_H
#define UI_SCENA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scena
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *Scena)
    {
        if (Scena->objectName().isEmpty())
            Scena->setObjectName(QString::fromUtf8("Scena"));
        Scena->resize(926, 511);
        centralwidget = new QWidget(Scena);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        Scena->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Scena);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 926, 26));
        Scena->setMenuBar(menubar);
        toolBar = new QToolBar(Scena);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Scena->addToolBar(Qt::RightToolBarArea, toolBar);
        toolBar_2 = new QToolBar(Scena);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        Scena->addToolBar(Qt::BottomToolBarArea, toolBar_2);

        retranslateUi(Scena);

        QMetaObject::connectSlotsByName(Scena);
    } // setupUi

    void retranslateUi(QMainWindow *Scena)
    {
        Scena->setWindowTitle(QCoreApplication::translate("Scena", "MainWindow", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Scena", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("Scena", "toolBar_2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Scena: public Ui_Scena {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENA_H
