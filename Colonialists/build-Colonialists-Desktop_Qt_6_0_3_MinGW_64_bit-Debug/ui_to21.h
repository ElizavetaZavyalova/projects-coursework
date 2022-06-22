/********************************************************************************
** Form generated from reading UI file 'to21.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TO21_H
#define UI_TO21_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_to21
{
public:
    QComboBox *comboBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *to21)
    {
        if (to21->objectName().isEmpty())
            to21->setObjectName(QString::fromUtf8("to21"));
        to21->resize(500, 400);
        to21->setMinimumSize(QSize(500, 400));
        to21->setMaximumSize(QSize(500, 400));
        comboBox = new QComboBox(to21);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/res/stone.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon, QString());
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/res/milet.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon1, QString());
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/res/shipbe.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon2, QString());
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/res/clay.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon3, QString());
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/res/tree.png"), QSize(), QIcon::Normal, QIcon::Off);
        comboBox->addItem(icon4, QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(220, 50, 251, 181));
        comboBox->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("Yu Gothic UI"));
        font.setPointSize(10);
        comboBox->setFont(font);
        comboBox->setIconSize(QSize(150, 150));
        label = new QLabel(to21);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 161, 141));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/res/milet.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(to21);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 200, 161, 151));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/res/milet.png")));
        label_2->setScaledContents(true);
        pushButton = new QPushButton(to21);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 260, 161, 61));

        retranslateUi(to21);

        QMetaObject::connectSlotsByName(to21);
    } // setupUi

    void retranslateUi(QDialog *to21)
    {
        to21->setWindowTitle(QCoreApplication::translate("to21", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("to21", "\320\232\320\260\320\274\320\265\320\275\321\214", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("to21", "\320\237\321\210\320\265\320\275\320\276", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("to21", "\320\250\320\265\321\200\321\201\321\202\321\214", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("to21", "\320\223\320\273\320\270\320\275\320\260", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("to21", "\320\224\320\265\321\200\320\265\320\262\320\276", nullptr));

        label->setText(QString());
        label_2->setText(QString());
        pushButton->setText(QCoreApplication::translate("to21", "\320\241\320\276\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \320\276\320\261\320\274\320\265\320\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class to21: public Ui_to21 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TO21_H
