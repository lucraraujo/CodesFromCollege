#include "brick.h"
#include <iostream>

Brick::Brick(int x, int y) : position(1), especial(false), especialAumentaPaddle(false), especialDestroi(false), especialDiminuiPaddle(false)
{
  image.load(":/brickie.png");
  destroyed = FALSE;
  rect = image.rect();
  rect.translate(x, y);
}

Brick::~Brick() {

    std::cout << "Brick deleted\n";
}

QRect Brick::getRect()
{
  return rect;
}

void Brick::setRect(QRect rct)
{
  rect = rct;
}

QImage & Brick::getImage()
{
  return image;
}

bool Brick::isDestroyed()
{
  return destroyed;
}

void Brick::setDestroyed(bool destr)
{
  destroyed = destr;
}

void Brick::setEspecial(bool esp)
{
    especial = esp;
}

bool Brick::getEspecial()
{
    return especial;
}

void Brick::setImage(bool amarelo)
{
    amarelo ? image.load(":/brickie2.png") : image.load(":/brickie.png");
}

void Brick::setEspecialAumentaPaddle(bool esp)
{
    especialAumentaPaddle = esp;
}

bool Brick::getEspecialAumentaPaddle()
{
    return especialAumentaPaddle;
}

void Brick::setEspecialDiminuiPaddle(bool esp)
{
    especialDiminuiPaddle = esp;
}

bool Brick::getEspecialDiminuiPaddle()
{
    return especialDiminuiPaddle;
}

void Brick::setEspecialDestroi(bool esp)
{
    especialDestroi = esp;
}

bool Brick::getEspecialDestroi()
{
    return especialDestroi;
}

void Brick::autoMove()
{
 rect.translate(position,0);

  if (rect.right() == 300 || rect.left() == 0) {
    position = -position;
  }
}
