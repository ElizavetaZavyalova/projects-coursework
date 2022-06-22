#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include <QGraphicsScene>
#include "settings.h"
//#include "scena.h"
#include "dialog.h"
#include "game_new.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{   // Game* game;
    Q_OBJECT
    Settings setings;
    Dialog dil;
    Game_New *game=nullptr;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_settings_clicked();

    void on_author_clicked();

    void on_exit_clicked();

   // void on_rules_released();

    void on_new_game_clicked();

    void on_rules_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H




