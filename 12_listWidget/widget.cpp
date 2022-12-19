#include "widget.h"
#include "ui_widget.h"
#include <QListWidget>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 向listWidegt里边添加内容
//    QListWidgetItem *item = new QListWidgetItem("疑是地上霜");
//    item->setTextAlignment(Qt::AlignHCenter);
//    ui->listWidget->addItem(item);
//    ui->listWidget->addItem("疑是地上霜");
    QStringList list;
    list << "窗前明月光" << "疑是地上霜" << "举头望明月" << "低头思故乡";
    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}

