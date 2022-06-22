#include "game_new.h"
#include "ui_game_new.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QWidget>
#include <QPushButton>



void Game_New::infromation_tool(){
    ui->clay_2->setIconText(QString::number(player[now%num].clay));
     ui->millet_2->setIconText(QString::number(player[now%num].millet));
      ui->tree_2->setIconText(QString::number(player[now%num].wood));
       ui->wool_2->setIconText(QString::number(player[now%num].wool));
        ui->stown_2->setIconText(QString::number(player[now%num].stone));
         ui->knit->setIconText(QString::number(player[now%num].knight));
          ui->sity_2->setIconText(QString::number(player[now%num].sity));
           ui->wilage_2->setIconText(QString::number(player[now%num].vilage));
           ui->points->setIconText(QString::number(player[now%num].points));
            ui->roud_2->setIconText(QString::number(player[now%num].road));
            ui->map->setIconText(QString::number(player[now%num].cards));
            ui->monopoly->setIconText(QString::number(player[now%num].monopoly));
            ui->army->setIconText(QString::number(player[now%num].army));
            ui->ivent->setIconText(QString::number(player[now%num].ivent));
            ui->new_roud->setIconText(QString::number(player[now%num].new_road));
            for(int i=0; i<num; i++){
                switch(player[i].color){
                case 'b':{
                     ui->Blue->setToolTip("Синий игрок\n"
                                           "Победные очки=" +QString::number(player[i].points)+"\n"
                                          "Глина=" +QString::number(player[i].clay)+"\n"
                                          "Шерсть=" +QString::number(player[i].wool)+"\n"
                                          "Камень=" +QString::number(player[i].stone)+"\n"
                                          "Пшено=" +QString::number(player[i].millet)+"\n"
                                          "Дерево=" +QString::number(player[i].wood)+"\n"
                                         "Армия=" +QString::number(player[i].army)+"\n"
                                         "Тракт=" +QString::number(player[i].road)+"\n");
                     break;
                }
                case 'r':{
                    ui->Red->setToolTip("Красный игрок\n"
                                          "Победные очки=" +QString::number(player[i].points)+"\n"
                                         "Глина=" +QString::number(player[i].clay)+"\n"
                                         "Шерсть=" +QString::number(player[i].wool)+"\n"
                                         "Камень=" +QString::number(player[i].stone)+"\n"
                                         "Пшено=" +QString::number(player[i].millet)+"\n"
                                         "Дерево=" +QString::number(player[i].wood)+"\n"
                                         "Армия=" +QString::number(player[i].army)+"\n"
                                         "Тракт=" +QString::number(player[i].road)+"\n");

                     break;
                }
                case 'w':{
                    ui->White->setToolTip("Белый игрок\n"
                                          "Победные очки=" +QString::number(player[i].points)+"\n"
                                         "Глина=" +QString::number(player[i].clay)+"\n"
                                         "Шерсть=" +QString::number(player[i].wool)+"\n"
                                         "Камень=" +QString::number(player[i].stone)+"\n"
                                         "Пшено=" +QString::number(player[i].millet)+"\n"
                                         "Дерево=" +QString::number(player[i].wood)+"\n"
                                         "Армия=" +QString::number(player[i].army)+"\n"
                                         "Тракт=" +QString::number(player[i].road)+"\n");
                      break;
                }
                case 'y':{
                    ui->Yellow->setToolTip("Желтый игрок\n"
                                          "Победные очки=" +QString::number(player[i].points)+"\n"
                                         "Глина=" +QString::number(player[i].clay)+"\n"
                                         "Шерсть=" +QString::number(player[i].wool)+"\n"
                                         "Камень=" +QString::number(player[i].stone)+"\n"
                                         "Пшено=" +QString::number(player[i].millet)+"\n"
                                         "Дерево=" +QString::number(player[i].wood)+"\n"
                                         "Армия=" +QString::number(player[i].army)+"\n"
                                         "Тракт=" +QString::number(player[i].road)+"\n");
                     break;
                }
                }
            }



            switch(player[now%num].color){
            case 'b':{
                ui->sity_2->setIcon(QIcon(":/new/prefix1/res/house2blue.png"));
                ui->wilage_2->setIcon(QIcon(":/new/prefix1/res/house1blue.png"));
                 ui->roud_2->setIcon(QIcon(":/new/prefix1/res/roudblue.jpg"));


                 break;
            }
            case 'r':{
                ui->sity_2->setIcon(QIcon(":/new/prefix1/res/house2Red.png"));
                ui->wilage_2->setIcon(QIcon(":/new/prefix1/res/house1Red.png"));
                 ui->roud_2->setIcon(QIcon(":/new/prefix1/res/roudred.jpg"));
                 break;
            }
            case 'w':{
                ui->sity_2->setIcon(QIcon(":/new/prefix1/res/house2white.png"));
                ui->wilage_2->setIcon(QIcon(":/new/prefix1/res/house1White.png"));
                 ui->roud_2->setIcon(QIcon(":/new/prefix1/res/roudwhite.jpg"));
                 break;
            }
            case 'y':{
                ui->sity_2->setIcon(QIcon(":/new/prefix1/res/house2Yellow.png"));
                ui->wilage_2->setIcon(QIcon(":/new/prefix1/res/house1Yellow.png"));
                 ui->roud_2->setIcon(QIcon(":/new/prefix1/res/roudyellow.jpg"));
                 break;
            }
            }
            if(player[now%num].points>=point){
                action[clear]=0;
                QMessageBox msgBox;
                 msgBox.setText("Победил игрок "+player[now%num].name);

                msgBox.exec();

}
}

