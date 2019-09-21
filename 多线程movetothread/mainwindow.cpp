#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<qdebug.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<"UI widget ThreadId:"<<QThread::currentThreadId();

        ui->progressBar->setValue(0);


        m_thread = new myThread();
        thread = new QThread();
            //  thread1 = new QThread();
        m_thread->moveToThread(thread);

        connect(m_thread,&myThread::currentProgress,this,&MainWindow::receiveProgress);

        connect(m_thread,&myThread::currentProgress1,this,&MainWindow::receiveProgress1);


        connect(this,&MainWindow::startWork,m_thread,&myThread::doWork);//建立主线程信号和子线程的槽的连接


        connect(thread,&QThread::finished,thread,&QThread::deleteLater);
        connect(thread,&QThread::finished,m_thread,&myThread::deleteLater);


}

MainWindow::~MainWindow()
{
    if(thread->isRunning())
           m_thread->stopThread();

       thread->quit();
       thread->wait();


       delete ui;

}



void MainWindow::receiveProgress(int value)
{
    ui->progressBar->setValue(value);
}
void MainWindow::receiveProgress1(int value)
{
    ui->progressBar_2->setValue(value);
}

void MainWindow::on_pushButton_3_clicked()
{
    thread->start();


      emit startWork();//发送信号
}
