#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include <QTimer>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *event)
{
    static int num1;
    static int num2;
    if(event->timerId()==this->mTimeId1) {
        num1++;
        ui->lcdNumber->display(num1);
    }
    if(event->timerId()==this->mTimeId2) {
        num2++;
        ui->lcdNumber_2->display(num2);
    }

}


void Widget::on_pushButton_clicked()
{
    if(!this->mTimeId1) {
        killTimer(this->mTimeId1);
    }
    this->mTimeId1 = startTimer(1000);
}


void Widget::on_pushButton_2_clicked()
{
    // 停止定时器
    killTimer(this->mTimeId1);
}


void Widget::on_pushButton_3_clicked()
{
    if(!this->mTimeId2) {
        killTimer(this->mTimeId2);
    }
    this->mTimeId2 = startTimer(100);
}


void Widget::on_pushButton_4_clicked()
{
    killTimer(this->mTimeId2);
}


void Widget::on_pushButton_5_clicked()
{
    connect(timer, &QTimer::timeout, [=]() {
       static int num;
       num++;
       ui->lcdNumber_3->display(num);
    });
    timer->start(10);
}

void Widget::on_pushButton_6_clicked()
{
    timer->stop();
}

