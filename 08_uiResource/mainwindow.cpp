#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // ui的初始化
    ui->setupUi(this);
    // 向状态栏添加信息
    ui->statusbar->addWidget(new QLabel("左侧信息",this));
    // 使用图片资源
    /*
     * 1.使用绝对路径
    */
//    ui->actionnew->setIcon(QIcon("E:\\Desktop\\CodeLIb\\qt\\QTSTUDY\\picture\\ship.png"));
    // 2.使用资源文件
    // 使用资源文件的路径
    // 冒号：+前缀 / + 目录文件名
    ui->actionnew->setIcon(QIcon(":/Image/ship.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

