#ifndef TRADER_AND_HELP_H
#define TRADER_AND_HELP_H
#include <QGraphicsItem>
#include <QLabel>
#include <QPushButton>
#include "game_objects.h"
class Game_New;
class Ship{
    Town* town[2];
    QLabel* label=nullptr;
public:
    void set_Town(Town&town2, Town&town1);
    bool is_ship(Player&play);
    friend Game_New;
    ~Ship();
};
typedef enum doing{
    fief1=0, to21=1, to31=2, to41=3, start=4, new_roud=5, my_knits=6, monopoly=7, ivent=8, clear=9

}doing;

typedef enum play_information{
    clay=0, tree=1, millet=2, stown=3, wool=4, knits=5, cards=6, sity=7, vilage=8, roud=9, points=10
}play_information;


class trader{
    QPushButton* tradeplayer[2];
    QLabel* trade[5];
    QLabel* trading;
    QLabel* cost;
    int trade_res[5];
    friend Game_New;
public:
    bool is_to21(int x, int y);
    bool is_to31(int x, int y);
    bool is_to41(int x, int y);
    bool to_21(Player &Play);
     bool to_31(Player &Play);
      bool to_41(Player &Play);
      ~trader();
};

#endif // TRADER_AND_HELP_H

