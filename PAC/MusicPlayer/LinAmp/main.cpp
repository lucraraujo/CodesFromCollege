#include <QtGui>

#include "mainwindow.h"

//![1]
int main(int argv, char **args)
{
    QApplication app(argv, args);
    QPixmap imagem(":/metal.gif");
    QSplashScreen splash(imagem);
    splash.show();
    sleep(3);
    splash.close();
    app.setApplicationName("LinAmp Music Player");
    app.setQuitOnLastWindowClosed(true);

    MainWindow window;
    window.show();

    return app.exec(); 
}
//![1]
