#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamemanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("热血传奇");
    setFixedSize(600, 450);
    setAutoFillBackground(true);
    pixmap = QPixmap(":/images/background.jpg");

    init();

    connect(ui->btnAutoSearch, SIGNAL(clicked()), this, SLOT(slotAutoSearch()));
    connect(ui->btnManualSearch, SIGNAL(clicked()), this, SLOT(slotManualSearch()));
    connect(ui->btnOK, SIGNAL(clicked()), this, SLOT(slotOk()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setBackgroundImage()
{
    QPalette palette;

    palette.setBrush(this->backgroundRole(),
                     QBrush(pixmap.scaled(this->size(),
                     Qt::IgnoreAspectRatio,
                     Qt::SmoothTransformation)));
    setPalette(palette);

}

void MainWindow::resizeEvent(QResizeEvent *)
{
   setBackgroundImage();
}

void MainWindow::init()
{
    //一进入客户端就进行自动搜索工作
    //ui->btnManualSearch->setEnabled(false);
    ui->editDir->setEnabled(false);
    ui->btnOK->setEnabled(false);

    //slotAutoSearch();
}

void MainWindow::slotAutoSearch()
{
    bool isSearched = 1;
    QString dir="test";

    ui->editDir->setText("搜索中请稍后。。。");
    ui->btnAutoSearch->setText("停止搜索");
    //执行自动搜索功能,返回结果给isSearched
    //add function

    if (isSearched)
    {
        //搜索成功
        QMessageBox::StandardButton ret = QMessageBox::question(this, "信息",
                              QString("搜索到一个传奇客户端\n%1\n确定无误后，按【确定】.\n 按【取消】继续查找").arg(dir),
                              QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if (ret == QMessageBox::Yes)
        {
            //确定
            ui->editDir->setText(QString(dir));
            ui->btnAutoSearch->setText("自动搜索");
            ui->btnManualSearch->setEnabled(true);
            ui->btnOK->setEnabled(true);
        } else
        {
            //取消，继续调用接口查找下一个
            slotAutoSearch();
        }
    } else
    {
        //搜索失败
        ui->editDir->setText("");
        ui->btnAutoSearch->setText("自动搜索");
        ui->btnManualSearch->setEnabled(true);

        QMessageBox::warning(this,"温馨提示","未找到传奇客户端目录,您可以尝试手动搜索",QMessageBox::Ok,QMessageBox::Ok);
    }
}

void MainWindow::slotManualSearch()
{
    ui->editDir->setText("");

    QString directory =
        QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("查找传奇客户端"), QString("/")));

    if (!directory.isEmpty())
    {
        bool isConfirm = 0;
        //判断查找到的文件的正确性
        //add function

        if (isConfirm)
        {
            //目录正确
            ui->editDir->setText(directory);
            ui->btnOK->setEnabled(true);
        } else
        {
            //目录错误
            QMessageBox::warning(this,"温馨提示","您设置的客户端目录不正确",QMessageBox::Ok,QMessageBox::Ok);
        }
    }
}

void MainWindow::slotOk()
{
    if (ui->editDir->text().isEmpty())
    {
        QMessageBox::warning(this,"温馨提示","请先设置客户端目录！",QMessageBox::Ok,QMessageBox::Ok);
        return;
    }

    //将此程序放入到桌面快捷方式中
    //add function

    QMessageBox::information(this,"温馨提示","已将次程序放入到桌面快捷方式中",QMessageBox::Ok,QMessageBox::Ok);


    gamemanager *managerwindow = new gamemanager();
    this->close();
    managerwindow->init();
    managerwindow->show();
}
