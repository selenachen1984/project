#include "logininfo.h"
#include "ui_logininfo.h"

LoginInfo::LoginInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginInfo)
{
    ui->setupUi(this);

    setWindowTitle("用户信息");

    connect(ui->btnGift, SIGNAL(clicked()), this, SLOT(slotGift()));
    connect(ui->btnPlayMoney, SIGNAL(clicked()), this, SLOT(slotPlayMoney()));
    connect(ui->btnPhoneFare, SIGNAL(clicked()), this, SLOT(slotPhoneFare()));
    connect(ui->btnMoney, SIGNAL(clicked()), this, SLOT(slotMoney()));

}

LoginInfo::~LoginInfo()
{
    delete ui;
}

void LoginInfo::setUid(QString uid)
{
    //根据uid去数据库中查找用户信息, 并将信息填入到界面中
    //add function
}

//兑换礼物
void LoginInfo::slotGift()
{

}

//兑换游戏币
void LoginInfo::slotPlayMoney()
{

}

//兑换话费
void LoginInfo::slotPhoneFare()
{

}

//兑换红包
void LoginInfo::slotMoney()
{

}
