#include "breakout.h"
#include <QPainter>
#include <QApplication>
#include <QHBoxLayout>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
#include <QRect>

Breakout::Breakout(QWidget *parent)
    : QWidget(parent)
{

  x = 0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  ball = new Ball();
  paddle = new Paddle(":/pegabola.png");
  tempo = new QTime();

  int k = 0;
  for (int i=0; i<5; i++) {
    for (int j=0; j<6; j++) {
      if(k == 0)
         bricks[k] = new Brick(0, 30);
      else if(k == 5)
          bricks[k] = new Brick(250, 110);
      else
        bricks[k] = new Brick(j*40+30, i*10+50);

      k++;
    }
  }

  sorteioTijolosEspeciais();

  numBricks = 0; //inicialmente, nenhum tijolo destruído
  lcd = new QLCDNumber();
  lcdNumVidas = new QLCDNumber();
  vidas = 2;
}

Breakout::~Breakout() {
 delete ball;
 delete paddle;
 delete lcd;
 delete lcdNumVidas;
 for (int i=0; i<30; i++) {
   delete bricks[i];
 }
}

void Breakout::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  if (gameOver) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Game Over");
  }
  else if(gameWon) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Victory");
  }
  else {
    lcd->display(numBricks);
    lcdNumVidas->display(vidas);

    painter.drawImage(ball->getRect(),
        ball->getImage());
    painter.drawImage(paddle->getRect(),
        paddle->getImage());

    for (int i=0; i<30; i++) {
        if (!bricks[i]->isDestroyed())
            painter.drawImage(bricks[i]->getRect(), bricks[i]->getImage());
    }

    if(tempo->elapsed() == 20000) //se já passaram 20 segundos, volta o paddle para o tamanho original
    {
        int x = paddle->getRect().x();
        delete paddle;
        paddle = new Paddle(":/pegabola.png", x); //cria o paddle na posição que ele estava
        delete tempo;
        tempo = new QTime();
    }
  }
}

void Breakout::timerEvent(QTimerEvent *event)
{
  bricks[0]->autoMove();
  bricks[5]->autoMove();
  ball->autoMove();
  checkCollision();
  repaint();
}

void Breakout::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
       {
         int x = paddle->getRect().x();
        for (int i=1; i<=5; i++)
          paddle->moveLeft(x--);
        break;
       }
    case Qt::Key_Right:
        {
          int x = paddle->getRect().x();
          for (int i=1; i<=5; i++)
            paddle->moveRight(x++);
        }
        break;
    case Qt::Key_P:
        {
          pauseGame();
        }
        break;
    case Qt::Key_Space:
        {
          startGame();
        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
    case Qt::Key_Q:
        {
          qApp->exit();
        }
    case Qt::Key_R:
        {
          restartGame();
        }
    default:
        QWidget::keyPressEvent(event);
    }
}

void Breakout::startGame()
{
   if (!gameStarted) {
    ball->resetState();
    paddle->resetState();

    for (int i=0; i<30; i++) {
      bricks[i]->setDestroyed(FALSE);
    }
    gameOver = FALSE;
    gameWon = FALSE;
    gameStarted = TRUE;
    timerId = startTimer(10);
  }
}

void Breakout::pauseGame()
{
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId);
   }
}

void Breakout::stopGame()
{
  killTimer(timerId);
  gameOver = TRUE;
  gameStarted = FALSE;
  //lcd->close();
}

void Breakout::victory()
{
  killTimer(timerId);
  gameWon = TRUE;
  gameStarted = FALSE;
}

