 #include "mainwindow.h"
int Hare::eat_delta=2;
int Hare::hungry_delta=2;
int Hare::thirst_delta=2;
int Hare::drink_delta=2;
int Hare::max=100;

Hare::Hare(QObject *parent):Animal(parent)
{

    delta_hungry=Fox::hungry_delta;
    delta_thirst=Fox::thirst_delta;
    delta_drink=Fox::drink_delta;
    delta_eat=Fox::eat_delta;
    max_delta=max;
     this->set_information();
    reset_timer();
}

void Hare::remove(){
    reinterpret_cast<MainWindow*>(this->parent())->get_cell(pos[0],pos[1])->delete_hare(this);
}
void Hare::change_run(){

reinterpret_cast<MainWindow*>(this->parent())->chose_hare(this);
}

void Hare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);


    painter->setBrush(Qt::white);

    if(h>r){
        painter->drawEllipse(0.5*r,0.5*r,r,r);
    }
    else{
    painter->drawEllipse(0,0,r,r);
    }
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
void Hare::create_chield(){
    Hare* hare= reinterpret_cast<MainWindow*>(this->parent())->addHare(pos[0],pos[1]);

    chield_set_param(hare);
    hare->start();
    hare->set_information();

}


void Hare::set_information(){
    QString name( "Заяц<br>");
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

     this->setToolTip(name+neads+age+generate);


}
