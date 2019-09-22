#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
//2个扩张控件horizontalSpacer设置模式无关,水平布局设置为setfixedsize固定大小,其中的组件设置为最大=最小=150,垂直水平布局策略preferred.  居左布局
//  这2句    ui->horizontalLayout->removeItem(ui->horizontalSpacer);//可以实现自动居中布局,不加就是居左
//ui->horizontalLayout->addItem(ui->horizontalSpacer);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  ui->centralWidget->setLayout(ui->verticalLayout);
connect(this,SIGNAL(paixu()),this,SLOT(slot_paixu()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_16_clicked()
{



    ui->pushButton->isVisible()==true?  ui->pushButton->setVisible(false):ui->pushButton->setVisible(true);

 //  ui->pushButton->isVisible()==false?(   ui->horizontalLayout->removeWidget(ui->pushButton)):(   ui->horizontalLayout->addWidget(ui->pushButton));
  qDebug()<<ui->horizontalLayout->count();

emit paixu();

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->pushButton_4->isVisible()==true?  ui->pushButton_4->setVisible(false):ui->pushButton_4->setVisible(true);

   //  ui->pushButton_4->isVisible()==false?(   ui->horizontalLayout->removeWidget(ui->pushButton_4)):(   ui->horizontalLayout->addWidget(ui->pushButton_4));
    qDebug()<<ui->horizontalLayout->count();

emit paixu();

}

void MainWindow::on_pushButton_13_clicked()
{

    ui->pushButton_5->isVisible()==true?  ui->pushButton_5->setVisible(false):ui->pushButton_5->setVisible(true);

  // ui->pushButton_5->isVisible()==false?(   ui->horizontalLayout->removeWidget(ui->pushButton_5)):(   ui->horizontalLayout->addWidget(ui->pushButton_5));
  qDebug()<<ui->horizontalLayout->count();
  qDebug()<<ui->horizontalLayout->indexOf(ui->pushButton_5);
emit paixu();


}

void MainWindow::on_pushButton_15_clicked()
{
    ui->pushButton_2->isVisible()==true?  ui->pushButton_2->setVisible(false):ui->pushButton_2->setVisible(true);

   //ui->pushButton_3->isVisible()==false?(   ui->horizontalLayout->removeWidget(ui->pushButton_3)):(   ui->horizontalLayout->addWidget(ui->pushButton_3));
  qDebug()<<ui->horizontalLayout->count();
  qDebug()<<ui->horizontalLayout->indexOf(ui->pushButton_2);
emit paixu();}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::slot_paixu()
{
    list1.clear();

    list1[1]=(ui->pushButton->isVisible());
      list1[2]=(ui->pushButton_2->isVisible());
       list1[3]=(ui->pushButton_4->isVisible());
      list1[4]=(ui->pushButton_5->isVisible());


        list1[5]=(ui->pushButton_17->isVisible());
         list1[6]=(ui->pushButton_18->isVisible());
         list1[7]=(ui->pushButton_19->isVisible());
           list1[8]=(ui->pushButton_20->isVisible());
          qDebug()<<"输出"<<list1;
          list0.clear();list01.clear();
          for (int i=1;i<=list1.count();i++) {
              if(list1[i]==true){
                  list0.append(i);//所有值=true的键都加入到list0中
              }
          }
          qDebug()<<list0;
      //     ui->horizontalLayout->setEnabled(false);
           if(list0.size()<=4)
              {

               if(list0.contains(1))
                  ui->horizontalLayout->addWidget(ui->pushButton);
               if(list0.contains(2))
                  ui->horizontalLayout->addWidget(ui->pushButton_2);
               if(list0.contains(3))
                  ui->horizontalLayout->addWidget(ui->pushButton_4);
               if(list0.contains(4))
                  ui->horizontalLayout->addWidget(ui->pushButton_5);
               if(list0.contains(5))
                  ui->horizontalLayout->addWidget(ui->pushButton_17);
               if(list0.contains(6))
                  ui->horizontalLayout->addWidget(ui->pushButton_18);
               if(list0.contains(7))
                  ui->horizontalLayout->addWidget(ui->pushButton_19);
               if(list0.contains(8))
                  ui->horizontalLayout->addWidget(ui->pushButton_20);
              ui->horizontalLayout->removeItem(ui->horizontalSpacer);//可以实现自动居中布局,不加就是居左
               ui->horizontalLayout->addItem(ui->horizontalSpacer);
           }else{

        list00={list0[0],list0[1],list0[2],list0[3]};
        for (int i=0;i<list0.size()-4;i++) {

        list01.append(list0[4+i]);

           }
        qDebug()<<list00;
        qDebug()<<list01;


        if(list00.contains(1))
           ui->horizontalLayout->addWidget(ui->pushButton);

        if(list00.contains(2))
           ui->horizontalLayout->addWidget(ui->pushButton_2);
        if(list00.contains(3))
           ui->horizontalLayout->addWidget(ui->pushButton_4);
        if(list00.contains(4))
           ui->horizontalLayout->addWidget(ui->pushButton_5);
        if(list00.contains(5))
           ui->horizontalLayout->addWidget(ui->pushButton_17);
        if(list00.contains(6))
           ui->horizontalLayout->addWidget(ui->pushButton_18);
        if(list00.contains(7))
           ui->horizontalLayout->addWidget(ui->pushButton_19);
        if(list00.contains(8))
           ui->horizontalLayout->addWidget(ui->pushButton_20);
        ui->horizontalLayout->removeItem(ui->horizontalSpacer);//可以实现自动居中布局,不加就是居左
       ui->horizontalLayout->addItem(ui->horizontalSpacer);


        if(list01.contains(5))
           ui->horizontalLayout_2->addWidget(ui->pushButton_17);

        if(list01.contains(6))
           ui->horizontalLayout_2->addWidget(ui->pushButton_18);

        if(list01.contains(7))
           ui->horizontalLayout_2->addWidget(ui->pushButton_19);

        if(list01.contains(8))
           ui->horizontalLayout_2->addWidget(ui->pushButton_20);


       ui->horizontalLayout_2->removeItem(ui->horizontalSpacer_2);//可以实现自动居中布局,不加就是居左
       ui->horizontalLayout_2->addItem(ui->horizontalSpacer_2);

                            }

}

void MainWindow::on_pushButton_9_clicked()
{
     ui->pushButton_17->isVisible()==true?  ui->pushButton_17->setVisible(false):ui->pushButton_17->setVisible(true);
emit paixu();
}

void MainWindow::on_pushButton_10_clicked()
{
     ui->pushButton_18->isVisible()==true?  ui->pushButton_18->setVisible(false):ui->pushButton_18->setVisible(true);
emit paixu();}

void MainWindow::on_pushButton_11_clicked()
{
     ui->pushButton_19->isVisible()==true?  ui->pushButton_19->setVisible(false):ui->pushButton_19->setVisible(true);
emit paixu();}

void MainWindow::on_pushButton_12_clicked()
{

    ui->pushButton_20->isVisible()==true?  ui->pushButton_20->setVisible(false):ui->pushButton_20->setVisible(true);
emit paixu();}

void MainWindow::on_pushButton_6_clicked()
{
ui->horizontalLayout_3->addWidget(ui->pushButton_7);

}

