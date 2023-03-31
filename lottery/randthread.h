#ifndef RANDTHREAD_H
#define RANDTHREAD_H

//1.继承QOject
#include <QObject>
#include<QThread>

//2.改为public QThread
class randThread : public QThread
{
    Q_OBJECT
public:
    explicit randThread(QObject *parent = nullptr);

signals:
    //自定义信号
    void  randSignal();
    //3.重写run函数
protected:
    void run();//线程入口函数

};

#endif // RANDTHREAD_H
