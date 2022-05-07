
#ifndef _TOOLTHREAD_H
#define _TOOLTHREAD_H
#pragma once
#include<QThread>
#include<SevenZHelper.hpp>
#include"progressbar.h"
class toolThread:public QThread
{
//    Q_OBJECT
private:
    bool Start = false;
    int mode;
    int fileNum;
    int level;
    int method;
    QString pwd;
    QString type;
    QStringList fileName;
    progressBar* bar;
    void run();
    ~toolThread();

public:
    void setStart();
    void setParam(int mode,int fileNum,QStringList fileName,QString pwd,QString type = "",int level = -1,int method = -1);
    void setBar(progressBar* bar);

signals:
    static void setProgress(double progress);
};
#endif

