#include "game_objects.h"

Road::Road()
{  left=nullptr;
   right=nullptr;
   player=nullptr;



}

void Road::cordinates(double R){
    x1=left->x;
    x2=right->x;
    y1=left->y;
    y2=right->y;
    double l=R/5, s=l, x11, y11, x22, y22; x11=x1; x22=x2; y11=y1; y22=y2;
    if(!(x1+l>=x2&&x2+l>=x1)){ l=l*sin(M_PI/6); s=s*cos(M_PI/6);
    }
    ((y1<=y2-l&&y2>=y2-l)||(y1>=y2-l&&y2<=y2-l))?(y22-=l):
    ((y1<=y2+l&&y2>=y2+l)||(y1>=y2+l&&y2<=y2+l))?(y22+=l):(y22=y2);

    ((y1<=y1-l&&y2>=y1-l)||(y1>=y1-l&&y2<=y1-l))?(y11-=l):
    ((y1<=y1+l&&y2>=y1+l)||(y1>=y1+l&&y2<=y1+l))?(y11+=l):(y11=y1);

    ((x1<=x2-s&&x2>=x2-s)||(x1>=x2-s&&x2<=x2-s))?(x22-=s):
     ((x1<=x2+s&&x2>=x2+s)||(x1>=x2+s&&x2<=x2+s))?(x22+=s):(x22=x2);

     ((x1<=x1-s&&x2>=x1-s)||(x1>=x1-s&&x2<=x1-s))?(x11-=s):
     ((x1<=x1+s&&x2>=x1+s)||(x1>=x1+s&&x2<=x1+s))?(x11+=s):(x11=x1);


    x1=x11; x2=x22; y1=y11; y2=y22;
}


int Road::private_road(Player& player){
    if(this->player==nullptr){
    if(can_create(player)){
    if((player.clay>0&&player.wood>0)||player.road_new>0){
        if(player.road_new>0)
        {    player.road_new--;
        this->player=&player;

            player.road++;
        return 0;
        }
        else{
        player.clay--;
        player.wood--;
        this->player=&player;

        player.road++;
        return 1;
        }
    }
    else return 2;// недостаточно ресурсов
    }
    else return 3; // рядом отсутствую дороги
    }
    else return 4; //уже занято
}

bool Road::can_create( Player& player){ //1 все хорошо
    Town*town[2];                           //0 нельзя ставить
    town[0]=this->left;
    town[1]=this->right;
    if(town[0]->player==&player||town[0]->player==nullptr){
        if(town[1]->player==&player||town[1]->player==nullptr){
    for(int i=0; i<2; i++){  
    if((town[i]->player==&player)&&(town[(i+1)%2]->player==&player||town[(i+1)%2]->player==nullptr))
            return 1;
    if(!((town[i]->player==&player)||(town[i]->player==nullptr))&&(town[(i+1)%2]->player==&player||town[(i+1)%2]->player==nullptr))
            return 0;
    if(town[i]->central!=this&&town[i]->central!=nullptr)
        if((town[i]->central)->player==&player)
            return 1;
    if(town[i]->left!=this&&town[i]->left!=nullptr)
        if((town[i]->left)->player==&player)
            return 1;
    if(town[i]->right!=this&&town[i]->right!=nullptr)
        if((town[i]->right)->player==&player)
            return 1;
    }
        }}
    return 0;
}

bool Road::is_road(double x, double y, double R){

    if((y>=y1&&y<=y2)||(y>=y2&&y<=y1)){
     double r=sqrtf((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
     double r1=sqrtf((y2-y)*(y2-y)+(x2-x)*(x2-x));
     double r2=sqrtf((y-y1)*(y-y1)+(x-x1)*(x-x1));
     if(abs(r-r1-r2)<=R/12)
         return 1;
    }
    return 0;
    return 0;
}

