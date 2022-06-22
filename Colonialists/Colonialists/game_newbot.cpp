#include "game_new.h"
#include "ui_game_new.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QWidget>
#include <QPushButton>



void Game_New::if_it_is_bot(){
    if(player[now%num].bot){
        if(action[clear]){
            play_bot();
            repaint();
          }
        if(!action[clear]&&action[start]){
            start_bot();
            if_it_is_bot();
        }


}
}
void Game_New::start_bot(){
               if(player[now%num].vilage==0){
                   bool can=1;
               while(can){
                  int i=rand()%54;
                   if(town[i].player==nullptr)
                           if((town[i].right!=nullptr)?(town[i].right->player==&player[now%num]||(town[i].right->player==nullptr)):(1))
                           if((town[i].central!=nullptr)?(town[i].central->player==&player[now%num]||town[i].central->player==nullptr):(1))
                           if((town[i].left!=nullptr)?(town[i].left->player==&player[now%num]||town[i].left->player==nullptr):(1)){
                       town[i].player=&player[now%num];
                       town[i].town=1;
                       can=0;
                             player[now%num].clay--;
                             player[now%num].wool--;
                             player[now%num].millet--;
                             player[now%num].wood--;
                             player[now%num].vilage++;
                       player[now%num].points++;
                       //now++;
                      town_label(i);
                      infromation_tool();

                   }
               }
               }
               if(player[now%num].vilage==1&&now<num){

             for(int i=0; i<72; i++){
                 if((road[i].private_road(player[now%num])==1)){
                     repaint();
                     now++;

                     infromation_tool();
                     //(now==num*2)?(set=1):(set=0);
                     return;
                 }
               }
               }  Town* town1=nullptr;
               if(now>=num&&now<2*num&&player[now%num].vilage==1){
                   bool can=1;
               while(can){
                  int i=rand()%54;
                   if(town[i].player==nullptr)
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
                        can=0;
                       town_label(i);
                       infromation_tool();
                       town1=&town[i];

                   }
               }
               if(player[now%num].vilage==2){
                can=1;
                while(can){
                  int  i=rand()%3;
                  Road*road1=nullptr;
                  (i==0)?(road1=town1->left): (i==1)?(road1=town1->right):(road1=town1->central);
                  if(road1!=nullptr){
                 if((road1->private_road(player[now%num])==1)){
                     repaint();
                         //now++;
                     if(now==num*2-1){
                         action[start]=0;
                         action[clear]=1;
                     }
                           now++;
                           can=0;

                       infromation_tool();
                     if(action[clear]==1){
                         now--;
                         on_dice_clicked();
                         return;

                     }

                     return;
                 }
                  }
               }
               }


}

}
void Game_New::play_bot(){
    play_bot_trade();
    if(player[now%num].clay>0&&player[now%num].millet>0\
            &&player[now%num].wood>0&&player[now%num].wool>0){


        for(int i=0; i<54; i++){
          if(town_init(i)){


          }
        }


              for(int i=0; i<72; i++){
                 road[i].private_road(player[now%num]);
                 the_bigest_road();
              }

    }if(player[now%num].millet>1\
            &&player[now%num].stone>2){
        for(int i=0; i<54; i++){
         town_init(i);
    }
}if(player[now%num].millet>0\
            &&player[now%num].stone>0&&player[now%num].wool>0){
        if(cards.give(player[now%num])=='k'){
            player[now%num].army++;
            player[now%num].knight--;
            the_bigest_army();
        }
    }
    //здесь
 on_dice_clicked();
    return;
}


bool Game_New::play_bot_trade(){
   if(player[now%num].clay>4){
       if(player[now%num].millet<2){
           player[now%num].millet++;
           player[now%num].clay-=4;
           return 1;
       }
       else if(player[now%num].wood==0){
           player[now%num].wood++;
           player[now%num].clay-=4;
            return 1;
       }
       else if(player[now%num].wool==0){
           player[now%num].wool++;
           player[now%num].clay-=4;
            return 1;
       }
       else if(player[now%num].clay==0){
           player[now%num].clay++;
           player[now%num].clay-=4;
            return 1;
       }
       else if(player[now%num].stone<3){
           player[now%num].stone++;
           player[now%num].clay-=4;
            return 1;
       }
   }
   if(player[now%num].millet>5){
       if(player[now%num].millet<2){
           player[now%num].millet++;
           player[now%num].millet-=4;
            return 1;
       }
       else if(player[now%num].wood==0){
           player[now%num].wood++;
           player[now%num].millet-=4;
            return 1;
       }
       else if(player[now%num].wool==0){
           player[now%num].wool++;
           player[now%num].millet-=4;
            return 1;
       }
       else if(player[now%num].clay==0){
           player[now%num].clay++;
           player[now%num].millet-=4;
            return 1;
       }
       else if(player[now%num].stone<3){
           player[now%num].stone++;
           player[now%num].millet-=4;
            return 1;
       }
   }
   if(player[now%num].stone>7){
       if(player[now%num].millet<2){
           player[now%num].millet++;
           player[now%num].stone-=4;
            return 1;
       }
       else if(player[now%num].wood==0){
           player[now%num].wood++;
           player[now%num].stone-=4;
            return 1;
       }
       else if(player[now%num].wool==0){
           player[now%num].wool++;
           player[now%num].stone-=4;
            return 1;
       }
       else if(player[now%num].clay==0){
           player[now%num].clay++;
           player[now%num].stone-=4;
            return 1;
       }
       else if(player[now%num].stone<3){
           player[now%num].stone++;
           player[now%num].stone-=4;
            return 1;
       }
   }
   if(player[now%num].wool>4){
       if(player[now%num].millet<2){
           player[now%num].millet++;
           player[now%num].wool-=4;
            return 1;
       }
       else if(player[now%num].wood==0){
           player[now%num].wood++;
           player[now%num].wool-=4;
            return 1;
       }
       else if(player[now%num].wool==0){
           player[now%num].wool++;
           player[now%num].wool-=4;
            return 1;
       }
       else if(player[now%num].clay==0){
           player[now%num].clay++;
           player[now%num].wool-=4;
            return 1;
       }
       else if(player[now%num].stone<3){
           player[now%num].stone++;
           player[now%num].wool-=4;
            return 1;
       }
   }
   if(player[now%num].wood>4){
       if(player[now%num].millet<2){
           player[now%num].millet++;
           player[now%num].wood-=4;
            return 1;
       }
       else if(player[now%num].wood==0){
           player[now%num].wood++;
           player[now%num].wood-=4;
            return 1;
       }
       else if(player[now%num].wool==0){
           player[now%num].wool++;
           player[now%num].wood-=4;
            return 1;
       }
       else if(player[now%num].clay==0){
           player[now%num].clay++;
           player[now%num].wood-=4;
            return 1;
       }
       else if(player[now%num].stone<3){
           player[now%num].stone++;
           player[now%num].wood-=4;
            return 1;
       }
        return 0;
   }
return 0;
}
