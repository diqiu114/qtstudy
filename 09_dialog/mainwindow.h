#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionWarning_triggered();

    void on_actionInfo_triggered();

    void on_actionQuestion_triggered();

    void on_actionQFileDialog_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
