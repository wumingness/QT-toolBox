#include "mainwindow.h"

#include <QApplication>
#include "SevenZHelper.hpp"
int main(int argc, char *argv[])
{
    QApplication::setStyle("motif");
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
    w->show();


    return a.exec();
}
