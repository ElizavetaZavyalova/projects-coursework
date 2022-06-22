#include "animal.h"
#include "mainwindow.h"


int Animal::h=20;
int Animal::spead=1000;




Animal::Animal(QObject *parent)
    : QObject(parent), QGraphicsItem()
{



     eat = new QTimer(this);

        connect(eat, SIGNAL(timeout()), this, SLOT(change_hungry()));
       drink = new QTimer(this);

           connect(drink, SIGNAL(timeout()), this, SLOT(change_thirst()));
            height=new QTimer(this);
              connect(height, SIGNAL(timeout()), this, SLOT(change_height()));
              run = new QTimer(this);
                 connect(run, SIGNAL(timeout()), this, SLOT(change_run()));





}



void Animal::change_height(){
    height->stop();
    if(!evolution){
     r*=2;
     delta_hungry/=2;
     delta_thirst/=2;
     delta_drink/=2;
     delta_eat/=2;
      evolution=1;

       this->set_information();
          height->start();
          reset_timer();
    }
    else{
        this->remove();
        reinterpret_cast<MainWindow*>(this->parent())->removeItem(this);

    }


}

void Animal::change_hungry(){
    hungry-=delta_hungry;
     this->set_information();
    if(hungry<=0){
          this->remove();
       reinterpret_cast<MainWindow*>(this->parent())->removeItem(this);

    }
}
void Animal::change_thirst(){
    thirst-=delta_thirst;
     this->set_information();
    if(thirst<=0){
        this->remove();
     reinterpret_cast<MainWindow*>(this->parent())->removeItem(this);

    }

}

Animal::~Animal()
{
    delete eat;
    delete drink;
    delete height;
    delete run;
}

QRectF Animal::boundingRect() const
{

    return QRectF(0,0,r,r);
}

void Animal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);

    painter->setBrush(Qt::red);

    painter->drawEllipse(0,0,r,r);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}




