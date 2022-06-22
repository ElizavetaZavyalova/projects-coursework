#include "game_new.h"
#include "ui_game_new.h"
#include <QMessageBox>
#include <QPainter>
#include <QMouseEvent>

void Game_New::paintEvent(QPaintEvent* pe)
{
    Q_UNUSED(pe);

    QPainter painter(this);

    hex_paintEvent();
    road_paintEvent();
    number_paintEvent();



}

void Game_New::hex_paintEvent(){
        QPen pen;
       QPainter painter(this);
        pen.setWidth(R/5);

       pen.setBrush(QColor(131, 77, 24));
       painter.setPen(pen);
       for(int i=0; i<9;i++){
           double x1=ship[i].label->pos().x()+0.5*R, y1=ship[i].label->pos().y()+0.5*R;
          double x2=ship[i].town[1]->x, y2=ship[i].town[1]->y;
          double x3=ship[i].town[0]->x, y3=ship[i].town[0]->y;
       painter.drawLine(x2, y2, (x2+x1)/2, (y2+y1)/2);
       painter.drawLine(x3, y3, (x3+x1)/2,  (y3+y1)/2);
       }  pen.setWidth(R/6);
            pen.setCapStyle(Qt::RoundCap);
             // толщина пера
            pen.setBrush(QColor(239, 207, 138)); // цвет пера
            painter.setPen(pen); // применяем настройки пера

        for(int j=0; j<19; j++){
            (hex[j].zone=='c')?( painter.setBrush(QColor(205,133,63))):
            (hex[j].zone=='t')?( painter.setBrush(QColor(34,139,34))):
            (hex[j].zone=='s')?( painter.setBrush(QColor(141,149,154))):
            (hex[j].zone=='m')?( painter.setBrush(QColor(251,236,93))):
             (hex[j].zone=='w')?( painter.setBrush(QColor(197,227,132))):
             (painter.setBrush(QColor(253, 234, 168)));
        QPolygonF polygon;

        for(int i=0; i<6; i++){
           polygon << QPointF(hex[j].peek[i][0], hex[j].peek[i][1]);

        }
         painter.drawPolygon(polygon);
        }

}

void Game_New::town_label(int i){
    if(town[i].town==1){
    town[i].label=new QLabel(this);
    town[i].label->show();
      town[i].label->setScaledContents(true);

     town[i].label->setGeometry(town[i].x-0.4*R, town[i].y-0.45*R, 0.8*R, 0.8*R);
     (town[i].player->color=='r')?
     (town[i].label->setPixmap(QPixmap(":/new/prefix1/res/house1Red.png"))):
      (town[i].player->color=='b')?
      (town[i].label->setPixmap(QPixmap(":/new/prefix1/res/house1blue.png"))):
       (town[i].player->color=='w')?
       (town[i].label->setPixmap(QPixmap(":/new/prefix1/res/house1White.png"))):

        (town[i].label->setPixmap(QPixmap(":/new/prefix1/res/house1Yellow.png")));
    }
           else{
            (town[i].player->color=='r')?
           (town[i].label->setPixmap(QPixmap(":/new/prefix1/res/house2Red.png"))):
            (town[i].player->color=='b')?
            (town[i].label->setPixmap(QPixmap(":/new/prefix1/res/house2blue.png"))):
             (town[i].player->color=='w')?
             (town[i].label->setPixmap(QPixmap(":/new/prefix1/res/house2white.png"))):

              (town[i].label->setPixmap(QPixmap(":/new/prefix1/res/house2Yellow.png")));

    }

}

void Game_New::number_paintEvent(){
    QPen pen;
    pen.setBrush(QColor(0, 0, 0));
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setBrush(QColor(255,255,255));
    painter.setPen(pen);


    QFont font = (painter.font()) ;

    /* twice the size than the current font size */
    font.setPointSize(0.35*R);

    /* set the modified font to the painter */
    painter.setFont(font);
    for(int i=0; i<19; i++){
         QPointF point(hex[i].x, hex[i].y+0.45*R);
        if(hex[i].number[0]!=7)
        {

           painter.drawEllipse(point, 0.35*R,0.25*R);
         if(hex[i].number[0]>9)
         painter.drawText(hex[i].x-0.25*R, hex[i].y+0.6*R, (QString::number(hex[i].number[0])));
          else
          painter.drawText(hex[i].x-0.15*R, hex[i].y+0.6*R, (QString::number(hex[i].number[0])));
        }

    }

}

void Game_New::road_paintEvent(){
     QPen pen;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
       //pen.setCapStyle(Qt::RoundCap);
        pen.setWidth(R/5); // толщина пера
          // цвет пера
         // применяем настройки пера
        for(int i=0; i<72; i++){

         if(road[i].player!=nullptr){
        (road[i].player->color=='r')?(pen.setBrush(QColor(255, 43, 43))):
         (road[i].player->color=='b')?(pen.setBrush(QColor(18, 47, 170))):
          (road[i].player->color=='w')?(pen.setBrush(QColor(255, 255, 255))):
          (pen.setBrush(QColor(255, 255, 26)));
             QLine line(road[i].x1,road[i].y1, road[i].x2,road[i].y2);
             //line.
             painter.setPen(pen);
             painter.drawLine(line);
         }
        }

}

