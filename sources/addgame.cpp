#include <QtWidgets>
#include "addgame.h"
#include "ui_addgame.h"

addgame::addgame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addgame)
{
    ui->setupUi(this);

    setWindowTitle("添加游戏");

    connect(ui->btnSearch, SIGNAL(clicked()), this, SLOT(slotSearch()));
    connect(ui->btnOK1, SIGNAL(clicked()), this, SLOT(slotOK()));
    connect(ui->btnOK2, SIGNAL(clicked()), this, SLOT(slotOK()));
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(slotCancel()));
    connect(ui->btnCancel2, SIGNAL(clicked()), this, SLOT(slotCancel()));
}

addgame::~addgame()
{
    delete ui;
}

//当默认是远程连接的时候，显示下载地址和名字
void addgame::setRemoteInfo(QString addr, QString name)
{
    ui->tabWidget->setCurrentIndex(1);
    ui->editName2->setText(name);
    ui->editAddr->setText(addr);
}

bool addgame::slotOK()
{
    if (ui->tabWidget->currentIndex() == 0)
    {
        if (ui->editName->text().isEmpty() || ui->editPath->text().isEmpty())
        {
            QMessageBox::warning(this,"温馨提示","请填入登陆服务器路径和游戏名字",QMessageBox::Ok,QMessageBox::Ok);
            return 0;
        }
    } else
    {
        if (ui->editName2->text().isEmpty() || ui->editAddr->text().isEmpty())
        {
            QMessageBox::warning(this,"温馨提示","请填入登陆服务器下载地址和游戏名字",QMessageBox::Ok,QMessageBox::Ok);
            return 0;
        }
    }
    accept();
    return 1;
}

bool addgame::slotCancel()
{
    reject();
    return 0;
}

void addgame::slotSearch()
{
    QString directory =
        QDir::toNativeSeparators(QFileDialog::getOpenFileName(this, tr("查找登陆器"), QString("/")));

    if(!directory.isEmpty())
    {
        ui->editPath->setText(directory);
        ui->editName->setText(directory);
    }
}
