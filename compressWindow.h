#ifndef QMAINWINDOW_H
#define QMAINWINDOW_H

#include <QMainWindow>

#endif // QMAINWINDOW_H

#include "progressbar.h"
#include<QObject>
#include <QLayout>
#include<QPushButton>
#include<QLabel>
#include<progressbar.h>
#include<QFileDialog>
#include<QDropEvent>
#include<QFile>
#include<QMimeData>
#include<QMessageBox>
#include<QString>
#include<QThread>
#include<QProcess>
#include<QTreeWidget>
#include"SevenZHelper.hpp"
#include"toolthread.h"

#pragma comment(lib,"user32.lib")
#pragma comment(lib,"gdi32.lib")
#pragma comment(lib,"ntdll.lib")
#pragma comment(lib,"oleaut32.lib")

class compressWindow:public QMainWindow
{
    Q_OBJECT

public:
    compressWindow(QWidget *parent = 0);
    ~compressWindow();
    void setShow();
    void handleFile();
    void dropEvent(QDropEvent* event);
    void compressMode();
    void deCompressMode();
    void OpenFileInExplorer();
    void dragEnterEvent(QDragEnterEvent* event);

private:
    QLabel* typelabel;
    QComboBox *typecomboBox;
    QString type;

    QLabel* levellabel;
    QComboBox *levelcomboBox;
    int level;

    QLabel* speedlabel;
    QComboBox *speedcomboBox;
    int speed;

    QLabel* pwdlabel;
    QLineEdit* pwdline;
    QString pwd;

    QPushButton* addfile_pb = new QPushButton("add files",this);
    QPushButton* decompress_pb =  new QPushButton("Decompress",this);
    QPushButton* compress_pb = new QPushButton("Compress",this);

    progressBar* bar = new progressBar(this);

    toolThread* t = new toolThread ();

    QStringList fileName;
    int fileNum;

private slots:
    void getPwd();
};
