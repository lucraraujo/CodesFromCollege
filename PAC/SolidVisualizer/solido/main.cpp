#include <QtGui/QApplication>
#include "mainwindow.h"
#include "offviewer.h"

int main(int argc, char *argv[])
{
    //GLUTInit(&argc, argv);
    if (!ParseArgs(argc, argv)) exit(1);
   mesh = ReadOffFile(filename);
    if (!mesh) exit(1);

    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    GLUTMainLoop();
    return 0;
    //return a.exec();
}
