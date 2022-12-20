#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 使用label播放gif
    QMovie *movie = new QMovie(":/down-arrow.gif", QByteArray(), this);
    ui->label_2->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Widget::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

