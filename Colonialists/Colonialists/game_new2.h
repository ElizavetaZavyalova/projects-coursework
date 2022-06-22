#ifndef GAME_NEW2_H
#define GAME_NEW2_H

#include <QMainWindow>

namespace Ui {
class Game_New2;
}

class Game_New2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game_New2(QWidget *parent = nullptr);
    ~Game_New2();

private:
    Ui::Game_New2 *ui;
};

#endif // GAME_NEW2_H
