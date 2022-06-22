#include "trader_and_help.h"
#include "game_objects.h"
#include <QPainter>
void Ship::set_Town(Town&town2, Town&town1){
    town[0]=&town1;
    town[1]=&town2;
};
Ship::~Ship(){
    delete label;
}
bool Ship::is_ship(Player& play){
    if(town[0]->player==&play||town[1]->player==&play)
        return 1;
    return 0;
}

trader::~trader(){
    for(int i=0; i<2; i++)
    delete tradeplayer[i];
    for(int i=0; i<5; i++)
    delete trade[i];
    delete trading;
    delete cost;
}
bool trader::is_to21(int x, int y){
    int x1=trade[4]->x();
    int h=trade[4]->height();
    int y1=trade[4]->y();
    int w=trade[4]->width();
    if(x1<x&&x<x1+w&&y1<y&&y<y1+h){
        trade_res[4]=(trade_res[4]+1)%5;
        (trade_res[4]==clay)?(trade[4]->setPixmap(QPixmap(":/new/prefix1/res/clay.png"))):
        (trade_res[4]==millet)?(trade[4]->setPixmap(QPixmap(":/new/prefix1/res/milet.png"))):
        (trade_res[4]==tree)?(trade[4]->setPixmap(QPixmap(":/new/prefix1/res/tree.png"))):
        (trade_res[4]==stown)?(trade[4]->setPixmap(QPixmap(":/new/prefix1/res/stone.png"))):
        (trade[4]->setPixmap(QPixmap(":/new/prefix1/res/shipbe.png")));
           return 1 ;
    }
    return 0;
}
bool trader::is_to31(int x, int y){
   for(int i=0; i<5; i++){
   int x1=trade[i]->x();
   int h=trade[i]->height();
   int y1=trade[i]->y();
   int w=trade[i]->width();
   if(x1<x&&x<x1+w&&y1<y&&y<y1+h&&i!=3){
       trade_res[i]=(trade_res[i]+1)%5;
       (trade_res[i]==clay)?(trade[i]->setPixmap(QPixmap(":/new/prefix1/res/clay.png"))):
       (trade_res[i]==millet)?(trade[i]->setPixmap(QPixmap(":/new/prefix1/res/milet.png"))):
       (trade_res[i]==tree)?(trade[i]->setPixmap(QPixmap(":/new/prefix1/res/tree.png"))):
       (trade_res[i]==stown)?(trade[i]->setPixmap(QPixmap(":/new/prefix1/res/stone.png"))):
       (trade[i]->setPixmap(QPixmap(":/new/prefix1/res/shipbe.png")));
               return 1;
   }

   }
   return 0;
};
bool trader::is_to41(int x, int y){
    for(int i=0; i<5; i++){
    int x1=trade[i]->x();
    int h=trade[i]->height();
    int y1=trade[i]->y();
    int w=trade[i]->width();
    if(x1<x&&x<x1+w&&y1<y&&y<y1+h){
        trade_res[i]=(trade_res[i]+1)%5;
        (trade_res[i]==clay)?(trade[i]->setPixmap(QPixmap(":/new/prefix1/res/clay.png"))):
        (trade_res[i]==millet)?(trade[i]->setPixmap(QPixmap(":/new/prefix1/res/milet.png"))):
        (trade_res[i]==tree)?(trade[i]->setPixmap(QPixmap(":/new/prefix1/res/tree.png"))):
        (trade_res[i]==stown)?(trade[i]->setPixmap(QPixmap(":/new/prefix1/res/stone.png"))):
        (trade[i]->setPixmap(QPixmap(":/new/prefix1/res/shipbe.png")));
            return 1;
    }
    }
    return 0;
}


