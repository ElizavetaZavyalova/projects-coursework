#ifndef ANIMAL_H
#define ANIMAL_H


#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <random>
#include <QTime>




class Animal : public QObject, public QGraphicsItem
{
protected:

    int generation=1;
    int r=10;
    int delta_hungry=2;
    int delta_thirst=2;
    int delta_drink=2;
    int delta_eat=2;
    int hungry=40;
    int thirst=40;
    bool evolution=0;
    int max_delta=100;
    QTimer* eat=nullptr;
    QTimer* drink=nullptr;
    QTimer* height=nullptr;
    QTimer*run=nullptr;

    int pos[2]={1, 1};
    Q_OBJECT
public:

    static int h;
    static int spead;
    explicit Animal(QObject *parent = 0);
    ~Animal();
public:

    void set_pos(const int& i, const int&j){pos[0]=i; pos[1]=j;}
    void reset_timer(){
        int delta=delta_eat+delta_drink+delta_hungry+delta_thirst;
        eat->setInterval(delta_eat*Animal::spead);
        if(evolution){
          height->setInterval(30*Animal::spead);
        }
        else{
         height->setInterval(Animal::spead);}

           run->setInterval((Animal::spead)/delta);
            drink->setInterval(delta_drink*Animal::spead);

    }
    void chield_set_param(Animal*animal){
        (delta_drink<=3)?(animal->delta_drink=2*delta_drink+2):(delta_drink>=40)?(animal->delta_drink=2*delta_drink-2):(animal->delta_drink=2*delta_drink+rand()%4-2);
         (delta_eat<=3)?(animal->delta_eat=2*delta_eat+2):(delta_eat>=40)?(animal->delta_eat=2*delta_eat-2):(animal->delta_eat=2*delta_eat+rand()%4-2);
        (delta_hungry<=3)?(animal->delta_hungry=2*delta_hungry+2):(delta_hungry>=40)?(animal->delta_hungry=2*delta_hungry-2):(animal->delta_hungry=2*delta_hungry+rand()%4-2);
         (delta_thirst<=3)?(animal->delta_thirst=2*delta_thirst+2):(delta_thirst>=40)?(animal->delta_thirst=2*delta_thirst-2):(animal->delta_thirst=2*delta_thirst+rand()%4-2);
        animal->generation=(this->generation)+1;
        int delta=delta_eat+delta_drink+delta_hungry+delta_thirst;
        animal->hungry=delta;
        animal->thirst=delta;
        animal->reset_timer();

    }
    void eating(){
        hungry+=delta_eat;
        if( thirst+hungry>=max_delta&&evolution){
            thirst/=2;
            hungry/=2;
            create_chield();
        }
         this->set_information();
    }
    void drinking(){
        thirst+=delta_eat;
        if( thirst+hungry>=max_delta&&evolution){
            thirst/=20;
            hungry/=20;
            create_chield();
        }
        this->set_information();
    }
    int &get_i(){
        return pos[0];
    }
    int &get_j(){
        return pos[1];
    }

    bool get_preoryty(){

        if(hungry>=thirst){
            return 1;
        }
        return 0;
    }




signals:




public slots:
    void change_hungry();
    void change_thirst();
    void change_height();
    virtual void change_run(){

    };



protected:


    virtual void set_information(){};
    virtual void create_chield(){};
     virtual void remove(){}
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // ANIMAL_H
