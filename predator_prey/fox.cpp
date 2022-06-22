 #include <QString>
#include "mainwindow.h"
int Fox::eat_delta=2;
int Fox::hungry_delta=2;
int Fox::thirst_delta=2;
int Fox::drink_delta=2;
int Fox::max=200;

Fox::Fox(QObject *parent):Animal(parent)
{

    delta_hungry=Fox::hungry_delta;
    delta_thirst=Fox::thirst_delta;
    delta_drink=Fox::drink_delta;
    delta_eat=Fox::eat_delta;
    max_delta=max;


    this->set_information();
    reset_timer();

}
void Fox::change_run(){
    reinterpret_cast<MainWindow*>(this->parent())->chose_fox(this);
}
void Fox::remove(){
    reinterpret_cast<MainWindow*>(this->parent())->get_cell(pos[0],pos[1])->delete_fox(this);
}
void Fox::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(Qt::black);


    painter->setBrush(Qt::red);

    if(h>r){
        painter->drawEllipse(0.5*r,0.5*r,r,r);
    }
    else{
    painter->drawEllipse(0,0,r,r);
    }
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Fox::create_chield(){
     Fox*fox=reinterpret_cast<MainWindow*>(this->parent())->addFox(pos[0],pos[1]);
    chield_set_param(fox);
    fox->start();
     fox->set_information();

}

void Fox::set_information(){
    QString name( "Лиса<br>");
    QString neads( "Eда: "  +  QString::number(this->hungry)\
                       + "<br>Жажда: "+ QString::number(this->thirst)\
                       + "<br>");
    QString help_age=(!(this->evolution))?("Ребенок"):("Взрослый");
    QString age("Возраст: "+help_age +"<br>");
    QString generate("Поколение: "+ QString::number(this->generation)+"<br>");
    QString nead( "Трата голода: "  +  QString::number(this->delta_eat)\
                       + "<br>Трата жажды: "+ QString::number(this->delta_drink)\
                       + "<br>Скорость голода: "+QString::number(this->delta_hungry)\
                  + "<br>Скорость жажды: "+QString::number(this->delta_thirst));



     this->setToolTip(name+neads+age+generate+nead);

}
