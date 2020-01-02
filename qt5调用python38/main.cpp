#include "mainwindow.h"

#include <QApplication>



#include"C:\Program Files\Python38\include\Python.h"

#include<QDebug>

#include<QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


Py_SetPythonHome((const wchar_t *)(L"C://Program Files//Python38"));//windows路径为C:\Program Files\Python37会报错.改成了反斜杠ok

//初始化python解释器
Py_Initialize();
if(!Py_IsInitialized()){return  -1;}
//导入python文件模块
PyObject* pModule = PyImport_ImportModule("test_py");  // 这里的test_py就是创建的python文件
   if (!pModule) {
           printf( "Cant open python file!\n");
           return -1;
       }



   //获取python的add函数对象
  PyObject* pFun_add= PyObject_GetAttrString(pModule,"add");  // 这里的hellow就是python文件定义的函数

   if(!pFun_add){
       printf("Get function add failed");
       return -1;
   }
   // 设置参数.形成元祖的形势传递.有2中方法
       PyObject* args = PyTuple_New(2);       // 2个参数
       //PyObject* arg1 = PyUnicode_FromString("hello");    // 参数一设为，字符串
       PyObject* arg1 = PyLong_FromLong(1050);    // 参数二设为，一个整数，用long表示
       PyObject* arg2 = PyLong_FromLong(520);    // 参数二设为，一个整数，用long表示
       PyTuple_SetItem(args, 0, arg1);
       PyTuple_SetItem(args, 1, arg2);
//       .第二种方法 简单
    //   PyObject* args1 = Py_BuildValue("ii",128, 103);//给python函数参数赋值.2个i代表2个参数类型都是整形

   //调用python的add函数
   PyObject* jieguo= PyObject_CallObject(pFun_add,args);

int res = 0;
    PyArg_Parse(jieguo,"i",&res);//i是整数

 qDebug()<<"add:"<< res  ;//输出结果


//第1种方法
// PyObject* args3 = Py_BuildValue("",128.5, 103.2);//给python函数参数赋值
 // 设置参数.形成元祖的形势传递.有2中方法
//     PyObject* args3 = PyTuple_New(2);       // 2个参数
//     PyObject* arg11 = PyFloat_FromDouble(10.50);    // 参数1设为，浮点
//     PyObject* arg21 = PyFloat_FromDouble(5.20);    // 参数2,浮点
//     PyTuple_SetItem(args3, 0, arg11);
//     PyTuple_SetItem(args3, 1, arg21);
 //第二种方法简单
PyObject* args3 = Py_BuildValue("ff",1.28, 1.03);//给python函数参数赋值.2个f代表2个参数的类型
//调用python的add函数
PyObject* fe= PyObject_CallObject(pFun_add,args3);

float res2 = 0;
PyArg_Parse(fe,"f",&res2);//f是浮点数

qDebug()<<"add(f):"<< res2  ;//输出结果



   //获取python的hello函数对象
  PyObject* pFunhello= PyObject_GetAttrString(pModule,"hello");  // 这里的hellow就是python文件定义的函数

   if(!pFunhello){
       printf("Get function hello failed");
       return -1;
   }
   //调用python的hello函数
   PyObject* jieguo1=    PyObject_CallFunction(pFunhello,0);



char* res1;
    PyArg_Parse(jieguo1,"s",&res1);//s是字符串格式.python返回字符串,而在c/c++中对应的是char*.

 qDebug()<<"字符输出:"<< res1  ;//输出结果






   Py_Finalize();




    return a.exec();
}
