#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <QWidget>

namespace Ui {
class New_Game;
}

class New_Game : public QWidget
{
    Q_OBJECT

public:
    explicit New_Game(QWidget *parent = nullptr);
    ~New_Game();

private:
    Ui::New_Game *ui;
};

#endif // NEW_GAME_H
