#include "game_objects.h"
#include "cmath"
#include <iostream>
Hex::Hex()
{
 number[1]=1;
 zone='p';
 for(int i=0; i<6; i++){
     town[i]=nullptr;
 }
}

Hex::~Hex(){
    if(label!=nullptr)
  delete label;
}

void Hex::cordinates(double x, double y, double X, double Y){
   this->x=x+X;
   this->y=y+Y;

}

void Hex::cordinates_peek(double R){
    double h=R, s=sqrt(3)*(h/2);
    town[0]->cordinates(x, y-h);
    town[1]->cordinates(x-s, y-0.5*h);
    town[2]->cordinates(x-s, y+0.5*h);
    town[3]->cordinates(x, y+h);
    town[4]->cordinates(x+s, y+0.5*h);
    town[5]->cordinates(x+s, y-0.5*h);
    for(int i=0; i<6; i++){
        peek[i][0]=town[i]->x;
        peek[i][1]=town[i]->y;
    }
}

void Hex::town_new(Town& town1){
    int i=0;
    while(i!=6/*&&town[i]!=nullptr*/){
      if(town[i]==nullptr)
          break;
        i++;
    }
    if(i!=6){
        town[i]=(&town1);
    }

}
void Hex::distrubute(){
    if(number[1]==0){
    for(int i=0; i<6; i++){
        if ((town[i]->player!=nullptr)){
                if(zone== 'c')
               (*(town[i]->player)).clay+=(town[i]->town);
                else if(zone== 't')
               (*(town[i]->player)).wood+=(town[i]->town);
                else if(zone== 's')
               (*(town[i]->player)).stone+=(town[i]->town);
               else  if(zone== 'm')
               (*(town[i]->player)).millet+=(town[i]->town);
                else if(zone== 'w')
               (*(town[i]->player)).wool+=(town[i]->town);
         }
    }
    }
}


bool Hex::is_hex(double x, double y,double R){
    if (abs(x-(this->x))<=0.8*R)
        if(abs(y-(this->y))<=0.8*R)
            return 1;
  return 0;
}
void Hex::fief_it(Player&play){
    for(int i=0; i<6; i++){
        if(town[i]->player!=nullptr){
         char r=town[i]->player->not7();
         (r=='m')?(play.millet++):
          (r=='c')?(play.clay++):
           (r=='s')?(play.stone++):
           (r=='t')?(play.wood++):
            (r=='w')?(play.wool++):
                     (play.clay);
    }
}
}


