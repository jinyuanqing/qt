
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<ruler.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//qDebug()<<"ui"<<ui->progressBar->maximum();
//ui->progressBar->maxValue=46;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action2_triggered()
{

}

void MainWindow::on_pushButton_clicked()
{static int ii=0;
    ii=10+ii;
    if(ii==100)ii=0;
    ui->progressBar->set_value(ii);
}
