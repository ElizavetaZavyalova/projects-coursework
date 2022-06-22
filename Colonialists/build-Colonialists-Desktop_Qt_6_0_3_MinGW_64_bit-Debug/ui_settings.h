/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *points_2;
    QCheckBox *Yellow;
    QLineEdit *RedPlayer;
    QCheckBox *white;
    QLineEdit *WhitePlayer;
    QLabel *label;
    QLineEdit *YellowPlayer;
    QLineEdit *BluePlayer;
    QCheckBox *blue;
    QLabel *label_2;
    QCheckBox *red;
    QCheckBox *botred;
    QCheckBox *botblue;
    QCheckBox *botwhite;
    QCheckBox *botYellow;
    QLabel *label_4;
    QWidget *gridLayoutWidget_2;
    QGridLayout *players;
    QLabel *label_3;
    QSpinBox *points;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(608, 251);
        gridLayoutWidget = new QWidget(Settings);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 581, 163));
        points_2 = new QGridLayout(gridLayoutWidget);
        points_2->setObjectName(QString::fromUtf8("points_2"));
        points_2->setContentsMargins(0, 0, 0, 0);
        Yellow = new QCheckBox(gridLayoutWidget);
        Yellow->setObjectName(QString::fromUtf8("Yellow"));

        points_2->addWidget(Yellow, 5, 2, 1, 1);

        RedPlayer = new QLineEdit(gridLayoutWidget);
        RedPlayer->setObjectName(QString::fromUtf8("RedPlayer"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Gothic"));
        font.setBold(false);
        RedPlayer->setFont(font);

        points_2->addWidget(RedPlayer, 2, 5, 1, 1);

        white = new QCheckBox(gridLayoutWidget);
        white->setObjectName(QString::fromUtf8("white"));

        points_2->addWidget(white, 4, 2, 1, 1);

        WhitePlayer = new QLineEdit(gridLayoutWidget);
        WhitePlayer->setObjectName(QString::fromUtf8("WhitePlayer"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Gothic"));
        WhitePlayer->setFont(font1);

        points_2->addWidget(WhitePlayer, 4, 5, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yu Gothic UI"));
        font2.setPointSize(10);
        font2.setBold(true);
        label->setFont(font2);

        points_2->addWidget(label, 0, 5, 1, 1);

        YellowPlayer = new QLineEdit(gridLayoutWidget);
        YellowPlayer->setObjectName(QString::fromUtf8("YellowPlayer"));
        YellowPlayer->setFont(font1);

        points_2->addWidget(YellowPlayer, 5, 5, 1, 1);

        BluePlayer = new QLineEdit(gridLayoutWidget);
        BluePlayer->setObjectName(QString::fromUtf8("BluePlayer"));
        BluePlayer->setFont(font);

        points_2->addWidget(BluePlayer, 3, 5, 1, 1);

        blue = new QCheckBox(gridLayoutWidget);
        blue->setObjectName(QString::fromUtf8("blue"));

        points_2->addWidget(blue, 3, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Yu Gothic UI"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setKerning(false);
        label_2->setFont(font3);

        points_2->addWidget(label_2, 0, 2, 1, 1);

        red = new QCheckBox(gridLayoutWidget);
        red->setObjectName(QString::fromUtf8("red"));
        QFont font4;
        font4.setBold(false);
        red->setFont(font4);
        red->setTabletTracking(false);
        red->setAcceptDrops(false);
        red->setChecked(false);
        red->setAutoRepeat(false);
        red->setAutoExclusive(false);
        red->setTristate(false);

        points_2->addWidget(red, 2, 2, 1, 1);

        botred = new QCheckBox(gridLayoutWidget);
        botred->setObjectName(QString::fromUtf8("botred"));

        points_2->addWidget(botred, 2, 6, 1, 1);

        botblue = new QCheckBox(gridLayoutWidget);
        botblue->setObjectName(QString::fromUtf8("botblue"));

        points_2->addWidget(botblue, 3, 6, 1, 1);

        botwhite = new QCheckBox(gridLayoutWidget);
        botwhite->setObjectName(QString::fromUtf8("botwhite"));

        points_2->addWidget(botwhite, 4, 6, 1, 1);

        botYellow = new QCheckBox(gridLayoutWidget);
        botYellow->setObjectName(QString::fromUtf8("botYellow"));

        points_2->addWidget(botYellow, 5, 6, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        points_2->addWidget(label_4, 0, 6, 1, 1);

        gridLayoutWidget_2 = new QWidget(Settings);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 190, 581, 31));
        players = new QGridLayout(gridLayoutWidget_2);
        players->setObjectName(QString::fromUtf8("players"));
        players->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        players->addWidget(label_3, 0, 0, 1, 1);

        points = new QSpinBox(gridLayoutWidget_2);
        points->setObjectName(QString::fromUtf8("points"));
        points->setMinimum(3);
        points->setMaximum(13);
        points->setValue(13);

        players->addWidget(points, 0, 1, 1, 1);


        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        Yellow->setText(QCoreApplication::translate("Settings", "\320\266\320\265\320\273\321\202\321\213\320\271", nullptr));
        RedPlayer->setText(QCoreApplication::translate("Settings", "Player1", nullptr));
        white->setText(QCoreApplication::translate("Settings", "\320\261\320\265\320\273\321\213\320\271", nullptr));
        WhitePlayer->setText(QCoreApplication::translate("Settings", "Player3", nullptr));
        label->setText(QCoreApplication::translate("Settings", "\320\230\320\274\321\217", nullptr));
        YellowPlayer->setText(QCoreApplication::translate("Settings", "Player4", nullptr));
        BluePlayer->setText(QCoreApplication::translate("Settings", "Player2", nullptr));
        blue->setText(QCoreApplication::translate("Settings", "\321\201\320\270\320\275\320\270\320\271", nullptr));
        label_2->setText(QCoreApplication::translate("Settings", "\320\246\320\262\320\265\321\202", nullptr));
        red->setText(QCoreApplication::translate("Settings", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        botred->setText(QString());
        botblue->setText(QString());
        botwhite->setText(QString());
        botYellow->setText(QString());
        label_4->setText(QCoreApplication::translate("Settings", "\320\221\320\276\321\202  ", nullptr));
        label_3->setText(QCoreApplication::translate("Settings", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\272\320\276\320\273-\320\262\320\276 \320\277\320\276\320\261\320\265\320\264\320\275\321\213\321\205 \320\276\321\207\320\272\320\276\320\262                                         ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
