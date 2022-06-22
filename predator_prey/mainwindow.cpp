#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    scene = new QGraphicsScene();



   ui->graphicsView->setGeometry(5,60,800,800);
    ui->graphicsView->resize(800,800);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,800,800);

    scene->setSceneRect(0,0,800,800);
    QGraphicsRectItem *rect = new QGraphicsRectItem();
    rect->setPen(QPen(Qt::red));
    rect->setRect(scene->sceneRect());
    scene->addItem(rect);
    createField();

}


bool MainWindow::preority_hare(Cell* cell_drink,Cell* cell_eat, Hare*hare){
    if(cell_drink==nullptr&&cell_eat==nullptr)
        return 0;
    if(hare->get_preoryty()){
        if(cell_eat!=nullptr){
           reset_hare(cell_eat,hare);
            hare->eating();
            cell_eat->set_status(0);
            return 1;
        }
        else{
             reset_hare(cell_drink,hare);
              hare->drinking();
               cell_drink->set_status(0);
            return 1;
        }
    }
        if(cell_drink!=nullptr){
             reset_hare(cell_drink,hare);
              hare->drinking();
              cell_drink->set_status(0);
            return 1;
        }
        else{
            reset_hare(cell_eat,hare);
              hare->eating();
              cell_eat->set_status(0);
            return 1;}
}

void MainWindow::chose_hare(Hare*hare){
    int x=hare->get_i();
    int y=hare->get_j();
    bool danger=0;
    Cell* cell_drink=nullptr;
    Cell* cell_eat=nullptr;
    Cell* cell_earth=nullptr;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i!=0||j!=0){
            Cell* cell=cells[((x+i)%((800)/Cell::w-1)+1)][((y+j)%((800)/Cell::w-1)+1)];
            if(cell->get_fox()!=nullptr){
                danger=1;

                if(preority_hare(cell_drink, cell_eat, hare)){
                     scene->update();
                    return ;
                }
                else {
                    if(cell_earth!=nullptr){
                         reset_hare(cell_earth,hare);
                          scene->update();
                         return;
                    }

                }
                  continue;

            }
           else  if(danger){
               reset_hare(cell,hare);
                  scene->update();
                 return;
            }
            if(cell->get_status()==1){
                cell_drink=cell;
            }
            else if(cell->get_status()==2){
                cell_eat=cell;
            }
            else if(cell->get_status()==0){
                cell_earth=cell;
            }
            }
        }
        }
    if(preority_hare(cell_drink, cell_eat, hare)){
         scene->update();
        return ;
    }
    if(cell_earth!=nullptr){
         reset_hare(cell_earth,hare);
          scene->update();
         return;
    }

    }

void MainWindow::reset_fox(Cell*cell, Fox*fox){
    cells[fox->get_i()][fox->get_j()]->delete_fox(fox);
    fox->set_pos(cell->get_x(), cell->get_y());
     cells[fox->get_i()][fox->get_j()]->set_fox(fox);
    fox->setPos(Cell::w*cell->get_x(),Cell::w*cell->get_y());
}
void MainWindow::reset_hare(Cell*cell,Hare*hare){
    cells[hare->get_i()][hare->get_j()]->delete_hare(hare);
   hare->set_pos(cell->get_x(), cell->get_y());
    cells[hare->get_i()][hare->get_j()]->set_hare(hare);
    hare->setPos(Cell::w*cell->get_x(),Cell::w*cell->get_y());

}
bool MainWindow::preority_fox(Cell* cell_drink,Cell* cell_eat, Hare*hare, Fox*fox){
    if(cell_drink==nullptr&&cell_eat==nullptr)
        return 0;
    if(fox->get_preoryty()){
        if(cell_eat!=nullptr){
             reset_fox(cell_eat,fox);
            if(cells[cell_eat->get_x()][cell_eat->get_y()]->delete_hare(hare)){
                fox->eating();
                   this->removeItem(hare);
            }


            return 1;
        }
        else{
           reset_fox(cell_drink,fox);
              fox->drinking();
               cell_drink->set_status(0);
            return 1;
        }
    }
        if(cell_drink!=nullptr){
            reset_fox(cell_drink,fox);
              fox->drinking();
              cell_drink->set_status(0);
            return 1;
        }
        else{
            reset_fox(cell_eat,fox);
            if(cells[cell_eat->get_x()][cell_eat->get_y()]->delete_hare(hare)){
                fox->eating();
                   this->removeItem(hare);
            }

            return 1;}
}

