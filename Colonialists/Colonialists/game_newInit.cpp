#include "game_new.h"
#include "ui_game_new.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>
#include <QLabel>
#include <QWidget>
#include <QPushButton>

Game_New::Game_New(QWidget *parent) :
     QMainWindow(parent),
    ui(new Ui::Game_New)
{
    ui->setupUi(this);
   for(int i=0; i<12; i++){
   action[i]=0;
   }

   action[start]=1;
   action[clear]=0;
   num=2;

}

Game_New::~Game_New(){
      delete ui;
    delete dice[0];
    delete dice[1];

    delete fief;
    delete[] player;



}
void Game_New::init_all(){

    X=this->width()/10;

    Y=this->height()/10;
    R=sqrtf(X*X+Y*Y)/2.8;
    X*=2;
    Y*=2;
    game_init();

    hex_number();
    road_create();
    repaint();
    Ship_init();
    hex_init();
    //information_inited();

    buttons_create();
    create_trade();

    ui->White->setVisible( false );
    ui->Yellow->setVisible( false );
    ui->Red->setVisible( false );
    ui->Blue->setVisible( false );
    for(int i=0; i<num; i++){
       if (player[i].color=='r'){
           ui->Red->setVisible(true);
           ui->Red->setText(player[i].name);

       }
       else if(player[i].color=='b'){
           ui->Blue->setVisible(true);
           ui->Blue->setText(player[i].name);
       }
       else if(player[i].color=='w'){
           ui->White->setVisible(true);
           ui->White->setText(player[i].name);
       }
       else if(player[i].color=='y'){
           ui->Yellow->setVisible(true);
           ui->Yellow->setText(player[i].name);
       }
       }bool deletebot=1;
    for(int i=0; i<num; i++){
     (!player[i].bot)?(deletebot=0):(deletebot);
    }
    (deletebot)?(player[0].bot=0):(player[0].bot);
     ui->endgame->setText("Максимальное кол-во победных очков "+QString::number(this->point));
    if_it_is_bot();
    infromation_tool();
 }


void Game_New::hex_connect(int i, int q, int z, int e, int d){
    hex[i].town[0]=&town[q];
    hex[i].town[1]=&town[z];z++;
    hex[i].town[2]=&town[e];e++;
    hex[i].town[3]=&town[d];d++;
    hex[i].town[4]=&town[e];
    hex[i].town[5]=&town[z];

}
void Game_New::game_init(){
    double y=R, x=(sqrtf(3))*(y/2);
    int q=0, z=3, e=7, d=12;
    double y1=30, x1=3*x;
    for(int i=0; i<3; i++){
       hex_connect(i, q, z, e, d);  q++; z++; e++; d++;
       hex[i].cordinates(x1, y1, X, Y);x1+=2*x;
        hex[i].cordinates_peek(R);
    }
    x1=2*x, y1+=1.5*y;
    q=7; z=11; e=16; d=22;
    for(int i=3; i<7; i++){
        hex_connect(i, q, z,e,d);  q++; z++; e++; d++;
         hex[i].cordinates(x1,y1, X, Y); x1+=2*x;
           hex[i].cordinates_peek(R);
    }
    x1=x, y1+=1.5*y;
    q=16; z=21; e=27; d=33;
    for(int i=7; i<12; i++){
         hex_connect(i, q, z, e, d);  q++; z++; e++; d++;
          hex[i].cordinates(x1,y1, X, Y); x1+=2*x;
            hex[i].cordinates_peek(R);
    }
    x1=2*x, y1+=1.5*y;
    q=28; z=33; e=38; d=43;
        for(int i=12; i<16; i++){
             hex_connect(i, q, z, e, d);  q++; z++; e++; d++;
              hex[i].cordinates(x1,y1, X, Y); x1+=2*x;
                hex[i].cordinates_peek(R);
        }
    x1=3*x, y1+=1.5*y;
    q=39; z=43; e=47; d=51;
    for(int i=16; i<19; i++){
         hex_connect(i, q, z,e, d); q++; z++; e++; d++;
          hex[i].cordinates(x1,y1, X, Y); x1+=2*x;
            hex[i].cordinates_peek(R);
    }
}


