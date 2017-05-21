#include "mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    widget = 0;
    setCentralWidget(widget);
    setupActions();
    setupUi();

}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi()
{
    QMenu *fileMenu = QMainWindow::menuBar()->addMenu(tr("&Arquivo"));
    fileMenu->addAction(openAction);
    //fileMenu->addSeparator();
    //fileMenu->addAction(exitAction);
}

void MainWindow::setupActions()
{
    openAction = new QAction(tr("&Adicionar Arquivos"), this);
    openAction->setShortcut(tr("Ctrl+O"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(addFile()));
}

void MainWindow::addFile()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                      tr("Selecione os Arquivos de Música"),
                                                      QDesktopServices::storageLocation(QDesktopServices::ApplicationsLocation),
                                                      tr("Aquivos OFF (*.off)"));
    widget = new glWidget(file.toLocal8Bit().data());

}

