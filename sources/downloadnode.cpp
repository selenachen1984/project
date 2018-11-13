#include "downloadnode.h"
#include "ui_downloadnode.h"

downloadnode::downloadnode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::downloadnode)
{
    ui->setupUi(this);
}

downloadnode::~downloadnode()
{
    delete ui;
}