bool trader::to_21(Player &Play){
     bool tray=0;
    if(trade_res[0]==clay&&Play.clay>1){
        Play.clay-=2; tray=1;
    }
    else if(trade_res[0]==wool&&Play.wool>1){
        Play.wool-=2; tray=1;
    }
    else if(trade_res[0]==tree&&Play.wood>1){
        Play.wood-=2; tray=1;
    }
    else if(trade_res[0]==millet&&Play.millet>1){
        Play.millet-=2; tray=1;
    }
    else if(trade_res[0]==stown&&Play.stone>1){
        Play.stone-=2; tray=1;
    }
    if(tray){
        (trade_res[4]==clay)?(Play.clay++):
        (trade_res[4]==wool)?(Play.wool++):
        (trade_res[4]==tree)?(Play.wood++):
        (trade_res[4]==stown)?(Play.stone++):
         (trade_res[4]==millet)?(Play.millet++):
                                (Play.millet);
         return 1;
        }

 return 0;
}


 bool trader::to_31(Player &Play){
     bool tray[3];
     for(int i=0; i<3; i++){
         tray[i]=0;
         if(trade_res[i]==clay&&Play.clay>0){
             Play.clay--; tray[i]=1;
         }
         else if(trade_res[i]==wool&&Play.wool>0){
             Play.wool--; tray[i]=1;
         }
         else if(trade_res[i]==tree&&Play.wood>0){
             Play.wood--; tray[i]=1;
         }
         else if(trade_res[i]==millet&&Play.millet>0){
             Play.millet--; tray[i]=1;
         }
         else if(trade_res[i]==stown&&Play.stone>0){
             Play.stone--; tray[i]=1;
         }
     }
     if(tray[0]&&tray[1]&&tray[2]){
         (trade_res[4]==clay)?(Play.clay++):
         (trade_res[4]==wool)?(Play.wool++):
         (trade_res[4]==tree)?(Play.wood++):
         (trade_res[4]==stown)?(Play.stone++):
          (trade_res[4]==millet)?(Play.millet++):
                                 (Play.millet);
          return 1;
         }
     else {
         for(int i=0; i<3; i++){
            if(tray[i]){
             if(trade_res[i]==clay){
                 Play.clay++;
             }
             else if(trade_res[i]==wool){
                 Play.wool++;
             }
             else if(trade_res[i]==tree){
                 Play.wood++;
             }
             else if(trade_res[i]==millet){
                 Play.millet++;
             }
             else if(trade_res[i]==stown){
                 Play.stone++;
             }
         }
     }


 }
      return 0;
 }

 bool trader::to_41(Player &Play){
     bool tray[4];
     for(int i=0; i<4; i++){
         tray[i]=0;
         if(trade_res[i]==clay&&Play.clay>0){
             Play.clay--; tray[i]=1;
         }
         else if(trade_res[i]==wool&&Play.wool>0){
             Play.wool--; tray[i]=1;
         }
         else if(trade_res[i]==tree&&Play.wood>0){
             Play.wood--; tray[i]=1;
         }
         else if(trade_res[i]==millet&&Play.millet>0){
             Play.millet--; tray[i]=1;
         }
         else if(trade_res[i]==stown&&Play.stone>0){
             Play.stone--; tray[i]=1;
         }
     }
     if(tray[0]&&tray[1]&&tray[2]&&tray[3]){
         (trade_res[4]==clay)?(Play.clay++):
         (trade_res[4]==wool)?(Play.wool++):
         (trade_res[4]==tree)?(Play.wood++):
         (trade_res[4]==stown)?(Play.stone++):
          (trade_res[4]==millet)?(Play.millet++):
                                 (Play.millet);
         return 1;
         }
     else {
         for(int i=0; i<4; i++){
            if(tray[i]){
             if(trade_res[i]==clay){
                 Play.clay++;
             }
             else if(trade_res[i]==wool){
                 Play.wool++;
             }
             else if(trade_res[i]==tree){
                 Play.wood++;
             }
             else if(trade_res[i]==millet){
                 Play.millet++;
             }
             else if(trade_res[i]==stown){
                 Play.stone++;
             }
         }
     }
     }
     return 0;

 }
