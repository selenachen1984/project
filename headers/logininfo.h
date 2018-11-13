#ifndef LOGININFO_H
#define LOGININFO_H

#include <QDialog>

namespace Ui {
class LoginInfo;
}

class LoginInfo : public QDialog
{
    Q_OBJECT

public:
    explicit LoginInfo(QWidget *parent = nullptr);
    ~LoginInfo();

    void setUid(QString uid);

private slots:
    void slotGift();
    void slotPlayMoney();
    void slotPhoneFare();
    void slotMoney();

private:
    Ui::LoginInfo *ui;
    QString uid;
};

#endif // LOGININFO_H
