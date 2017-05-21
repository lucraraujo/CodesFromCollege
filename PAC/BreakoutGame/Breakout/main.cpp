#include <QtGui/QApplication>
#include "ball.h"
#include "breakout.h"
#include "brick.h"
#include "paddle.h"
#include "mainWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(0));
    a.setApplicationName("Ronaldo");
    a.setQuitOnLastWindowClosed(true);
    //Breakout b;
    mainWindow window;
    window.show();

    //b.show();
    //b.setFixedSize(300,400);

    return a.exec();
}
