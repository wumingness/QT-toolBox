#include "compressWindow.h"
#include<QDebug>
compressWindow::compressWindow(QWidget* parent)
//    :QMainWindow(parent)
{
    QFont font("KaiTi_GB2312", 12);
    setFont(font);
    resize(1600,1000);

    connect(compress_pb,&QPushButton::clicked,this,&compressWindow::compressMode);
    connect(decompress_pb,&QPushButton::clicked,this,&compressWindow::deCompressMode);
    connect(addfile_pb,&QPushButton::clicked,this,&compressWindow::OpenFileInExplorer);
    connect(addfile_pb,SIGNAL(clicked()),bar,SLOT(setProgress()));

    compress_pb->resize(200,100);
    compress_pb->move(1200,100);
    compress_pb->setDisabled(true);

    decompress_pb->resize(200,100);
    decompress_pb->move(1200,400);
    decompress_pb->setDisabled(true);

    addfile_pb->resize(200,100);
    addfile_pb->move(1200,700);

    bar->resize(800,500);
    bar->move(100,400);
    bar->setVisible(true);

    typelabel = new QLabel (this);
    typelabel->setText(tr("Type:"));
    typelabel->resize(100,100);
    typelabel->move(100,100);
    typecomboBox = new QComboBox(this);
    typecomboBox->addItem(tr("7z"));
    typecomboBox->addItem(tr("zip"));
    typecomboBox->addItem(tr("rar"));
    typecomboBox->resize(200,50);
    typecomboBox->move(200,125);

    levellabel = new QLabel(this);
    levellabel->setText(tr("Level:"));
    levellabel->resize(100,100);
    levellabel->move(500,100);
    levelcomboBox = new QComboBox(this);
    levelcomboBox->addItem(tr("only"));
    levelcomboBox->addItem(tr("normal"));
    levelcomboBox->addItem(tr("standard"));
    levelcomboBox->addItem(tr("ultra"));
    levelcomboBox->addItem(tr("max"));
    levelcomboBox->resize(200,50);
    levelcomboBox->move(610,125);

    speedlabel = new QLabel(this);
    speedlabel->setText(tr("Method:"));
    speedlabel->resize(120,100);
    speedlabel->move(100,250);
    speedcomboBox = new QComboBox(this);
    speedcomboBox->addItem(tr("normal"));
    speedcomboBox->addItem(tr("fast"));
    speedcomboBox->addItem(tr("ultra"));
    speedcomboBox->resize(200,50);
    speedcomboBox->move(220,275);

    pwdlabel = new QLabel(this);
    pwdlabel->setText("Pwd:");
    pwdlabel->resize(100,100);
    pwdlabel->move(500,250);
    pwdline = new QLineEdit(this);
    pwdline->resize(250,50);
    pwdline->move(570,275);

    setAcceptDrops(true);
}

compressWindow::~compressWindow(){

}

void compressWindow::setShow(){
    if(this != nullptr)
        setVisible(this);
}

void compressWindow::OpenFileInExplorer()
{
    fileName = QFileDialog::getOpenFileNames(this,"select");
    fileNum = fileName.size();
    if(fileNum>0){
        compress_pb->setEnabled(true);
        decompress_pb->setEnabled(true);
    }
}

void compressWindow::handleFile(){
    QMessageBox::StandardButton info;
    if(fileName.size()==0){
        info = QMessageBox::critical(this,"warning","File doesn not exist!" );
    }
    else{
        info = QMessageBox::question(this,"confirm","Sure to compress/decompress the file/directory?");
    }
    if(info==QMessageBox::Ok||info==QMessageBox::No)
        return;
    if(info==QMessageBox::Yes){
        //调用compress函数
        compress_pb->setEnabled(true);
        decompress_pb->setEnabled(true);
    }
}

void compressWindow::dragEnterEvent(QDragEnterEvent *event){
    event->acceptProposedAction();
}

void compressWindow::dropEvent(QDropEvent*event)
{
    const QMimeData*qm=event->mimeData();
    fileNum = qm->urls().size();
    for (int i = 0;i<fileNum ;i++)
    fileName.push_back(qm->urls()[i].toLocalFile());
    handleFile();
}

void compressWindow::getPwd(){
    pwd = pwdline->text();
    qDebug()<<pwd;
}

void compressWindow::compressMode(){
    type = typecomboBox->currentText();
    pwd = pwdline->text();
    level = 2*levelcomboBox->currentIndex()-1;
    speed = 3*speedcomboBox->currentIndex();
    t->setParam(2,fileNum,fileName,pwd,type,level,speed);
    bar->setThread(t);
    t->setBar(bar);
    t->start();
    compress_pb->setDisabled(true);
    decompress_pb->setDisabled(true);
}

void compressWindow::deCompressMode(){
   pwd = pwdline->text();
   t->setParam(1,fileNum,fileName,pwd);
   bar->setThread(t);
   t->setBar(bar);
   t->start();
   compress_pb->setDisabled(true);
   decompress_pb->setDisabled(true);
}
