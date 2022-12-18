#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 创建按钮
    QPushButton* Bnt1 = new QPushButton("按钮1", this);
    // 关闭按钮
    // 1 建立关系 被点击-》关闭

    connect(Bnt1, &QPushButton::clicked,this,&Widget::close);
//    connect(Bnt1, &QPushButton::clicked,this,&Widget::showMaximized);
}

Widget::~Widget()
{
    delete ui;
}

