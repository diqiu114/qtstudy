#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <mypushbutton.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 局部变量，在函数退出时会自动free
    // 延长周期
    // 1 static
    // 2 类成员变量
    // 3 new
    QPushButton *Bnt1 = new QPushButton("Bnt1", this);
    // 没有delete，但是窗口不用释放
    MyPushButton *Bnt2 = new MyPushButton(this);
    Bnt2->setText("按钮2");
}

Widget::~Widget()
{
    delete ui;
}

