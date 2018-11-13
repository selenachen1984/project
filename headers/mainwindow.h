#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void slotAutoSearch();
    void slotManualSearch();
    void slotOk();

private:
    Ui::MainWindow *ui;
    QPixmap pixmap;
    void setBackgroundImage();
    void init();

};

#endif // MAINWINDOW_H
