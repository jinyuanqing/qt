#include "ruler.h"
#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QTimer>
#include <iostream>
#include<stdio.h>
#include<math.h>//引入math头文件
using namespace std;
Ruler::Ruler(QWidget *parent ):QProgressBar(parent)//后加
{
/*自定义控件的步骤:首先新建项目-添加c++类,填写类名和基类,基类就是你想在哪个控件的基础上做自定义.例如我们整个自定义进度条效果,就是在进度条类的基础上做的.
 *如果你在其他控件上做也可以做,但是会麻烦.比如说通过ui界面属性设置比例尺的最大值就可以通过属性界面直接修改.如果你通过label控件自定义,属性界面都没有最大值属性怎么改呢?也可以改,但是
 * 会麻烦点.所以基类别选错了.头文件和cpp中有4处后加的注释代码.这里在自动生成的文件模板中是没有的,需要自己添加

    */



lineColor.setRgb(50,205,155,255);//设置刻度线的颜色
timer=new QTimer(this);
connect(timer,SIGNAL(timeout()), this,SLOT( update_ruler()));

timer->start(100);

//把提升的进度条控件的最大值固定设置为0-100.  修改比例尺的最大值就可以实现进度条成比例的对应刻度了




}
void Ruler::update_ruler()
{
shua_xin=1;
update();//强制刷新,效果就是调用一次绘制事件
}


Ruler::~Ruler()
{

}




void Ruler::set_value(int  a1){

    value=a1;


}


