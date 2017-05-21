#include "paddle.h"
#include <iostream>

Paddle::Paddle(QString caminho, int x)
{
  image.load(caminho);

  rect = image.rect();
  resetState(x);
}

Paddle::~Paddle()
{
    std::cout << "paddle deleted\n";
}

void Paddle::moveLeft(int left)
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void Paddle::moveRight(int right)
{
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

void Paddle::resetState(int x)
{
  rect.moveTo(x, 360);
}

QRect Paddle::getRect()
{
  return rect;
}

QImage & Paddle::getImage()
{
  return image;
}
