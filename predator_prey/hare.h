#ifndef HARE_H
#define HARE_H
#include "animal.h"




class Hare:public Animal
{

public:
    Hare(QObject *parent);
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
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)override;
     void set_information() override;
     void create_chield()override;
     void remove()override;
signals:
     public slots:
   void change_run()override ;
     ~Hare(){};
};

#endif // HARE_H
