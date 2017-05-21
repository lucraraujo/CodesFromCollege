#ifndef BRICK_H
#define BRICK_H

#include <QImage>
#include <QRect>

class Brick
{

  public:
    Brick(int, int); //recebe x, y, posicao do vetor, i e j
    ~Brick();

  public:
    void resetState();
    bool isDestroyed();
    void setDestroyed(bool);
    QRect getRect();
    void setRect(QRect);
    QImage & getImage();
    void setEspecial(bool esp);
    bool getEspecial();
    void setImage(bool amarelo);
    void setEspecialAumentaPaddle(bool esp);
    bool getEspecialAumentaPaddle();
    void setEspecialDiminuiPaddle(bool esp);
    bool getEspecialDiminuiPaddle();
    void setEspecialDestroi(bool esp);
    bool getEspecialDestroi();
    void autoMove();

  private:
    QImage image;
    QRect rect;
    int position;
    bool destroyed;
    bool especial; //o brick especial só pode ser destruido com duas "boladas"
    bool especialAumentaPaddle; //o brick com essa flag = true aumenta o tamanho do paddle
    bool especialDiminuiPaddle; //o brick com essa flag = true diminui o tamanho do paddle
    bool especialDestroi; //o brick com essa flag = true destroi os bricks ao seu redor
};

#endif
