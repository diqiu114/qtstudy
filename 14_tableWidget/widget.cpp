#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置行数
    ui->tableWidget->setRowCount(5);
    ui->tableWidget->setColumnCount(3);
    // 设置标题
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "英雄" << "性别" << "年龄");
    QStringList hroNames = QStringList() << "亚瑟" << "妲己"<< "安其拉"<< "赵云"<< "孙悟空";
    QStringList hroGenders = QStringList() << "男" << "男"<< "男"<< "男"<< "男";
    for(int cnt = 0; cnt < 5; cnt++) {
        ui->tableWidget->setItem(cnt, 0, new QTableWidgetItem(hroNames[cnt]));
        ui->tableWidget->setItem(cnt, 1, new QTableWidgetItem(hroGenders[cnt]));
        ui->tableWidget->setItem(cnt, 2, new QTableWidgetItem(QString::number(cnt + 18)));
    }
}

Widget::~Widget()
{
    delete ui;
}