void MainWindow::chose_fox(Fox *fox){
    int x=fox->get_i();
    int y=fox->get_j();
    Cell* cell_drink=nullptr;
    Cell* cell_eat=nullptr;
    Cell* cell_earth=nullptr;
    Hare* hare= nullptr;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i!=0||j!=0){
            Cell* cell=cells[((x+i)%((800)/Cell::w-1)+1)][((y+j)%((800)/Cell::w-1)+1)];

            Hare* eating=cell->get_hare();
            if(eating!=nullptr){
                 hare=eating;
                cell_eat=cell;
            }
            if(cell->get_status()==1){
                cell_drink=cell;
            }
            else if(cell->get_status()<3){
               cell_earth=cell;
            }
            }
        }
        }
    if(!preority_fox(cell_drink,cell_eat,hare, fox)){
        reset_fox(cell_earth,fox);
    }

    scene->update();
    }


MainWindow::~MainWindow()
{
    for(auto row=cells.begin(); row!=cells.end(); row++){
        for(auto cell=row->begin(); cell!=row->end(); cell++){
                removeItem(*cell);


     }

    }
    delete ui;
}


void MainWindow::on_Water_triggered(){
    Cell::chose=1;
}
void MainWindow::on_Earth_triggered()
{
    Cell::chose=0;
}

void MainWindow::on_Grass_triggered()
{
    Cell::chose=2;
}

void MainWindow::on_Hare_triggered()
{
    Cell::chose=5;
}

void MainWindow::on_Fox_triggered()
{
    Cell::chose=4;
}

void MainWindow::createField(){


 int count= (800)/Cell::w;


 int w1=0,h1=0;
 for(int i=0;i<count;i++){
     QVector<Cell*> row;
     for(int j=0; j<count; j++){

          Cell* cell=new Cell(this);
          cell->set_pos(i,j);

         if(i==0||j==0||i==count-1||j==count-1){
              cell->set_status(3,0);
         }
         else{
            cell->set_status(rand()%3, 0);
         }
         row.push_back(cell);

        cell->setPos(w1,h1);
       scene->addItem(cell);
       h1+=Cell::w;
     }
      h1=0;
       w1+=Cell::w;
    this->cells.push_back(row);

 }

 }
void MainWindow::removeItem( QGraphicsItem*item){
    scene->removeItem(item);
    delete item;
}
Hare* MainWindow::addHare(const int&i,const int&j){
    Hare* animal=new Hare(this);
    animal->set_pos(i,j);
  animal->setPos(Cell::w*i,Cell::w*j);
  scene->addItem(animal);
  scene->update();

    cells[i][j]->set_hare(animal);
    return animal;
}
Fox* MainWindow::addFox(const int&i,const int&j){
    Fox* animal=new Fox(this);
    animal->set_pos(i,j);
  animal->setPos(Cell::w*i,Cell::w*j);
  scene->addItem(animal);
  scene->update();
    cells[i][j]->set_fox(animal);

  return animal;
}






void MainWindow::on_Start_triggered()
{
    for(auto row=cells.begin(); row!=cells.end(); row++){
        for(auto cell=row->begin(); cell!=row->end(); cell++){
            (*cell)->start();

        }
    }

}



void MainWindow::on_Stop_triggered()
{


    for(auto row=cells.begin(); row!=cells.end(); row++){
        for(auto cell=row->begin(); cell!=row->end(); cell++){
            (*cell)->stop();

        }
    }

}

void MainWindow::on_Fox_settings_triggered()
{
    settings.exec();
    Fox::eat_delta=(this->settings).eat_delta;
    Fox::hungry_delta=(this->settings).hungry_delta;
    Fox::thirst_delta=(this->settings).thirst_delta;
    Fox::drink_delta=(this->settings).drink_delta;
     Fox::max=(this->settings).max;

}

void MainWindow::on_Hare_settings_triggered()
{
    settings.exec();
    Hare::eat_delta=(this->settings).eat_delta;
    Hare::hungry_delta=(this->settings).hungry_delta;
    Hare::thirst_delta=(this->settings).thirst_delta;
    Hare::drink_delta=(this->settings).drink_delta;
    Hare::max=(this->settings).max;
}








