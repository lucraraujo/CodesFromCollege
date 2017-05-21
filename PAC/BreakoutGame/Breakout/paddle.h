#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>
#include <QString>

class Paddle
{

  public:
    Paddle(QString, int x = 100); //recebe o caminho da imagem
    ~Paddle();

  public:
    void resetState(int x = 100); //recebe a coordenada x
    void moveLeft(int);
    void moveRight(int);
    QRect getRect();
    QImage & getImage();

  private:
    QImage image;
    QRect rect;

};

#endif
