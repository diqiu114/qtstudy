#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionmodal, &QAction::triggered, [=](){
        // 创建一个模态对话框
        QDialog dlg(this);
        dlg.exec(); // 消息循环
        qDebug() << "hello dialog";
    });
    // triggered:按下抬起的动作
    connect(ui->actionNonModel, &QAction::triggered, [=](){
        // show非阻塞，dlg会释放，改用new的方式
        QDialog *dlg = new QDialog(this);
        // 通过设置窗口的属性，关闭的时候自动释放内存，否则一直申请内存
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        dlg->show(); // 非阻塞，一闪而过
        qDebug() << "hello actionNonModel";
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionWarning_triggered()
{
    QMessageBox::critical(this, "错误","critical");

    //connect()
}


void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::information(this, "信息","输出了一些信息");
}


void MainWindow::on_actionQuestion_triggered()
{
    if(QMessageBox::Ok==
            QMessageBox::question(
                this, "问题","是吗？", QMessageBox::Ok|QMessageBox::Cancel)) {
        qDebug() << "selcet ok";
    } else {
        qDebug() << "selcet Cancel";
    }

}


void MainWindow::on_actionQFileDialog_triggered()
{
    // 打开一个文件对话框
    QString fileName = QFileDialog:: (
                this, "打开一个文件",
                "E:\\Desktop\\CodeLIb\\qt\\09_dialog",
                "PNG (*.png) ;; JPG (*.jpg) ;; C++ (*.cpp)");
    qDebug() << fileName; // 得到的是文件的绝对路径
}

