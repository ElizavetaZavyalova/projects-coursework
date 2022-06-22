#include "game_objects.h"

Player::Player()
{

    clay=4;
    wood=4;
    stone=0;
    millet=2;
    wool=2;
    monopoly=0;
    ivent=0;
    new_road=0;
    knight=0;
    points=0;
    road=0;
    army=0;
    cards=0;
    vilage=0;
    sity=0;
    the_bigest_roud=0;
}

void  Player::set_init(char c, QString name){
    color=c;
    this->name=name;
}
void Player::bot_init(){
    bot=1;
}

char Player::not7(){
    int z=millet+clay+stone+wood+wool; int k=0;
    if(z!=0){
     char res[z];
     if(millet>0){
         res[k]='m'; k++;}
     if(stone>0) {
              res[k]='s'; k++;
          }
     if(clay>0) {
         res[k]='c'; k++;
     }
     if(wood>0) {
         res[k]='t'; k++;
     }
     if(wool>0) {
         res[k]='w'; k++;
     }
     char r=res[rand()%k];
     (r=='m')?(millet--):
      (r=='c')?(clay--):
       (r=='s')?(stone--):
       (r=='t')?(wood--):
        (r=='w')?(wool--):
                 (clay);
    return r;
    }
    return 'n';

}
