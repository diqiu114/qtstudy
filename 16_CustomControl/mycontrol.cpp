#include "mycontrol.h"
#include "ui_mycontrol.h"
#include <QSpinBox>

MyControl::MyControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyControl)
{
    ui->setupUi(this);
    // 建立两个控件的关联
    // 1.滚动滚条，计数器变化
    // 设置数值范围
    ui->horizontalSlider->setRange(0, 100);
    ui->spinBox->setRange(0,100);
    connect(ui->horizontalSlider, &QSlider::valueChanged, [=](int value) {
        ui->spinBox->setValue(value);
    });
    connect(ui->spinBox, (&QSpinBox::valueChanged), ui->horizontalSlider, &QSlider::setValue);

}

MyControl::~MyControl()
{
    delete ui;
}

void MyControl::setValue(int val)
{
    ui->horizontalSlider->setValue(val);
}

int MyControl::value()
{
    return ui->horizontalSlider->value();
}
