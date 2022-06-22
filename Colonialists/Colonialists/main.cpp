#include "mainwindow.h"

#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.showFullScreen();
    QPixmap bkgnd(":/new/prefix1/res/fon.jpg");
    bkgnd = bkgnd.scaled(w.size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    w.setPalette(palette);
    return a.exec();
}
