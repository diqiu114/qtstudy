#include "widget.h"
#include "ui_widget.h"
#include "mycontrol.h"
#include <QDebug>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QMessageBox::information(this, "值", QString::number(this->ui->customControl->value()));
    qDebug() << "on_pushButton_clicked";
}


void Widget::on_pushButton_2_clicked()
{
    ui->customControl->setValue(50);
    qDebug() << "on_pushButton_2_clicked";
}