void Ruler::paintEvent(QPaintEvent *){

//    save() 用于保存 QPainter 的状态，restore() 用于恢复 QPainter 的状态，save() 和 restore() 一般都是成对使用的，如果只调用了 save() 而不调用 restore()，那么保存就没有意义了，保存是为了能恢复被保存的状态而使用的。QPainter 的状态有画笔，画刷，字体，变换（旋转，移动，切变，缩放）等。
 if((shua_xin==1)&&(shuiping_chuizhi==0))
  {

        QPainter painter(this);
            QRect rect = QRect(0, 52, width(), 95);//以第一个比例尺y坐标为起点(50)地方绘制进度条的外部矩形,高度100=2个比例尺之间的距离. 如果正好一50和100作为参数绘制,导致绘制重叠,因此留出距离.
            QRect textRect = QRect(0, height()/2, width(), height()/2);

            const double k = (double)(value - minimum()) / (maximum()-minimum());
//            qDebug()<<"maximum():"<<maximum();
            int x = (int)(rect.width() * k);
            QRect fillRect = rect.adjusted(0, 0, x-rect.width(), 0);//进度条内部填充的矩形.后2个参数为右下角作为原点(00).所有右下角的参考运算都是负数的.长度为负数也就是x-rect.width(),也就是正的width-x

            QString valueStr = QString("%1%").arg(QString::number(value));


            //画进度条

//            p.setPen(Qt::NoPen);
              painter.setBrush(QBrush(QColor(97, 117, 118)));
            painter.drawRect(rect);
                  painter.setBrush(QBrush(QColor(150,205,155)));
                  painter.drawRect(fillRect);


            //画文字
            QFont f = QFont("Microsoft YaHei", 15, QFont::Bold);
            painter.setFont(f);
            painter.setPen(QColor("#555555"));
            painter.drawText(textRect, Qt::AlignCenter, valueStr);


//标尺绘制分成4步:1底线,2长刻度线3短刻度线4刻度值文字


         //绘制刻度在下方的比例尺
  painter.save();
        painter.setPen(lineColor);
        double initX = 0;//自定义控件的坐标x原点

        //1步:绘制横向标尺  底线.
        double initTopY =150;  //影响标尺的底线距离控件原点(0,0)的距离,页间接影响文字是否显示全.这个值不能大于提升控件的宽高
        QPointF lineTopLeftPot = QPointF(initX, initTopY);
        QPointF lineTopRightPot = QPointF(width() - initX, initTopY);
        painter.drawLine(lineTopLeftPot, lineTopRightPot);

        //绘制上部分及下部分横向标尺刻度
        double length = width()-1;//提升控件的宽度要+1,提升控件的宽度设置的值/shortStep要=整数,这样才能等分线段
        //计算每一格移动多少
        double increment = length / (maxValue - minValue);
        //长线条短线条长度
        int longLineLen = 15;
        int shortLineLen = 10;

        //根据范围值绘制刻度值文字(第4步)及刻度值长线条(第2步) ,短刻度线条(第3步)
      for (int i = minValue; i <= maxValue; i = i + shortStep)//刻度从上往下依次 变大


        {
            if (i % longStep == 0) {


                QPointF topPot = QPointF(initX, initTopY);
                QPointF bottomPot = QPointF(initX, initTopY + longLineLen);
                painter.drawLine(topPot, bottomPot);//长刻度线条(第2步)

                //第一个值和最后一个值不要绘制
                if (i == minValue || i == maxValue) {
                    initX += increment * shortStep;
                    continue;
                }

                QString strValue = QString("%1").arg((double)i/pow(10, precision), 0, 'f', precision);//浮点方式显示.pow(10, precision)=10的precision次幂
                double textWidth = fontMetrics().width(strValue);
                double textHeight = fontMetrics().height();

                QPointF textPot = QPointF(initX - textWidth / 2, initTopY + textHeight + longLineLen);
                painter.drawText(textPot, strValue);//绘制刻度值文字(第4步)
            } else {
                if (i % (longStep / 2) == 0) {
                    shortLineLen = 10;
                } else {
                    shortLineLen = 6;
                }

                QPointF topPot = QPointF(initX, initTopY);
                QPointF bottomPot = QPointF(initX, initTopY + shortLineLen);
                painter.drawLine(topPot, bottomPot);//绘制短刻度线条(第3步)
            }

            initX += increment * shortStep;
        }

    painter.restore();

        //绘制刻度在上方的比例尺
 painter.save();
       painter.setPen(lineColor);

initX= 0;
       //绘制横向标尺  底线.
        initTopY =50;//影响标尺的底线距离控件原点(0,0)的距离,页间接影响文字是否显示全
        lineTopLeftPot = QPointF(initX, initTopY);
        lineTopRightPot = QPointF(width() - initX, initTopY);
       painter.drawLine(lineTopLeftPot, lineTopRightPot);

       //绘制上部分及下部分横向标尺刻度
        length = width()-1;//提升控件的宽度要+1,提升控件的宽度设置的值/shortStep要=整数,这样才能等分线段
       //计算每一格移动多少
        increment = length / (maxValue - minValue);
       //长线条短线条长度
        longLineLen = 15;
        shortLineLen = 10;
        int  up=10;
       //根据范围值绘制刻度值及刻度值 长线条需要移动10像素 短线条需要移动5像素
       for (int i = minValue; i <= maxValue; i = i + shortStep) {
           if (i % longStep == 0) {
               QPointF topPot = QPointF(initX, initTopY);
               QPointF bottomPot = QPointF(initX, initTopY - longLineLen);
               painter.drawLine(topPot, bottomPot);

               //第一个值和最后一个值不要绘制
               if (i == minValue || i == maxValue) {
                   initX += increment * shortStep;
                   continue;
               }

               QString strValue = QString("%1").arg((double)i, 0, 'f', precision);
               double textWidth = fontMetrics().width(strValue);
               double textHeight = fontMetrics().height();

               QPointF textPot = QPointF(initX - textWidth / 2, initTopY -textHeight -longLineLen);
               painter.drawText(textPot, strValue);
           } else {
               if (i % (longStep / 2) == 0) {
                   shortLineLen = 10;
               } else {
                   shortLineLen = 6;
               }

               QPointF topPot = QPointF(initX, initTopY);
               QPointF bottomPot = QPointF(initX, initTopY - shortLineLen);
               painter.drawLine(topPot, bottomPot);
           }

           initX += increment * shortStep;
       }




        painter.restore();
shua_xin=0;
}else if((shua_xin==1)&&(shuiping_chuizhi==1))
 {//垂直刻度尺


     QPainter painter(this);
         QRect rect = QRect(105, 0, 140, height());//以第一个比例尺y坐标为起点(50)地方绘制进度条的外部矩形,高度100=2个比例尺之间的距离. 如果正好一50和100作为参数绘制,导致绘制重叠,因此留出距离.
         QRect textRect = QRect(0, height()/2, width(), height()/2);

         const double k = (double)(value - minimum()) / (maximum()-minimum());
//            qDebug()<<"maximum():"<<maximum();
         int x = (int)(rect.height() * k);
         //QRect fillRect = rect.adjusted(0, rect.height()-x, 0,0);//进度条内部填充的矩形.下往上绘制填充矩形.左上角和右下角为原点的.前2个参数(0, rect.height()-x)是以左上角为原点,后2个参数(0,0)是右下角的原点.负值表示在矩形内，正值表示在矩形外

         QRect fillRect = rect.adjusted(0, 0, 0, x-rect.height());//进度条内部填充的矩形.上往下绘制填充矩形.x-rect.height()是距离右下角原点0,0的距离负

         QString valueStr = QString("%1%").arg(QString::number(value));


         //画进度条

//            p.setPen(Qt::NoPen);
           painter.setBrush(QBrush(QColor(97, 117, 118)));
         painter.drawRect(rect);
               painter.setBrush(QBrush(QColor(150,205,155)));
               painter.drawRect(fillRect);


         //画文字
         QFont f = QFont("Microsoft YaHei", 15, QFont::Bold);
         painter.setFont(f);
         painter.setPen(QColor("#555555"));
         painter.drawText(textRect, Qt::AlignCenter, valueStr);


//标尺绘制分成4步:1底线,2长刻度线3短刻度线4刻度值文字


      //绘制刻度在左侧的比例尺
painter.save();
     painter.setPen(lineColor);
     double initY = 0;//自定义控件的坐标x原点

     //1步:绘制横向标尺  底线.
     double initTopX =250;  //影响标尺的底线距离控件原点(0,0)的距离,页间接影响文字是否显示全.这个值不能大于提升控件的宽高
     QPointF lineTopLeftPot = QPointF(initTopX,initY );
     QPointF lineTopRightPot = QPointF(initTopX,height() - initY );
     painter.drawLine(lineTopLeftPot, lineTopRightPot);

     //绘制上部分及下部分横向标尺刻度
     double length = height()-1;//提升控件的宽度要+1,提升控件的宽度设置的值/shortStep要=整数,这样才能等分线段
     //计算每一格移动多少
     double increment = length / (maxValue - minValue);
     //长线条短线条长度
     int longLineLen = 15;
     int shortLineLen = 10;

     //根据范围值绘制刻度值文字(第4步)及刻度值长线条(第2步) ,短刻度线条(第3步)
    // for (int i = minValue; i <= maxValue; i = i + shortStep) //上往下,刻度值依次大
      for (int i = maxValue; i >= minValue; i = i - shortStep) //下往上,刻度值依次大
     {
         if (i % longStep == 0) {


             QPointF topPot = QPointF(initTopX,initY );
             QPointF bottomPot = QPointF(initTopX + longLineLen,initY );
             painter.drawLine(topPot, bottomPot);//长刻度线条(第2步)

             //第一个值和最后一个值不要绘制
             if (i == minValue || i == maxValue) {
                 initY += increment * shortStep;
                 continue;
             }

             QString strValue = QString("%1").arg((double)i/pow(10, precision), 0, 'f', precision);//浮点方式显示.pow(10, precision)=10的precision次幂
             double textWidth = fontMetrics().width(strValue);
             double textHeight = fontMetrics().height();

             QPointF textPot = QPointF( initTopX  + textWidth + longLineLen ,  initY +textHeight / 2);
             painter.drawText(textPot, strValue);//绘制刻度值文字(第4步)
         } else {
             if (i % (longStep / 2) == 0) {
                 shortLineLen = 10;
             } else {
                 shortLineLen = 6;
             }

             QPointF topPot = QPointF( initTopX, initY);
             QPointF bottomPot = QPointF(initTopX + shortLineLen,  initY);
             painter.drawLine(topPot, bottomPot);//绘制短刻度线条(第3步)
         }

         initY += increment * shortStep;
     }

 painter.restore();

     //绘制刻度在上方的比例尺
painter.save();
    painter.setPen(lineColor);

initY= 0;
    //绘制横向标尺  底线.
     initTopX =100;//影响标尺的底线距离控件原点(0,0)的距离,间接影响文字是否显示全
     lineTopLeftPot = QPointF( initTopX, initY);
     lineTopRightPot = QPointF(initTopX,height() -  initY);
    painter.drawLine(lineTopLeftPot, lineTopRightPot);

    //绘制上部分及下部分横向标尺刻度
     length = height()-1;//提升控件的宽度要+1,提升控件的宽度设置的值/shortStep要=整数,这样才能等分线段
    //计算每一格移动多少
     increment = length / (maxValue - minValue);
    //长线条短线条长度
     longLineLen = 15;
     shortLineLen = 10;
     int  ju_li=30;
    //根据范围值绘制刻度值及刻度值 长线条需要移动10像素 短线条需要移动5像素
    for (int i = minValue; i <= maxValue; i = i + shortStep) {
        if (i % longStep == 0) {
            QPointF topPot = QPointF( initTopX, initY);
            QPointF bottomPot = QPointF(  initTopX- longLineLen, initY );
            painter.drawLine(topPot, bottomPot);

            //第一个值和最后一个值不要绘制
            if (i == minValue || i == maxValue) {
                initY += increment * shortStep;
                continue;
            }

            QString strValue = QString("%1").arg((double)i, 0, 'f', precision);
            double textWidth = fontMetrics().width(strValue);
            double textHeight = fontMetrics().height();

            QPointF textPot = QPointF(initTopX -textWidth  -longLineLen-ju_li , initY +textHeight  / 2);
            painter.drawText(textPot, strValue);
        } else {
            if (i % (longStep / 2) == 0) {
                shortLineLen = 10;
            } else {
                shortLineLen = 6;
            }

            QPointF topPot = QPointF( initTopX, initY);
            QPointF bottomPot = QPointF( initTopX- shortLineLen, initY );
            painter.drawLine(topPot, bottomPot);
        }

        initY += increment * shortStep;
    }




     painter.restore();
shua_xin=0;



 }







}