void Breakout::checkCollision()
{

  if (ball->getRect().bottom() > 400) //quando a bola cai
  {
    if(vidas == 0)
        stopGame();
    else
    {
        --vidas;
        ball->resetState();
        paddle->resetState();
        startGame();
    }
  }
  for (int i=0, j=0; i<30; i++) {
    if (bricks[i]->isDestroyed()) {
      j++;
    }
    if (j==30)
      victory();
  }

  if ((ball->getRect()).intersects(paddle->getRect())) {

    int paddleLPos = paddle->getRect().left();
    int ballLPos = ball->getRect().left();

    int first = paddleLPos + 8;
    int second = paddleLPos + 16;
    int third = paddleLPos + 24;
    int fourth = paddleLPos + 32;

    if (ballLPos < first) {
      ball->setXDir(-1);
      ball->setYDir(-1);
    }

    if (ballLPos >= first && ballLPos < second) {
      ball->setXDir(-1);
      ball->setYDir(-1*ball->getYDir());
    }

    if (ballLPos >= second && ballLPos < third) {
       ball->setXDir(0);
       ball->setYDir(-1);
    }

    if (ballLPos >= third && ballLPos < fourth) {
       ball->setXDir(1);
       ball->setYDir(-1*ball->getYDir());
    }

    if (ballLPos > fourth) {
      ball->setXDir(1);
      ball->setYDir(-1);
    }


  }


  for (int i=0; i<30; i++) {
    if ((ball->getRect()).intersects(bricks[i]->getRect())) {

      int ballLeft = ball->getRect().left();
      int ballHeight = ball->getRect().height();
      int ballWidth = ball->getRect().width();
      int ballTop = ball->getRect().top();

      QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
      QPoint pointLeft(ballLeft - 1, ballTop);
      QPoint pointTop(ballLeft, ballTop -1);
      QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

      if (!bricks[i]->isDestroyed()) {
        if(bricks[i]->getRect().contains(pointRight)) {
           ball->setXDir(-1);
        }

        else if(bricks[i]->getRect().contains(pointLeft)) {
           ball->setXDir(1);
        }

        if(bricks[i]->getRect().contains(pointTop)) {
           ball->setYDir(1);
        }

        else if(bricks[i]->getRect().contains(pointBottom)) {
           ball->setYDir(-1);
        }

        if(bricks[i]->getEspecialAumentaPaddle()) //se o tijolo for especial para aumentar o tamanho do paddle
        {
            int x = paddle->getRect().x();
            delete paddle;
            paddle = new Paddle(":/pegabolaMaior.png", x); //cria o paddle na posição que ele estava
            bricks[i]->setEspecialAumentaPaddle(false);

            //calcular um tempo para o paddle votar ao tamanho original...
            tempo->start();
        }

        if(bricks[i]->getEspecialDiminuiPaddle()) //se o tijolo for especial para diminuir o tamanho do paddle
        {
            int x = paddle->getRect().x();
            delete paddle;
            paddle = new Paddle(":/pegabolaMenor.png", x); //cria o paddle na posição que ele estava
            bricks[i]->setEspecialDiminuiPaddle(false);

            //calcular um tempo para o paddle votar ao tamanho original...
            tempo->start();
        }

        if(bricks[i]->getEspecialDestroi()) //se o tijolo for especial para destruir todos ao seu redor
            destroiBricksRedor(i); //destroi os bricks ao redor do brick de indice i

        if(bricks[i]->getEspecial()) //se o tijolo for amarelo, nao é destruido e vira um tijolo normal
        {
            bricks[i]->setImage(false);
            bricks[i]->setEspecial(false);
        }
        else
        {
            bricks[i]->setDestroyed(TRUE);
            ++numBricks;
        }
      }
    }
  }

}

QLCDNumber* Breakout::getlcd()
{
    return lcd;
}

QLCDNumber* Breakout::getlcdNumVidas()
{
    return lcdNumVidas;
}

void Breakout::restartGame()
{
    stopGame();
    numBricks = 0;
    vidas = 2;
    delete paddle;
    paddle = new Paddle(":/pegabola.png");
    delete tempo;
    tempo = new QTime();

    for(int i = 0;i < 30;++i) //setar todos os tijolos como não especiais e a imagem como sendo o brick vermelho
    {
        bricks[i]->setEspecial(false);
        bricks[i]->setEspecialAumentaPaddle(false);
        bricks[i]->setEspecialDiminuiPaddle(false);
        bricks[i]->setEspecialDestroi(false);
        bricks[i]->setImage(false);
    }

    sorteioTijolosEspeciais(); //recalcular os tijolos especiais
    startGame();
}

