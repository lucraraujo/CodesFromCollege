#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "breakout.h"
#include <QMainWindow>
//#include <QMenuBar>
class QAction;
//#include <QAction>
//#include <QtGui>

class mainWindow : public QMainWindow
{
    Q_OBJECT

    Breakout* breakout;
    QMenuBar* fileMenu;
    QAction* playAction;
    QAction* pause;
    QAction* restart;
    QAction* exit;
    QAction *atributos;
    QAction *aboutQtAction;

public:
    mainWindow();
    void setupUi();
    ~mainWindow();
    void setupMenu();
    void setupActions();
};

#endif // MAINWINDOW_H