void Game_New::road_create(){
    int k=0;
    for(int i=0; i<19; i++){
        for(int j=0; j<6; j++){
           if(hex[i].town[j%6]->road_create(*(hex[i].town[(j+1)%6]), road[k], R))
               k++;
        }
    }

}

void Game_New::Ship_init(){
    //ship[0]=new Ship;

    for(int i=0; i<9; i++){
    ship[i].label=new QLabel("", this);
    ship[i].label->setScaledContents(true);
    ship[i].label->show();
    }
     ship[0].set_Town(*hex[0].town[0], *hex[0].town[1]);
      ship[0].label->setPixmap(QPixmap("ship31.png"));//3:1
       ship[0].label->setGeometry(hex[0].x-1.5*R, hex[0].y-1.9*R, R, R);

    ship[1].set_Town(*hex[1].town[0], *hex[1].town[5]);
   ship[1].label->setPixmap(QPixmap("ship21clay.png"));
     ship[1].label->setGeometry(hex[1].x+0.25*R, hex[1].y-2*R, R, R);

  ship[2].set_Town(*hex[3].town[1], *hex[3].town[2]);
  ship[2].label->setPixmap(QPixmap("ship31.png"));//3:1
   ship[2].label->show();
   ship[2].label->setGeometry(hex[3].x-2*R, hex[3].y-0.75*R, R, R);
     ship[3].set_Town(*hex[6].town[0], *hex[6].town[5]);
     ship[3].label->setPixmap(QPixmap("ship21tree.png"));
     ship[3].label->show();
      ship[3].label->setGeometry(hex[6].x+0.25*R, hex[6].y-2*R, R, R);
    ship[4].set_Town(*hex[11].town[5], *hex[11].town[4]);
   ship[4].label->setPixmap(QPixmap("ship21ship.png"));
    ship[4].label->show();
     ship[4].label->setGeometry(hex[11].x+1.2*R, hex[11].y-0.75*R, R, R);
     ship[5].set_Town(*hex[12].town[1], *hex[12].town[2]);
     ship[5].label->setPixmap(QPixmap("ship31.png"));//3:1
      ship[5].label->show();
      ship[5].label->setGeometry(hex[12].x-2*R, hex[12].y-0.75*R, R, R);
     ship[6].set_Town(*hex[15].town[3], *hex[15].town[4]);
    ship[6].label->setPixmap(QPixmap("ship21millet.png"));
     ship[6].label->show();
     ship[6].label->setGeometry(hex[15].x+0.25*R, hex[15].y+0.75*R, 1.25*R, R);
    ship[7].set_Town(*hex[16].town[2], *hex[16].town[3]);
    ship[7].label->setPixmap(QPixmap("ship31.png"));//3:1
     ship[7].label->show();
     ship[7].label->setGeometry(hex[16].x-1.25*R, hex[16].y+0.75*R, R, R);
     ship[8].set_Town(*hex[17].town[3], *hex[17].town[4]);
    ship[8].label->setPixmap(QPixmap("ship21stown.png"));
      ship[8].label->show();
     ship[8].label->setGeometry(hex[17].x+0.35*R, hex[17].y+0.75*R, R, R);
}


