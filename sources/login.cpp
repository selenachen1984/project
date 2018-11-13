#include "login.h"
#include "ui_login.h"
#include "QZXing.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    setWindowTitle("登陆");
    //ui->label_2->setPixmap(QPixmap(":/images/code2.png"));

}

login::~login()
{
    delete ui;
}