void Breakout::sorteioTijolosEspeciais()
{
    //calculando os tijolos que serão especiais
    for(int i = 0;i < 4;++i)
    {
        int num1 = rand() % 30;
        bricks[num1]->setEspecial(true);
        bricks[num1]->setImage(true);
    }

    //calculando tijolos que irão aumentar ou diminuir o tamanho do paddle
    for(int i = 0;i < 2;++i)
    {
        int num1 = rand() % 30;
        int num2 = rand() % 30;
        bricks[num1]->setEspecialAumentaPaddle(true);
        bricks[num2]->setEspecialDiminuiPaddle(true);
        //bricks[num1]->setImage(true); //tirar...
    }

    //calcula o tijolo que ira destruir todos ao seu redor
    int num1 = rand() % 30;
    bricks[num1]->setEspecialDestroi(true);
    //bricks[num1]->setImage(true); //tirar...
}

void Breakout::mousePressEvent(QMouseEvent *event)
{
    switch(event->buttons())
    {
        case Qt::LeftButton:
            if(gameStarted)
                pauseGame();
            break;
        case Qt::RightButton:
            imprimeAtributos();
            break;
    }
}

void Breakout::imprimeAtributos()
{
    if(gameStarted)
        if(!paused)
            pauseGame();
    QMessageBox::information(this, tr("Informações dos Objetos"),
                                                         tr("Posição do Paddle: %1 \n"
                                                            "Velocidade do Paddle:  \n"
                                                            "Velocidade da Bola: %2 \n"
                                                            "Tijolos Destruídos: %3 \n"
                                                            "Bricks: %4 %5 \n").arg(paddle->getRect().x()).arg(ball->getSpeed()).arg(numBricks).arg(bricks[0]->getRect().y()).arg(bricks[29]->getRect().y()));

    pauseGame(); //reinicia o jogo apos clicar no Ok do message box
}

int Breakout::getBrickPorCoordenada(int x, int y)
{
    for(int i = 0;i < 30;++i)
        if(bricks[i]->getRect().x() == x && bricks[i]->getRect().y() == y)
            return i; //retorna a posição do brick a ser deletado
}

void Breakout::destroiBricksRedor(int i)
{
    int x = bricks[i]->getRect().x();
    int y = bricks[i]->getRect().y();

    if(x != 30) //x = 30 é o primeiro tijolo da fileira...ou seja, não existe nenhum à sua esquerda
    {
        int xBrickLadoEsquerdo = x - 40;
        int yBrickLadoEsquerdo = y;
        int indice = getBrickPorCoordenada(xBrickLadoEsquerdo, yBrickLadoEsquerdo);
        bricks[indice]->setDestroyed(TRUE);
        ++numBricks;
    }

    if(x != 230) //x = 230 é o ultimo tijolo da fileira...ou seja, não existe nenhum à sua direita
    {
        int xBrickLadoDireito = x + 40;
        int yBrickLadoDireito = y;
        int indice = getBrickPorCoordenada(xBrickLadoDireito, yBrickLadoDireito);
        bricks[indice]->setDestroyed(TRUE);
        ++numBricks;
    }

    if(y != 50) //y = 50 é a fileira de cima(primeira)...ou seja, acima dela não existe nenhum tijolo
    {
        int xBrickCima = x;
        int yBrickCima = y - 10;
        int indice = getBrickPorCoordenada(xBrickCima, yBrickCima);
        bricks[indice]->setDestroyed(TRUE);
        ++numBricks;
    }

    if(y != 90) //y = 90 é a fileira de baixo(ultima)...ou seja, abaixo dela não existe nenhum tijolo
    {
        int xBrickBaixo = x;
        int yBrickBaixo = y + 10;
        int indice = getBrickPorCoordenada(xBrickBaixo, yBrickBaixo);
        bricks[indice]->setDestroyed(TRUE);
        ++numBricks;
    }
}
