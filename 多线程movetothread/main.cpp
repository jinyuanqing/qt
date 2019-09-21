#include "mainwindow.h"
#include <QApplication>
#include<qdebug.h>
#include<qthread.h>

#include<myThread.h>
#include<qobject.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
