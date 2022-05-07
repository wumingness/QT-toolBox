#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1600,1000);
    setWindowTitle("mainWindow");
    createCoder();
    createCompressor();

}

MainWindow::~MainWindow(){

}

bool MainWindow::createCoder(){
    coder->resize(800,500);

    coder->move(800,0);

    coder->show();

    QPushButton* pb = new QPushButton("coder",coder);

    pb->resize(400,400);

    pb->move(200,50);

    pb->show();

    QObject::connect(pb,&QPushButton::clicked,new codeWindow(this),&codeWindow::setShow);

    return true;
}


bool MainWindow::createCompressor(){

    compressor->resize(800,500);

    compressor->move(800,500);

    QPushButton* pb = new QPushButton("compressor",compressor);

    pb->resize(400,400);

    pb->move(200,50);

    pb->show();

    QObject::connect(pb,&QPushButton::clicked,new compressWindow(this),&compressWindow::setShow);



    return true;
}

void MainWindow::paintEvent(QPaintEvent(*)){
 //   QImage *image = new QImage();
  //  if(!image->load(QString("D:/VS2019 Files/toolBox/toolBox/image/safe.png")))
 //       QMessageBox::warning(this,"wrong","wrong in opening image file.");
  //  QLabel* label = new QLabel("image",calender);
 //   label->resize(800,1000);
 //   label->move(0,0);
 //   label->setPixmap(QPixmap::fromImage(*image));
  //  label->show();

    QPainter painter(this);
    QPen pen;
    QColor color_sunny(130,234,187,80);
    pen.setColor(color_sunny);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    QFont font;
    font.setFamily("KaiTi_GB2312");
    font.setPointSize(30);
    painter.setFont(font);
    painter.setPen(pen);
    painter.drawText(100,100,tr("Sunny"));

}

void MainWindow::dropEvent(QDropEvent*event)    //放下事件
{
    const QMimeData*qm=event->mimeData();//获取MIMEData	//依据文件名导入文件即可
}
