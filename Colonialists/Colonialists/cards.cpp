#include "game_objects.h"
#include <time.h>

Cards::Cards(){
    points[0]='u';
    points[1]='g';
    points[2]='t';
    points[3]='l';
    points[4]='c';
    for(int i=5; i<19; i++){
        points[i]='k';
    }
     points[19]='m';
      points[20]='m';
      points[21]='i';
       points[22]='i';
       points[23]='r';
        points[24]='r';
    }

char Cards::give(Player &play){
    if(play.stone>0&&play.wool>0&&play.millet>0){
        play.stone--;
        play.wool--;
        play.millet--;
    srand(time(NULL));
    char d=points[rand()%25];
    if(d=='m'){
        play.monopoly++;
        play.cards++;
    }
   else if(d=='i'){
        play.ivent++;
        play.cards++;
    }
    else if(d=='r'){
         play.new_road++;
         play.cards++;
     }
    else if(d=='k'){
         play.knight++;
         play.cards++;
     }
    else{
        play.points++;
    }
     return d;
    }
    return 'n';
}


