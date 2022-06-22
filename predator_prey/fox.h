#ifndef FOX_H
#define FOX_H
#include "animal.h"


class Fox: public Animal
{
public:
    Fox(QObject *parent) ;
    ~Fox(){};
static int max;
static int eat_delta;
static int hungry_delta;
static int thirst_delta;
static int drink_delta;
void start(){
    eat->start();
    drink->start();
    height->start();
    run->start();
}
void stop(){
    eat->stop();
    drink->stop();
    height->stop();
    run->stop();
}
private:
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
     void set_information() override;
     void create_chield() override;
     void remove()override;
signals:
     public slots:
     void change_run()override ;


};

#endif // FOX_H