void Game_New::the_bigest_army(){
    if(player[now%num].army>2&&!player[now%num].the_bigest_army){
        bool big=0;
        for(int i=0; i<num; i++){
            (player[i].the_bigest_army)?(big=1):(big);
            if((player[now%num].army>player[i].army)&&player[i].the_bigest_army){
                if(!player[now%num].bot){
                QMessageBox msgBox;
                 msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/bigest_army.png"));
                 msgBox.setModal(true);
                 msgBox.exec();}
                player[i].points-=2;
                player[i].the_bigest_army=0;
                player[now%num].points+=2;
                player[now%num].the_bigest_army=1;
            }
        }
        if(!player[now%num].the_bigest_army&&!big){
            if(!player[now%num].bot){
            QMessageBox msgBox;
             msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/bigest_army.png"));
             msgBox.setModal(true);
             msgBox.exec();}
            player[now%num].points+=2;
            player[now%num].the_bigest_army=1;
        }
    }
}

void Game_New::the_bigest_road(){
    if(player[now%num].road>4&&!player[now%num].the_bigest_roud){
        bool big=0;
        for(int i=0; i<num; i++){
             (player[i].the_bigest_roud)?(big=1):(big);
            if((player[now%num].road>player[i].army)&&player[i].the_bigest_roud){
                if(!player[now%num].bot){
                QMessageBox msgBox;
                 msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/long_roud.png"));
                 msgBox.setModal(true);
                 msgBox.exec();}
                player[i].points-=2;
                player[i].the_bigest_roud=0;
                player[now%num].points+=2;
                player[now%num].the_bigest_roud=1;
            }
        }
        if(!player[now%num].the_bigest_roud&&!big){
            if(!player[now%num].bot){
            QMessageBox msgBox;
             msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/long_roud.png"));
             msgBox.setModal(true);
             msgBox.exec();}
            player[now%num].points+=2;
            player[now%num].the_bigest_roud=1;
        }
    }
}

void Game_New::monopoly_do(int res){
            for(int j=0; j<num; j++){
                if(res==clay){
                int t= player[j].clay;
                 player[j].clay=0;
                player[now%num].clay+=t;
               }
                else if(res==tree){
                    int t= player[j].wood;
                    player[j].wood=0;
                    player[now%num].wood+=t;
                }
                else if(res==stown){
                    int t=player[j].stone;
                    player[j].stone=0;
                    player[now%num].stone+=t;
                }

               else  if(res==millet){
                      int t=player[j].millet;
                      player[j].millet=0;
            player[now%num].millet+=t;  }
                else if(res==wool){
                     int t=player[j].wool;
                     player[j].wool=0;
              player[now%num].wool+=t;  }
            }
            action[clear]=1;
            action[monopoly]=0;
            infromation_tool();
        }

void Game_New::ivent_do(int res){
    (res==clay)?(player[now%num].clay++):
    (res==millet)?(player[now%num].millet++):
       (res==stown)?(player[now%num].stone++):
      (res==tree)?(player[now%num].wood++):
         (res==wool)?(player[now%num].wool++):(player[now%num].wool);
    cards.r--;
    if(cards.r==0){
        action[clear]=1;
        action[ivent]=0;

    }
     infromation_tool();

}

void Game_New::new_roud_do(double x, double y){
     for(int i=0; i<72; i++){
         if(road[i].is_road(x,y,R)){
             if(road[i].private_road(player[now%num])==0)
             player[now%num].road_new--;
         }
     }

    if(player[now%num].road_new==0){
          action[clear]=1;
          action[new_roud]=0;
      }
    the_bigest_road();
    infromation_tool();
    repaint();

}

