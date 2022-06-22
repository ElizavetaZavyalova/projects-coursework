#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QVector>
#include <cell.h>
#include <QMultiMap>
#include "settings.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{    Settings settings;
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
void createField();
Cell*get_cell(const int&i,const int&j ){return cells[i][j];}
Hare* addHare(const int&i,const int&j);
Fox* addFox(const int&i,const int&j);
void reset_fox(Cell*cell, Fox*fox);
 void reset_hare(Cell*cell,Hare*hare);
void removeItem( QGraphicsItem*item);
void chose_hare(Hare*hare);
void chose_fox(Fox*fox);
bool preority_fox(Cell* cell_drink,Cell* cell_eat, Hare*hare, Fox*fox);
bool preority_hare(Cell* cell_drink,Cell* cell_eat, Hare*hare);
private:
    Ui::MainWindow  *ui;

    QGraphicsScene  *scene;
    QVector<QVector<Cell*>> cells;


private slots:



    void on_Earth_triggered();
    void on_Grass_triggered();
    void on_Hare_triggered();
    void on_Fox_triggered();

    void on_Water_triggered();
    void on_Start_triggered();

    void on_Stop_triggered();
    void on_Fox_settings_triggered();
    void on_Hare_settings_triggered();

};

#endif // MAINWINDOW\_H
