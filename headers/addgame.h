#ifndef ADDGAME_H
#define ADDGAME_H

#include <QDialog>
#include <QDir>
#include <QFileDialog>

namespace Ui {
class addgame;
}

class addgame : public QDialog
{
    Q_OBJECT

public:
    explicit addgame(QWidget *parent = nullptr);
    ~addgame();
    void setRemoteInfo(QString addr, QString name);

private slots:
    bool slotOK();
    bool slotCancel();
    void slotSearch();
private:
    Ui::addgame *ui;
};

#endif // ADDGAME_H
