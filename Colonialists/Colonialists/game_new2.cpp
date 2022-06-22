#include "game_new2.h"
#include "ui_game_new2.h"

Game_New2::Game_New2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Game_New2)
{
    ui->setupUi(this);
}

Game_New2::~Game_New2()
{
    delete ui;
}
