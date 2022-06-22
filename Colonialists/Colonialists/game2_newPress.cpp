#include "game_new.h"
#include "ui_game_new.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>



void Game_New::mousePressEvent(QMouseEvent* me)
{

    double x =me->position().x();
    double y=me->position().y();
    if(!action[clear]){
    if(action[start]){
      Start_init(x, y);
      return;
     }
    else if (action[to21]){
        tradeto21(x, y);
        return;
    }
    else if (action[to31]){
        tradeto31(x, y);
        return;
    }
    else if (action[to41]){
        tradeto41(x, y);
        return;
    }
    else if(action[new_roud]){
             new_roud_do(x,y);
             return;
    }
    else if(action[fief1]){
      fiefmove(x ,y);
      return;
    }
    }
    else{
       if(x>(hex[18].x+4*R-13*R)&&x<(hex[18].x+6.75*R-13*R)&&(hex[18].y+R)<y&&y<(hex[18].y+6.25*R))
          { on_dice_clicked();
        infromation_tool();

    return;
       }

        for(int i=0; i<54; i++){
            if(town[i].is_number(x, y, R))
               {
                town_init(i);
                return;
               }
        }
        for(int i=0; i<72; i++){
            if(road[i].is_road(x,y,R)){
                road_init(i);
                return;
            }
        }
    }
}


void Game_New::Start_init(double x, double y){
    if(player[now%num].vilage==0){
    for(int i=0; i<54 ;i++){
        if(town[i].is_number(x, y,R)&&town[i].player==nullptr)
                if((town[i].right!=nullptr)?(town[i].right->player==&player[now%num]||(town[i].right->player==nullptr)):(1))
                if((town[i].central!=nullptr)?(town[i].central->player==&player[now%num]||town[i].central->player==nullptr):(1))
                if((town[i].left!=nullptr)?(town[i].left->player==&player[now%num]||town[i].left->player==nullptr):(1)){
            town[i].player=&player[now%num];
            town[i].town=1;
                  player[now%num].clay--;
                  player[now%num].wool--;
                  player[now%num].millet--;
                  player[now%num].wood--;
                  player[now%num].vilage++;
            player[now%num].points++;
            //now++;
           town_label(i);
           infromation_tool();
           if_it_is_bot();
            return;
        }
    }
    }
    if(player[now%num].vilage==1&&now<num){
    for(int i=0; i<72; i++){
      if((road[i].is_road(x,y, R))&&(road[i].private_road(player[now%num])==1)){
          repaint();
          now++;
          infromation_tool();
          if_it_is_bot();
          //(now==num*2)?(set=1):(set=0);
          return;
      }
    }
    }
    if(now>=num&&now<2*num&&player[now%num].vilage==1){
    for(int i=0; i<54 ;i++){
        if(town[i].is_number(x, y, R)&&town[i].player==nullptr)
            if((town[i].right!=nullptr)?(town[i].right->player==&player[now%num]||(town[i].right->player==nullptr)):(1))
            if((town[i].central!=nullptr)?(town[i].central->player==&player[now%num]||town[i].central->player==nullptr):(1))
            if((town[i].left!=nullptr)?(town[i].left->player==&player[now%num]||town[i].left->player==nullptr):(1)){
            town[i].player=&player[now%num];
            town[i].town=1;
            player[now%num].clay--;
            player[now%num].wool--;
            player[now%num].millet--;
            player[now%num].wood--;
            player[now%num].vilage++;
            player[now%num].points++;
            //now++;
            town_label(i);
            infromation_tool();
            if_it_is_bot();
            return;
        }
    }
    }
    if(player[now%num].vilage==2){
    for(int i=0; i<72; i++){
      if(road[i].is_road(x,y, R*2)&&(road[i].private_road(player[now%num])==1)){
          repaint();
              //now++;
          if(now==num*2-1){
              action[start]=0;
              action[clear]=1;
          }
                now++;
            infromation_tool();
          if(action[clear]==1){
              now--;
           on_dice_clicked();

          }
          if_it_is_bot();
          return;
      }
    }
    }

}



bool Game_New::town_init(int i){
    if(town[i].town==0){
        int my_town=town[i].private_town(player[now%num]);
        if(my_town==1){
            town_label(i);
           infromation_tool();
           return 1;
        }
    }
    else{
        int my_town=town[i].modify_town(player[now%num]);
        if(my_town==1){
            town_label(i);
            infromation_tool();
            return 1;
           }

    }
    return 0;

}
void Game_New::road_init(int i){
    if((road[i].private_road(player[now%num])==1)){
        repaint();
        the_bigest_road();
        infromation_tool();}
}


void Game_New::fiefmove(double x, double y){
    for(int i=0; i<19; i++){
        if(hex[i].is_hex(x, y, R)){
             fief_move(i);
             hex[i].fief_it(player[now%num]);
             infromation_tool();
             action[fief1]=0;
             action[clear]=1;

        }
    }
}


void Game_New::tradeto21(double x, double y){
  if(trading.is_to21(x, y))
      return;

}

void Game_New::tradeto31(double x, double y){
    if(trading.is_to31(x, y))
        return;
}

void Game_New::tradeto41(double x, double y){
    if(trading.is_to41(x, y))
        return;
}




