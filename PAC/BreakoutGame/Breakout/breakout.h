#ifndef BREAKOUT_H
#define BREAKOUT_H

#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include <QWidget>
#include <QKeyEvent>
#include <QLCDNumber>
#include <QTime>


class Breakout : public QWidget
{
  Q_OBJECT

  public:
    Breakout(QWidget *parent = 0);
    ~Breakout();
    QLCDNumber* getlcd();
    QLCDNumber* getlcdNumVidas();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void victory();
    void checkCollision();
    void stopGame();
    void sorteioTijolosEspeciais();
    int  getBrickPorCoordenada(int x, int y); //retorna o indice do brick no vetor
    void destroiBricksRedor(int); //destroi os bricks ao redor de um brick...recebe o indice do brick especial como parametro


  protected slots:
    void startGame();
    void pauseGame();
    void restartGame();
    void imprimeAtributos();

  private:
    int x;
    int timerId;
    Ball *ball;
    Paddle *paddle;
    Brick * bricks[30];
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    int numBricks; //armazena o numero de bricks destruidos
    QLCDNumber* lcd; //lcd que mostra quantos tijolos foram destruidos
    int vidas; //numero de vidas restantes
    QLCDNumber* lcdNumVidas; //lcd que mostra numero de vidas
    QTime* tempo; //tempo passado desde que o paddle aumentou ou diminuiu de tamanho
};

#endif
