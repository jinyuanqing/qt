#include "mythread.h"
#include <QDebug>
myThread::myThread(QObject *parent)
{
    qDebug()<<"construction ThreadID:"<<QThread::currentThreadId();
    m_mutex = new QMutex();
}

void myThread::doWork()
{
    for(int i = 0;i<=10000000;i+=10)
    {
        if(!m_isRun)
            return;

        qDebug()<<"doWork() ThreadID:"<<QThread::currentThreadId();

        emit currentProgress(i);
    emit currentProgress1(i);
        QThread::msleep(10);
    }
    qDebug()<<"doWork over";

}



void myThread::stopThread()
{
    QMutexLocker(*m_mutex);
    m_isRun = false;
    qDebug()<<"线程停止时的 ThreadID:"<<QThread::currentThreadId();
}
