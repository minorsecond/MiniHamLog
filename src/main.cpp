#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("com.rwardrup.minihamlog");
    MainWindow w;
    w.show();
    return a.exec();
}
