#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
//#include "game_new.h"

#include <QLabel>


#include <QPixmap>
//#include <QPalette>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->exit->setStyleSheet("  QPushButton { font-size: 12.5px; background-color: #abf6ec; color:#000000}");
     ui->author->setStyleSheet("  QPushButton { font-size: 12.5px; background-color: #abf6ec; color:#000000}");
     ui->settings->setStyleSheet("  QPushButton { font-size: 12.5px; background-color: #abf6ec; color:#000000}");
      ui->rules->setStyleSheet("  QPushButton { font-size: 12.5px; background-color: #abf6ec; color:#000000}");
       ui->new_game->setStyleSheet("  QPushButton { font-size: 12.5px; background-color: #abf6ec; color:#000000}");

}

MainWindow::~MainWindow()
{
    delete ui;
    if(game!=nullptr)
        delete game;
}






void MainWindow::on_settings_clicked()
{
  setings.setModal(true);
   setings.exec();
}

void MainWindow::on_author_clicked()
{
    QMessageBox msgBox;

    msgBox.setText("Завьялова Елизавета Александровна М8о-110Б-20");
    msgBox.exec();

}

void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}


void MainWindow::on_new_game_clicked()
{   setings.return_mas();
   //hide();
   if(game!=nullptr)
       delete game;
    game=new Game_New;

    game->player=setings.player;
     game->num=setings.num;
     game->point=setings.point;
    game->showFullScreen();

    QPalette palette;
       palette.setBrush(game->backgroundRole(), QBrush(QColor(25, 116, 210)));
      game->setPalette(palette);
       game->setAutoFillBackground(true);
    game->init_all();

}

void MainWindow::on_rules_clicked()
{
   dil.setModal(1);
   dil.exec();
}

