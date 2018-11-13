#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QWidget>
#include <QBitmap>
namespace Ui {
class gamemanager;
}

class gamemanager : public QWidget
{
    Q_OBJECT

public:
    explicit gamemanager(QWidget *parent = nullptr);
    ~gamemanager();

    void init();
private slots:
    void slotLoginInfo();
    void slotAddGames();
    void slotDelGames();

private:
    Ui::gamemanager *ui;
    bool isLogin;
    QString uid; //登陆者的标识信息

    void displayLoginInfo();
    void displayGames();
    void clearList();
};

#endif // GAMEMANAGER_H
