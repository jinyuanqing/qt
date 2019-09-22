#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

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
   void  paixu();
private slots:
    void on_pushButton_16_clicked();
void slot_paixu();
    void on_pushButton_14_clicked();



    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
QList<int> list0;   QList<int> list00,list01;
       QMap<int,bool> list1;//Qmap可以去重,如果此处换成数组,数组会有重复的数据.而map天生去重.且按照索引顺序排序
};

#endif // MAINWINDOW_H
