#include "mainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QApplication>
#include <QTextCodec>

mainWindow::mainWindow()
{
    /*Passa a reconhecer os caracteres especiais*/
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    breakout = new Breakout();
    breakout->setFixedSize(300,400);

    setupActions();
    setupMenu();
    setupUi();
}

mainWindow::~mainWindow()
{
    delete breakout;
}

void mainWindow::setupUi()
{
    QLabel* label = new QLabel("Tijolos Quebrados");
    QLabel* label1 = new QLabel("Vidas");

    QHBoxLayout* layout1 = new QHBoxLayout();
    layout1->addWidget(breakout->getlcd());
    layout1->addWidget(label);
    layout1->addStretch();
    layout1->addWidget(breakout->getlcdNumVidas());
    layout1->addWidget(label1);

    QVBoxLayout* layout2 = new QVBoxLayout();
    layout2->addLayout(layout1);
    layout2->addWidget(breakout);

    QWidget* widget = new QWidget();
    widget->setLayout(layout2);
    breakout->setFocusPolicy(Qt::StrongFocus);
    setCentralWidget(widget);
}

void mainWindow::setupMenu()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("&Opções"));
    fileMenu->addAction(playAction);
    fileMenu->addAction(pause);
    fileMenu->addAction(restart);
    fileMenu->addAction(exit);

    QMenu *aboutMenu = menuBar()->addMenu(tr("A&juda"));
    aboutMenu->addAction(atributos);
    aboutMenu->addAction(aboutQtAction);
}

void mainWindow::setupActions()
{
    playAction = new QAction(tr("&Iniciar"), this);
    pause = new QAction(tr("&Pausar"), this);
    restart = new QAction(tr("&Restart"), this);
    exit = new QAction(tr("&Sair"), this);
    aboutQtAction = new QAction(tr("&Sobre QT"), this);
    atributos =  new QAction(tr("&Atributos dos Objetos"), this);

    connect(playAction, SIGNAL(triggered()), breakout, SLOT(startGame()));
    connect(pause, SIGNAL(triggered()), breakout, SLOT(pauseGame()));
    connect(restart, SIGNAL(triggered()), breakout, SLOT(restartGame()));
    connect(exit, SIGNAL(triggered()), this, SLOT(close()));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(atributos, SIGNAL(triggered()), breakout, SLOT(imprimeAtributos()));
}
