#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    QPalette palette;
       palette.setBrush(this->backgroundRole(), QBrush(QColor(171, 246, 236)));
      this->setPalette(palette);
       this->setAutoFillBackground(true);
}

Settings::~Settings()
{
    if(player!=nullptr)
        delete[] player;
    delete ui;
}

void Settings::return_mas(){
   int i=0;
    if(ui->red->isChecked()){

         i++;
    }
    if(ui->blue->isChecked()){

        i++;
    }
    if(ui->white->isChecked()){

        i++;
    }
    if(ui->Yellow->isChecked()){

        i++;
    }
    if(i>1){
        player=new Player[i];i=0;
        if(ui->red->isChecked()){
            if(ui->botred->isChecked()){
                player[i].bot_init();
            }
          player[i].set_init('r',(ui->RedPlayer)->text()); i++;
        }
        if(ui->blue->isChecked()){
            if(ui->botblue->isChecked()){
                player[i].bot_init();
            }
          player[i].set_init('b', (ui->BluePlayer)->text());i++;

        }
        if(ui->white->isChecked()){
            if(ui->botwhite->isChecked()){
                player[i].bot_init();
            }
          player[i].set_init('w', (ui->WhitePlayer)->text()); i++;
        }
        if(ui->Yellow->isChecked()){
            if(ui->botYellow->isChecked()){
                player[i].bot_init();
            }
          player[i].set_init('y', (ui->YellowPlayer)->text()); i++;
        }
        this->num=i;
    }
    else {
      player=new Player[2];
      player[0].set_init('r', (ui->RedPlayer)->text());
       player[1].set_init('b', (ui->BluePlayer)->text());
       if(ui->botblue->isChecked()){
           player[1].bot_init();
       }
       if(ui->botred->isChecked()){
           player[0].bot_init();
       }
       num=2;
    }
    point=(ui->points->text()).toInt();
}
