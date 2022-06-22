/********************************************************************************
** Form generated from reading UI file 'game_new1.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_NEW1_H
#define UI_GAME_NEW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Game_New
{
public:

    void setupUi(QDialog *Game_New)
    {
        if (Game_New->objectName().isEmpty())
            Game_New->setObjectName(QString::fromUtf8("Game_New"));
        Game_New->resize(600, 435);
        Game_New->setMinimumSize(QSize(300, 300));
        Game_New->setMaximumSize(QSize(600, 435));

        retranslateUi(Game_New);

        QMetaObject::connectSlotsByName(Game_New);
    } // setupUi

    void retranslateUi(QDialog *Game_New)
    {
        Game_New->setWindowTitle(QCoreApplication::translate("Game_New", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game_New: public Ui_Game_New {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_NEW1_H
