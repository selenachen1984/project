#include <QtWidgets>
#include "gamemanager.h"
#include "ui_gamemanager.h"
#include "login.h"
#include "logininfo.h"
#include "addgame.h"
#include "widgetnode.h"
gamemanager::gamemanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamemanager)
{
    ui->setupUi(this);
   // setFixedSize(1024, 620);

    isLogin = false;

   // QHBoxLayout *hlayout = new QHBoxLayout();

    ui->verticalLayout_3->setMargin(0);
    ui->verticalLayout_3->setSpacing(0);
    ui->horizontalLayout->setMargin(0);
    ui->verticalLayout->setMargin(0);
    ui->verticalLayout->setSpacing(0);
    ui->verticalLayout_2->setMargin(0);
    ui->verticalLayout_2->setSpacing(0);

    connect(ui->btnHead, SIGNAL(clicked()), this, SLOT(slotLoginInfo()));
    connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(slotAddGames()));
    connect(ui->btnDel, SIGNAL(clicked()), this, SLOT(slotDelGames()));


}

gamemanager::~gamemanager()
{
    delete ui;
}

void gamemanager::init()
{
   // ui->lbSearch->setGeometry(ui->editSearch->geometry());
}

void gamemanager::displayLoginInfo()
{
    QString name="Test"; //登陆者名称
    int gametimes = 0; //游戏次数
    //根据uid查询数据库获取登陆者信息
    //add function

    ui->lbName->setText(name);
    ui->lbID->setText(uid);
    ui->lbTimes->setText(QString(gametimes));

    LoginInfo *logwin = new LoginInfo();
    logwin->setUid(uid);
    logwin->exec();
}

void gamemanager::slotLoginInfo()
{
    if (!isLogin)
    {
        //未登陆，显示登陆界面
        login *loginWindow = new login();
        isLogin = loginWindow->exec();

        //获取登陆者的uid
        //add function
        isLogin = true;
    }
    if (isLogin)
    {
        //已登陆，显示登陆者信息, 并更新游戏列表
        displayLoginInfo();
    }
}

void gamemanager::slotAddGames()
{
    addgame *addWindow = new addgame(this);
    int ret = addWindow->exec();

    if (ret == QDialog::Accepted)
    {
        //加入下载任务,更新“我的游戏”里面的列表
        displayGames();
    }
}

void gamemanager::slotDelGames()
{

}

void gamemanager::clearList()
{
    ui->leftMiddMenu->clear();
}

void gamemanager::displayGames()
{
    clearList();

    //查询数据库，获取最新列表,每一条记录增加一个结点
    //add function

    //test
    int i = 0;
    for (i=0; i < 5; i++)
    {
        widgetNode *node = new widgetNode(this);

        QListWidgetItem *item = new QListWidgetItem(ui->leftMiddMenu);

        ui->leftMiddMenu->setItemWidget(item, node);
    }
}
