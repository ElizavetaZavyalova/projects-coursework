#include "game_new.h"

#include <QMessageBox>
 #include "trader_and_help.h"
#include <QtGui>
#include <QIcon>
#include <QApplication>
void Game_New::on_clay_triggered()
{   if(ship[1].is_ship(player[now%num])){
        if(action[clear]||action[to21]||action[to31]||action[to41]){
            action[to41]=0;
            action[to31]=0;
            action[to21]=1;
            action[clear]=0;
            trading.trade_res[0]=clay;
             trading.trade_res[1]=clay;

    to21_show();
     for(int i=0; i<2; i++){
         trading.trade[i]->setPixmap(QPixmap(":/new/prefix1/res/clay.png"));
     }
        }
    }
}
void Game_New::to21_show(){
       trading.trade[3]->hide();
        trading.trade[2]->hide();
        trading.trading->show();
        trading.trade[4]->show();
        trading.trade[0]->show();
        trading.trade[1]->show();
        trading.trade[0]->setGeometry(hex[2].x+4.85*R, hex[2].y-1.75*R, 2.5*R, 2.5*R);
        trading.trade[1]->setGeometry(hex[2].x+4.85*R , hex[2].y+1.25*R, 2.5*R, 2.5*R);
        trading.tradeplayer[0]->show();
        trading.tradeplayer[1]->show();
}

void Game_New::on_millet_triggered()
{
    if(ship[6].is_ship(player[now%num])){
            if(action[clear]||action[to21]||action[to31]||action[to41]){
                action[to41]=0;
                action[to31]=0;
                action[to21]=1;
                action[clear]=0;
                trading.trade_res[0]=millet;
                trading.trade_res[1]=millet;
        to21_show();
         for(int i=0; i<5; i++){
             trading.trade[i]->setPixmap(QPixmap(":/new/prefix1/res/milet.png"));
         }
            }
        }
}

void Game_New::on_tree_triggered()
{
    if(ship[3].is_ship(player[now%num])){
            if(action[clear]||action[to21]||action[to31]||action[to41]){
                action[to41]=0;
                action[to31]=0;
                action[to21]=1;
                action[clear]=0;
                trading.trade_res[0]=tree;
                trading.trade_res[1]=tree;
        to21_show();
         for(int i=0; i<2; i++){
             trading.trade[i]->setPixmap(QPixmap(":/new/prefix1/res/tree.png"));
         }
            }
        }
}

void Game_New::on_stown_triggered()
{
    if(ship[8].is_ship(player[now%num])){
            if(action[clear]||action[to21]||action[to31]||action[to41]){
                action[to41]=0;
                action[to31]=0;
                action[to21]=1;
                action[clear]=0;
                trading.trade_res[0]=stown;
                trading.trade_res[1]=stown;
        to21_show();
         for(int i=0; i<2; i++){
             trading.trade[i]->setPixmap(QPixmap(":/new/prefix1/res/stone.png"));
         }
            }
        }
}

void Game_New::on_wool_triggered()
{
    if(ship[4].is_ship(player[now%num])){
            if(action[clear]||action[to21]||action[to31]||action[to41]){
                action[to41]=0;
                action[to31]=0;
                action[to21]=1;
                action[clear]=0;
                trading.trade_res[0]=wool;
                trading.trade_res[1]=wool;
        to21_show();
         for(int i=0; i<2; i++){
             trading.trade[i]->setPixmap(QPixmap(":/new/prefix1/res/shipbe.png"));
         }
            }
        }
}

