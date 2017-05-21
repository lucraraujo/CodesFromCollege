#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "glwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setupUi();
    void setupActions();
    QAction *openAction;
    glWidget* widget;

private slots:
    void addFile();


};

#endif // MAINWINDOW_H
