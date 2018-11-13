#include "widgetnode.h"
#include "ui_widgetnode.h"

widgetNode::widgetNode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgetNode)
{
    ui->setupUi(this);
    setFixedHeight(78);
}

widgetNode::~widgetNode()
{
    delete ui;
}
