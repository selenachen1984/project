#ifndef WIDGETNODE_H
#define WIDGETNODE_H

#include <QWidget>

namespace Ui {
class widgetNode;
}

class widgetNode : public QWidget
{
    Q_OBJECT

public:
    explicit widgetNode(QWidget *parent = nullptr);
    ~widgetNode();

private:
    Ui::widgetNode *ui;
};

#endif // WIDGETNODE_H