void Game_New::on_to41_triggered()
{  if(action[clear]||action[to31]||action[to21]){
    for(int i=0; i<5; i++){
        trading.trade[i]->show();
    }
    trading.trading->show();
    action[to41]=1;
    action[to31]=0;
    action[to21]=0;

 trading.trade[4]->setGeometry(hex[2].x+8.15*R, hex[2].y, 2*R, 2*R);
 trading.trade[0]->setGeometry(hex[2].x+4.75*R, hex[2].y-1.75*R, 1.25*R, 1.25*R);
 trading.trade[1]->setGeometry(hex[2].x+6.25*R, hex[2].y-0.5*R, 1.25*R, 1.25*R);
  trading.trade[2]->setGeometry(hex[2].x+6.25*R, hex[2].y+1.25*R, 1.25*R, 1.25*R);
  trading.trade[3]->setGeometry(hex[2].x+4.75*R, hex[2].y+2.5*R, 1.25*R, 1.25*R);
  action[clear]=0;
  trading.tradeplayer[0]->show();
  trading.tradeplayer[1]->show();
    }
}

void Game_New::on_to31_triggered()
{
    if(ship[0].is_ship(player[now%num])||ship[2].is_ship(player[now%num])||\
        ship[5].is_ship(player[now%num])||ship[7].is_ship(player[now%num]))
    if(action[clear]||action[to41]||action[to21]) {
    for(int i=0; i<3; i++){
        trading.trade[i]->show();
    }
    trading.trade[4]->show();
    trading.trading->show();
    trading.trade[3]->hide();
    trading.trade[0]->setGeometry(hex[2].x+4.75*R, hex[2].y-1.75*R, 1.75*R, 1.75*R);
    trading.trade[1]->setGeometry(hex[2].x+5.85*R, hex[2].y+0.1*R, 1.75*R, 1.75*R);
     trading.trade[2]->setGeometry(hex[2].x+4.75*R, hex[2].y+2*R, 1.75*R, 1.75*R);
     action[to41]=0;
     action[to31]=1;
     action[to21]=0;
     action[clear]=0;
     trading.tradeplayer[0]->show();
     trading.tradeplayer[1]->show();
    }
}

void Game_New::on_exit_triggered()
{
     hide();
}

void Game_New::on_map_triggered()
{
    char d=cards.give(player[now%num]);
    switch(d)
    {
    case 'r':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/r.png"));
        msgBox.exec();}
                break;
    case 'i':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/i.png"));
        msgBox.exec();}
                break;
    case 'm':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/m.png"));
        msgBox.exec();}
            break;
    case 'k':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/k.png"));
        msgBox.exec();
        the_bigest_army();
    }
    break;
    case 'u':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/u.png"));
        msgBox.exec();;
    }
     break;
    case 'g':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/g.png"));
        msgBox.exec();;
    }
     break;
    case 't':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/t.png"));
        msgBox.exec();}
     break;
    case 'l':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/l.png"));
        msgBox.exec();;
    }
    break;
    case 'c':{
        QMessageBox msgBox;

        msgBox.setIconPixmap(QPixmap(":/new/prefix1/res/c.png"));
        msgBox.exec();}
     break;
    }
    infromation_tool();
}

void Game_New::on_dice_clicked(){
     now=(now+1)%num;
    int ran[2];

     srand(time(0));
     if(action[clear]){
         ran[0]=rand()%6+1;
         ran[1]=rand()%6+1;
     for(int i=0; i<2; i++){
       (ran[i]==1)?(dice[i]->setPixmap(QPixmap(":/new/prefix1/res/1.png"))):
       (ran[i]==2)?(dice[i]->setPixmap(QPixmap(":/new/prefix1/res/2.png"))):
       (ran[i]==3)?(dice[i]->setPixmap(QPixmap(":/new/prefix1/res/3.png"))):
       (ran[i]==4)?(dice[i]->setPixmap(QPixmap(":/new/prefix1/res/4.png"))):
      (ran[i]==5)?(dice[i]->setPixmap(QPixmap(":/new/prefix1/res/5.png"))):
      (dice[i]->setPixmap(QPixmap(":/new/prefix1/res/6.png")));
         infromation_tool();

     }
     if((ran[0]+ran[1])!=7){
         for(int i=0; i<19; i++){
            if(hex[i].number[0]==(ran[0]+ran[1]))
            if(hex[i].number[1]!=1){
             hex[i].distrubute();
             for(int i=0; i<10; ++i){
                 Sleep(100);
                 QApplication::processEvents();
             }
            if_it_is_bot();
            infromation_tool();
             }

         }
         return;
     }
     else{
         for(int i=0; i<num; i++){
             while((player[i].millet+player[i].clay+player[i].stone+player[i].wood+player[i].wool)>7){
                 player[i].not7();
             }
         }
             if(!player[now%num].bot){

                 action[clear]=0;
                 action[fief1]=1;
                 for(int i=0; i<10; ++i){
                     Sleep(100);
                     QApplication::processEvents();
                 }
             }
             else{
                 int i =rand()%19;
                 hex[i].fief_it(player[now%num]);
                   fief_move(i);

                   infromation_tool();
                   for(int i=0; i<10; ++i){
                       Sleep(100);
                       QApplication::processEvents();
                   }
                    //здесь
                   on_dice_clicked();
             }
         }

     }
}



