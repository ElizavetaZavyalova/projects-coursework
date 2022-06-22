#include "QLabel"
#include "QPainter"
#include <QGraphicsItem>
class Paint_Hex;
#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H
class Town;
class Hex;
class Road;
class Player;
class Cards;
class Game_New;
class Ship;
class trader;


class Cards{
   int r=-1;
  char points[25];
public:
  Cards();
  friend Player;
  friend Game_New;
  char give(Player &play);



};

class Hex
{
   char zone;
   double x;
    double y; 
   double peek[6][2];
   int number[2];
   QLabel *label=nullptr;
   Town* town[6];
public:
     Hex();
      ~Hex();
    void cordinates(double x, double y,double X, double Y);
    void cordinates_peek(double R);
    void distrubute();

    void town_new(Town& town1);

    void fief_it(Player&play);
    bool is_hex(double x, double y, double R);
    friend Game_New;
};
class Road
{  Town* left;
    Town* right;
    Player* player;
   double x1;
   double x2;
   double y1;
   double y2;
   char color='n';
public:
   friend Town;
   friend Player;
   friend Game_New;
   void cordinates(double R);
   int private_road(Player& player);
   bool can_create(Player& player);
   bool is_road(double x, double y, double R);
//   friend QDataStream& operator<<(QDataStream& stream, const Road& obj);
//   friend QDataStream& operator>>(QDataStream& stream, Road& obj);

    Road();

};

class Player
{
    QString name;
    char color;
    int clay;
    int wood;
    int stone;
    int millet;
    int wool;
    int monopoly;
    int ivent;
    int new_road;
    int road_new=0;
    int knight;
    int points;
    int road;
    int army;
    int vilage;
    int sity;
    int cards;
    bool the_bigest_roud=0;
    bool the_bigest_army=0;
    bool bot=0;
public:
    friend Town;
    friend Hex;
    friend Road;
    friend Cards;
    friend Game_New;
    friend trader;
    void  set_init(char c, QString name);
    Player();
    void bot_init();
    char not7();
//    friend QDataStream& operator<<(QDataStream& stream, const Player& obj);
//    friend QDataStream& operator>>(QDataStream& stream, Player& obj);


   // ~Player();
};

class Town
{   QLabel *label=nullptr;
    Road* right;
    Road* left;
    Road* central;
    Player* player;
    int town;
    char color='n';
    double x;
    double y;
public:
     ~Town();
    Town();
    friend Road;
    friend Player;
    friend Hex;
    friend Game_New;
    friend Ship;
    friend Cards;
    void cordinates(double x, double y);

    bool road_create(Town& town1, Road &road, double R);

    int private_town(Player &player);
    int modify_town(Player &player);
    bool can_create(const Player& player);
    bool is_number(double x, double y, double R);
//    friend QDataStream& operator<<(QDataStream& stream, const Town& obj);
//    friend QDataStream& operator>>(QDataStream& stream, Town& obj);

};
#endif // GAME_OBJECTS_H

