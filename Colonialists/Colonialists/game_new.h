#ifndef GAME_NEW_H
#define GAME_NEW_H

#include <QMainWindow>
#include "game_objects.h"
#include "mainwindow.h"
#include <QGraphicsScene>
#include "trader_and_help.h"
#include <QPixmap>
#include <QGridLayout>
namespace Ui {
class Game_New;
}

class Game_New : public QMainWindow
{

    Q_OBJECT
    bool action[11];
    QLabel* dice[2];
    trader trading;
    QLabel* fief;
    Ship ship[9];
    Hex hex[19];
    Road road[72];
    Town town[54];
    Cards cards;
    double X;
    double Y;
    double R;
    Player* player;
    int point;
    int num;
    int now=0;
public:
    explicit Game_New(QWidget *parent = nullptr);
    ~Game_New();

    //Функции проверки на самое большое
    void the_bigest_army();
    void the_bigest_road();
    //Вспомогательная функция для тарифов
    void to21_show();
    //Инициализация игры
    void init_all();

    void game_init();
    void road_create();
    void hex_number();
    void hex_connect(int i, int q, int z, int e, int d);  
    void start_game();
    void Ship_init();
    void hex_init();
    void create_trade();
    void Start_init(double x, double y);
    void buttons_create();
    //Изменение панели инструментов
     void infromation_tool();
    //Функции рисования
    void hex_paintEvent();
    void road_paintEvent();
    void number_paintEvent();


    //Функции строительства
    void town_label(int i);
    bool town_init(int i);
    void road_init(int i);
    //Функция передвижения разбойника
    void fief_move(int i);
    void fiefmove(double x, double y);
    //функции торговли
    void tradeto21(double x, double y);
    void tradeto31(double x, double y);
    void tradeto41(double x, double y);
    //Функции карт развития
    void monopoly_do(int res);
    void ivent_do(int res);
    void new_roud_do(double x, double y);
    //Функция броска кубиков
    void on_dice_clicked();
     //Функции игры ии
    void if_it_is_bot();
    void start_bot();
    void play_bot();
    bool play_bot_trade();


private slots://Отвечают за торговлю. правая toolbar
    void on_clay_triggered();
    void on_millet_triggered();
    void on_tree_triggered();
    void on_stown_triggered();
    void on_wool_triggered();
    void on_to41_triggered();
    void on_to31_triggered();
    void end_trade();
    void trade();
    //Отвечают за карточки. Нижняя toolbar
    void on_map_triggered();     
    void on_monopoly_triggered();
    void on_new_roud_triggered();
    void on_ivent_triggered();
    void on_knit_triggered();
 //Резерв левая toolbar  нужны в торговле
    void on_millet_2_triggered();
    void on_wool_2_triggered();
    void on_tree_2_triggered();
    void on_clay_2_triggered();
    void on_stown_2_triggered();
  //Верхняя toolbar
    void on_exit_triggered();
 //Иные слоты
    void paintEvent(QPaintEvent* pe);
    void mousePressEvent(QMouseEvent* me);
     friend class MainWindow;




     void on_ruls_triggered();

private:
Ui::Game_New *ui;

};

#endif // GAME_NEW_H
