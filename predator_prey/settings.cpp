#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_clicked()
{

    eat_delta=(ui->eat->text()).toInt();
    hungry_delta=(ui->hungry->text()).toInt();
    thirst_delta=(ui->thirst->text()).toInt();
    drink_delta=(ui->drink->text()).toInt();
    max=(ui->maxy->text()).toInt();
    this->close();
}
