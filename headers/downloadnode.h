#ifndef DOWNLOADNODE_H
#define DOWNLOADNODE_H

#include <QWidget>

namespace Ui {
class downloadnode;
}

class downloadnode : public QWidget
{
    Q_OBJECT

public:
    explicit downloadnode(QWidget *parent = nullptr);
    ~downloadnode();

private:
    Ui::downloadnode *ui;
};

#endif // DOWNLOADNODE_H
