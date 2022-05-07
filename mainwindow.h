#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QDropEvent>
#include <QGroupBox>
#include<QImage>
#include<QPen>
#include<QPixmap>
#include <QPainter>
#include<QBrush>
#include<QColor>
#include<QPicture>
#include"codewindow.h"
#include"compressWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool createCoder();
    bool createCompressor();
    void paintEvent(QPaintEvent *);
    void dropEvent(QDropEvent* event);

private:
    QWidget* coder = new QWidget(this);
    QWidget* compressor = new QWidget(this);
    QWidget* calender = new QWidget(this);
};
#endif // MAINWINDOW_H
