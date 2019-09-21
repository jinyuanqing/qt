#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mythread.h"
#include <QThread>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void startWork();

private slots:


    void receiveProgress(int value);


    void receiveProgress1(int value);



    void on_pushButton_3_clicked();

private:

    QThread* thread;  QThread* thread1;
    myThread* m_thread;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
