#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>

class MainWindow;
namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    int eat_delta;
    int hungry_delta;
    int thirst_delta;
    int drink_delta;
    int max;

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Settings *ui;
    friend class MainWindow;
};

#endif // SETTINGS_H
