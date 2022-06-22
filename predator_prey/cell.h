#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <random>
#include <QTime>
#include <fox.h>
#include <hare.h>



class Cell : public QObject, public QGraphicsItem
{   enum Status{ earth=0,water=1,grass=2, end=3, fox=4, hare=5};
    int status=earth;
    QTimer* timer=nullptr;
    int pos[2]={1, 1};
    QList<Hare*> hares;
    QList<Fox*> foxs;
    Q_OBJECT
public:
    explicit Cell(QObject *parent = 0);
    ~Cell();
public:

    static int w;
    static int chose;
    static int spead;
    void set_timer();
    bool delete_fox(Fox*animal){
        for(auto fox=foxs.begin(); fox!=foxs.end();fox++ ){
            if((*fox)==animal){
               (*fox)=*(--foxs.end());
               foxs.pop_back();
                return 1;
            }
        }
        return 0;
    }
    bool delete_hare(Hare*animal){
        for(auto hare=hares.begin(); hare!=hares.end();hare++ ){
            if((*hare)==animal){
                (*hare)=*(--hares.end());
                hares.pop_back();
                return 1;
            }
        }
        return 0;
    }
    void set_fox(Fox*fox){
        foxs.push_back(fox);
    }
    void set_hare(Hare*hare){
        hares.push_back(hare);
    }
    Fox* get_fox(Fox*animal=nullptr){
         if(animal==nullptr&&foxs.begin()!=foxs.end()){
             return (*foxs.begin());
         }
         else if(animal!=nullptr){
             for(auto fox=foxs.begin(); fox!=foxs.end();fox++ ){
                 if((*fox)==animal){
                     return (*fox);
                 }
             }
         }
         return nullptr;
    }
    Hare* get_hare(Hare*animal=nullptr){
         if(animal==nullptr&&hares.begin()!=hares.end()){
             return (*hares.begin());
         }
         else if(animal!=nullptr){
             for(auto hare=hares.begin(); hare!=hares.end();hare++ ){
                 if((*hare)==animal){
                     return (*hare);
                 }
             }
         }
         return nullptr;
    }
    int get_x(){return pos[0];}
     int get_y(){
         return pos[1];}
    int&get_status(){return status;}
    void set_status(const int status, bool go=1);

    void set_pos(const int&i, const int&j){
        pos[0]=i;
        pos[1]=j;
    }
    void start(){
        if(status==earth){
            timer->start();
        }
        for(auto fox=foxs.begin(); fox!=foxs.end();fox++ ){

            (*fox)->start();
        }
        for(auto hare=hares.begin(); hare!=hares.end();hare++ ){

            (*hare)->start();
        }
    }
    void stop(){

            timer->stop();

        for(auto fox=foxs.begin(); fox!=foxs.end();fox++ ){

            (*fox)->stop();
        }
        for(auto hare=hares.begin(); hare!=hares.end();hare++ ){

            (*hare)->stop();
        }
    }


signals:

    void press();
    void status_earch();

public slots:
    void change();
    void complete();

protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CELL_H
