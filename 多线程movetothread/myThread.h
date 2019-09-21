#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>


class myThread :public QObject
{
    Q_OBJECT
public:
    myThread(QObject* parent = NULL);

    void doWork();

    void stopThread();
signals:
    void currentProgress(int value);
 void currentProgress1(int value);
private:
    bool m_isRun = true;
    QMutex *m_mutex;
};

#endif // MYTHREAD_H
