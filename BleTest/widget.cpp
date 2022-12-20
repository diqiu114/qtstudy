#include "widget.h"
#include "ui_widget.h"
#include "bluedevice.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    BlueDevice *Ble = new BlueDevice();
}

Widget::~Widget()
{
    delete ui;
}

