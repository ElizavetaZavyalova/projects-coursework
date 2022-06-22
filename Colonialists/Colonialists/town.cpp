#include "game_objects.h"
#include <cmath>
#include <iostream>

Town::~Town()
{
   if(label!=nullptr)
      delete label;

}
Town::Town(){
    right=nullptr;
       left=nullptr;
       central=nullptr;
       player=nullptr;
       town=0;

       x=-1;
       y=-1;
}

void Town::cordinates(double x, double y){
   this->x=x;
   this->y=y;
}


bool Town::road_create(Town& town1, Road &road, double R){
  bool q=1;
  Road* left1=left;
  Road* right1=right;
  Road* central1=central;
  if(left1!=nullptr)
   if((left1->left==&town1)||(left1->right==&town1)) q=0;
    if(right1!=nullptr)
      if((right1->left==&town1)||(right1->right==&town1)) q=0;
        if(central1!=nullptr)
        if((central1->left==&town1)||(central1->right==&town1)) q=0;
        if(q){
            (left==nullptr)? (left=&road):
              (right==nullptr)? (right=&road):(central=&road);
  (town1.left==nullptr)? (town1.left=&road):
    (town1.right==nullptr)? (town1.right=&road):(town1.central=&road);
      road.left=this;
      road.right=(&town1);
         road.cordinates( R);
        return 1; }
                             return 0;


}

int Town::private_town(Player& player){
    if(this->player==nullptr){
    if(can_create(player)){
    if(player.clay>0&&player.wood>0&&player.wool>0&&player.millet>0){
        player.clay--;
        player.wood--;
        player.wool--;
        player.millet--;
        town++;
        player.points++;
        this->player=&player;
        return 1;//деревня построена
    }
    else return 2;// недостаточно ресурсов
    }
    else return 3; // рядом отсутствую дороги
    }
    else return 4; //уже занято
}

int Town::modify_town(Player &player){
    if(this->player==&player){
    if(player.millet>1&&player.stone>2&&this->town==1)  {
    player.millet-=2;
    player.stone-=3;
    town++;
    player.sity++;
    player.vilage--;
    player.points++;
    return 1; //все хорошо
    }
    else return 2;//недостаточно ресурсов
    }
    else return 4;//уже занято

}

bool Town::can_create(const Player& player){
    int r=0;

        if((right!=nullptr)?((right->player==&player)||(right->player==nullptr)):(1))
            r++;
        if((left!=nullptr)?((left->player==&player)||(left->player==nullptr)):(1))
            r++;
        if((central!=nullptr)?((central->player==&player)||(central->player==nullptr)):(1))
            r++;
     if(r==3){
        if((right!=nullptr)?((right->player==&player)):(0))
            r++;
        if((left!=nullptr)?((left->player==&player)):(0))
            r++;
        if((central!=nullptr)?((central->player==&player)):(0))
            r++;}
    if(r>3)
        return 1;// все хорошо
    else
        return 0; // нелья ставить
}

bool Town::is_number(double x, double y, double R){
    if (abs(x-(this->x))<R/6)
     if(abs(y-(this->y))<R/6)
            return 1;
  return 0;
}
