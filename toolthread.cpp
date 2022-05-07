#include "toolthread.h"
#include<QDebug>

toolThread::~toolThread(){
    if(bar) delete bar;
}
void toolThread::setParam(int mode,int fileNum,QStringList fileName,QString pwd,QString type,int level,int method){
    this->mode = mode;
    this->fileName = fileName;
    this->fileNum = fileNum;
    this->pwd = pwd;
    this->level = level;
    this->method = method;
    this->type = type;
}

void toolThread::run(){
    switch (mode) {
    case 1:{
        bar->setStart();
        SevenZHelper* sevenZ = new SevenZHelper();
                for(int i = 0;i<fileNum;i++){
                    sevenZ->CompressDecompression(SevenZType::OpType_Decompression,
                                                  std::wstring((const wchar_t *)fileName[i].utf16()),
                                                  std::wstring((const wchar_t *)type.utf16()),
                                                  std::wstring((const wchar_t *)pwd.utf16()));
                }
                return;

    }
    case 2:{
        bar->setStart();
        SevenZHelper* sevenZ = new SevenZHelper();
                for(int i = 0;i<fileNum;i++){
                    sevenZ->CompressDecompression(SevenZType::OpType_Compress,
                                                  std::wstring((const wchar_t *)fileName[i].utf16()),
                                                  std::wstring((const wchar_t *)type.utf16()),
                                                  std::wstring((const wchar_t *)pwd.utf16()),
                                                  (bit7z::BitCompressionLevel)level,
                                                  (bit7z::BitCompressionMethod)method);
                    qDebug()<<fileName[i];
                }
                qDebug()<<"end";
                return;

    }
}
    }


void toolThread::setBar(progressBar *bar){
    this->bar = bar;
}

void toolThread::setStart(){
    Start = true;
}

