#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QMainWindow>
#include "game_objects.h"
class MainWindow;

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Player*player;
    int point;
    int num;

    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    void return_mas();
    friend class MainWindow;
    ~Settings();
private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
