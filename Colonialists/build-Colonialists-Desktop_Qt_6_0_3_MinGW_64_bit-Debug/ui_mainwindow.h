/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout;
    QPushButton *new_game;
    QPushButton *author;
    QPushButton *rules;
    QPushButton *exit;
    QPushButton *settings;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(500, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(500, 500));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        new_game = new QPushButton(centralwidget);
        new_game->setObjectName(QString::fromUtf8("new_game"));
        new_game->setMinimumSize(QSize(400, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Gothic"));
        font.setPointSize(12);
        font.setBold(true);
        new_game->setFont(font);

        gridLayout->addWidget(new_game, 0, 0, 1, 1);

        author = new QPushButton(centralwidget);
        author->setObjectName(QString::fromUtf8("author"));
        author->setMinimumSize(QSize(60, 50));
        author->setFont(font);

        gridLayout->addWidget(author, 3, 0, 1, 1);

        rules = new QPushButton(centralwidget);
        rules->setObjectName(QString::fromUtf8("rules"));
        rules->setMinimumSize(QSize(60, 50));
        rules->setFont(font);

        gridLayout->addWidget(rules, 1, 0, 1, 1);

        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setMinimumSize(QSize(60, 50));
        exit->setMaximumSize(QSize(500, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Gothic"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setItalic(false);
        exit->setFont(font1);

        gridLayout->addWidget(exit, 4, 0, 1, 1);

        settings = new QPushButton(centralwidget);
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setMinimumSize(QSize(60, 50));
        settings->setFont(font1);

        gridLayout->addWidget(settings, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        new_game->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\230\320\263\321\200\320\260", nullptr));
        author->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        rules->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\260\320\262\320\270\320\273\320\260", nullptr));
        exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        settings->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