void Game_New::on_monopoly_triggered()
{  if(action[clear]&&player[now%num].monopoly>0){
   player[now%num].monopoly--;
   player[now%num].cards--;
        action[clear]=0;
   action[monopoly]=1;
    infromation_tool();}
}

void Game_New::end_trade()
{
    if(!action[clear]&&(action[to21]||action[to31]||action[to41])){
        action[clear]=1;
        action[to21]=0;
        action[to31]=0;
        action[to41]=0;
        for(int i=0; i<5; i++){
            trading.trade[i]->hide();
        }
         trading.trading->hide();
         trading.tradeplayer[0]->hide();
         trading.tradeplayer[1]->hide();
    }

}

void Game_New::trade(){
    if(!action[clear]&&(action[to21]||action[to31]||action[to41])){
        if(action[to21]){
          trading.to_21(player[now%num]);
           infromation_tool();
          return;
        }
        if(action[to31]){
          trading.to_31(player[now%num]);
           infromation_tool();
          return;
        }
        if(action[to41]){
          trading.to_41(player[now%num]);
          infromation_tool();
          return;
        }
    }
}

void Game_New::on_new_roud_triggered()
{
    if(action[clear]&&player[now%num].new_road>0){
       player[now%num].new_road--;
        player[now%num].cards--;
        action[clear]=0;
       action[new_roud]=1;
       player[now%num].road_new=2;
        infromation_tool();
    }
}

void Game_New::on_ivent_triggered()
{
    if(action[clear]&&player[now%num].ivent>0){
       player[now%num].ivent--;
        player[now%num].cards--;
        action[clear]=0;
       action[ivent]=1;
       cards.r=2;
        infromation_tool();
    }
}

void Game_New::on_knit_triggered()
{
    if(action[clear]&&player[now%num].knight>0){
        player[now%num].knight--;
         player[now%num].cards--;
        player[now%num].army++;
       action[clear]=0;
       action[fief1]=1;
       infromation_tool();
    }
}

void Game_New::on_millet_2_triggered()
{
    if(!action[clear]){
        if(action[ivent]){
            ivent_do(millet);

        }
        else if(action[monopoly]){

            monopoly_do(millet);
        }
    }
}

void Game_New::on_wool_2_triggered()
{
    if(!action[clear]){
        if(action[ivent]){
            ivent_do(wool);

        }
        else if(action[monopoly]){

             monopoly_do(wool);
        }
    }
}

void Game_New::on_tree_2_triggered()
{
    if(!action[clear]){
        if(action[ivent]){
            ivent_do(tree);

        }
        else if(action[monopoly]){

            monopoly_do(tree);
        }
    }

}

void Game_New::on_clay_2_triggered()
{

    if(!action[clear]){
        if(action[ivent]){
            ivent_do(clay);

        }
        else if(action[monopoly]){

            monopoly_do(clay);
        }
    }

}

void Game_New::on_stown_2_triggered()
{
    if(!action[clear]){
        if(action[ivent]){
            ivent_do(stown);

        }
        else if(action[monopoly]){

            monopoly_do(stown);
        }
    }
}



void Game_New::on_ruls_triggered()
{  Dialog dil;
    dil.setModal(1);
    dil.exec();
}
