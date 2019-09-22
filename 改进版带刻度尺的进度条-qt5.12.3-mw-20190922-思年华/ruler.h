#ifndef RULER_H
#define RULER_H

#include <QObject>
#include <QWidget>
#include<QProgressBar>//后加
class Ruler : public QProgressBar
{

    Q_OBJECT//后加
public:
    Ruler(QWidget *parent = nullptr);//后加
    ~Ruler();
void  paintEvent(QPaintEvent *);

public slots:
void update_ruler();
void set_value(int  a1);
public:
    //此处属性可以在外部调用
    int minValue=0;                //比例尺最小值
       int maxValue=55;                //比例尺最大值
       int precision=2;                  //精确度,小数点后几位
       int longStep=5;                   //长线条等分步长 .注意:longStep/shortstep需要等于整数,否则没法等分
       int shortStep=1;                  //短线条等分步长

bool shuiping_chuizhi=1;//0水平,1垂直.修改此值就要修改提升控件的宽高了.

          int value=2;                   //目标值
       bool rulerTop=0;                  //刻度线在上面
bool shua_xin=0;
       bool animation;                 //是否启用动画显示
       double animationStep;           //动画显示时步长
int a1;
       QColor *bgColor;                 //背景颜色
       QColor lineColor;               //线条颜色
       QColor *progressColor;           //进度颜色
QTimer *timer;



};

#endif // RULER_H
