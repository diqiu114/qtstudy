#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 1.设置标题
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "简介");
    // 2.添加根节点
    QTreeWidgetItem *PwrItem = new QTreeWidgetItem(QStringList() << "力量");
    QTreeWidgetItem *minjieItem = new QTreeWidgetItem(QStringList() << "敏捷");
    QTreeWidgetItem *zhiliItem = new QTreeWidgetItem(QStringList() << "智力");

    // 添加子节点
    PwrItem->addChild(new QTreeWidgetItem(QStringList() << "刚背猪" << "前排坦克"));

    ui->treeWidget->addTopLevelItem(PwrItem);
    ui->treeWidget->addTopLevelItem(minjieItem);
    ui->treeWidget->addTopLevelItem(zhiliItem);
}

Widget::~Widget()
{
    delete ui;
}

