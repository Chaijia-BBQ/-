#include "randThread.h"

randThread::randThread(QObject *parent) : QThread(parent)
{

}

void randThread::run()
{
    while(1)
    {
        emit randSignal();
       // QThread::usleep(1000);
        QThread::msleep(50);
    }

}