void Game_New::hex_init(){
    for(int i=0; i<19; i++){
      if(hex[i].label==nullptr){
    hex[i].label=new QLabel("", this);
    hex[i].label->setScaledContents(true);
    hex[i].label->show();}
    (hex[i].zone=='t')?(hex[i].label->setPixmap(QPixmap("tree.png"))):
    (hex[i].zone=='m')?(hex[i].label->setPixmap(QPixmap("milet.png"))):
    (hex[i].zone=='s')?(hex[i].label->setPixmap(QPixmap("stone.png"))):
    (hex[i].zone=='c')?(hex[i].label->setPixmap(QPixmap("clay.png"))):
    (hex[i].zone=='w')?(hex[i].label->setPixmap(QPixmap("shipbe.png"))):
                       (hex[i].label->setPixmap(QPixmap("cactus.png")));
    (hex[i].zone!='d')?(hex[i].label->setGeometry(hex[i].x-0.4*R, hex[i].y-0.65*R, 0.75*R, 0.75*R)):
                       (hex[i].label->setGeometry(hex[i].x-0.5*R, hex[i].y-0.5*R, R, R));
    }
    fief=new QLabel("", this);
    fief->setScaledContents(true);
    fief->show();
    fief->setPixmap(QPixmap("fief_M.png"));
   fief_move(9);
}
void Game_New::fief_move(int i){
     fief->setGeometry(hex[i].x-0.85*R, hex[i].y-0.95*R, 1.75*R, 1.75*R);
     for(int p=0; p<19; p++){

     hex[p].number[1]=0;}
     hex[i].number[1]=1;

}
void Game_New::hex_number(){
    char zone[5];
   zone[0]='m';
   zone[1]='s';
   zone[2]='c';
   zone[3]='t';
   zone[4]='w';
   hex[0].number[0]=11;
   hex[1].number[0]=4; 
   hex[2].number[0]=8;  
   hex[3].number[0]=12; 
   hex[4].number[0]=3;
   hex[5].number[0]=11;
   hex[6].number[0]=10;
   hex[7].number[0]=9;
   hex[8].number[0]=6;
   hex[9].number[0]=7;
   hex[10].number[0]=9;
   hex[11].number[0]=5;
   hex[12].number[0]=10;
   hex[13].number[0]=5;
   hex[14].number[0]=4;
   hex[15].number[0]=2;
   hex[16].number[0]=8;
   hex[17].number[0]=3;
   hex[18].number[0]=6;
   srand(time(0));
   for(int i=0; i<19; i++){
    hex[i].zone=zone[rand()%5];
   }
   hex[9].zone='d';
}






void Game_New::buttons_create(){
    for(int i=0; i<2; i++){
        dice[i]=new QLabel("1", this);

        dice[i]->show();

     dice[i]->setScaledContents(true);
      dice[i]->setPixmap(QPixmap(":/new/prefix1/res/1.png"));
    }
    dice[0]->setGeometry(hex[18].x+5.5*R-13*R, hex[18].y+R, 1.25*R, 1.25*R);

      dice[1]->setGeometry(hex[18].x+4*R-13*R, hex[18].y+R, 1.25*R, 1.25*R);

}


void Game_New::create_trade(){
    trading.trading=new QLabel(this);
    trading.trading->hide();
    trading.trading->setScaledContents(true);
    trading.trading->setPixmap(QPixmap(":/new/prefix1/res/screne_new.png"));

    trading.trading->setGeometry(hex[2].x+4.5*R, hex[2].y-2*R, 6*R, 6*R);
    for(int i=0; i<5; i++){
        trading.trade[i]=new QLabel(this);
        trading.trade[i]->hide();
        trading.trade[i]->setPixmap(QPixmap(":/new/prefix1/res/milet.png"));
        trading.trade[i]->setScaledContents(true);
        trading.trade_res[i]=millet;
    }
        for(int i=0; i<2; i++){



        trading.tradeplayer[i]=new QPushButton(this);
          trading.tradeplayer[i]->hide();

          trading.tradeplayer[i]->setStyleSheet("  QPushButton { font-size: 12.5px; background-color: #3f48cc; color:#ffffff}");
        }
        trading.tradeplayer[0]-> setGeometry(hex[2].x+8.15*R, hex[2].y-1.5*R, 2*R, R);
        trading.tradeplayer[1]-> setGeometry(hex[2].x+8.15*R, hex[2].y+2.5*R, 2*R, R);
        trading.tradeplayer[0]->setText("Торговать");
        trading.tradeplayer[1]->setText("Закончить торговлю");
        trading.trade[4]->setGeometry(hex[2].x+8.15*R, hex[2].y, 2*R, 2*R);
        connect(trading.tradeplayer[0],SIGNAL(released()),this,SLOT(trade()));
        connect(trading.tradeplayer[1],SIGNAL(released()),this,SLOT(end_trade()));
        trading.cost=new QLabel(this);
        trading.cost->show();
        trading.cost->setPixmap(QPixmap(":/new/prefix1/res/cost.png"));
        trading.cost->setScaledContents(true);
        trading.cost->setGeometry(hex[2].x+4.5*R, hex[2].y+4.5*R, 5*R, 4.5*R);
}
