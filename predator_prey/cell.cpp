#include "cell.h"

#include "mainwindow.h"
int Cell::w=20;
int Cell::chose=3;
int Cell::spead=10000;




Cell::Cell(QObject *parent)
    : QObject(parent), QGraphicsItem()
{

    connect(this,SIGNAL(press()),this, SLOT(change()));

     timer = new QTimer(this);
        timer->setInterval(rand()%5*Cell::spead);
        connect(timer, SIGNAL(timeout()), this, SLOT(complete()));

        status=rand()%3;
}
void Cell::complete(){
    timer->stop();

    this->set_status(rand()%3);

}
void Cell::set_timer(){
     timer->setInterval((rand()%5)*Cell::spead);
     for(auto fox=foxs.begin(); fox!=foxs.end();fox++ ){
         (*fox)->reset_timer();
     }
     for(auto hare=hares.begin(); hare!=hares.end();hare++ ){
         (*hare)->reset_timer();
     }
}
void Cell::change(){
    if(this->status==3){
        return;
    }
    if(Cell::chose==fox){
        reinterpret_cast<MainWindow*>(this->parent())->addFox(pos[0],pos[1]);
     return ;
    }
    if(Cell::chose==hare){
        reinterpret_cast<MainWindow*>(this->parent())->addHare(pos[0], pos[1]);
         return ;
    }
    if(Cell::chose!=3){
    this->set_status(Cell::chose);
    }

}
Cell::~Cell()
{
    for(auto fox=foxs.begin(); fox!=foxs.end();fox++ ){
        reinterpret_cast<MainWindow*>(this->parent())->removeItem(*fox);

    }
    for(auto hare=hares.begin(); hare!=hares.end();hare++ ){
        reinterpret_cast<MainWindow*>(this->parent())->removeItem(*hare);

    }
    if(timer!=nullptr)
    delete timer;
}

QRectF Cell::boundingRect() const
{

    return QRectF(0,0,w,w);
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    if(this->status==earth){

    painter->setBrush(Qt::yellow);
    }
    else  if(this->status==grass){
        painter->setBrush(Qt::green);
        }
    else  if(this->status==water){

        painter->setBrush(Qt::blue);
        }
    else{
          painter->setBrush(Qt::gray);
    }

    painter->drawRect(0,0,w,w);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}



void Cell::set_status(const int status, bool go){
    if(status==earth&&go){

         timer->start();
    }
    this->status=status;
     this->update();
}
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit press();

    QGraphicsItem::mousePressEvent(event);
}

