#include "Paddles.h"
#include <iostream>

Paddle::Paddle()
{
  std::cout << "Paddle created\n";

  if(!paddle_texture_red.loadFromFile("Data/Images/paddleRed.png"))
  {
    std::cout << "Red paddle texture didn't load\n";
  }
  if(!paddle_texture_blue.loadFromFile("Data/Images/paddleBlue.png"))
  {
    std::cout << "Red paddle texture didn't load\n";
  }
  y_dir = 0.0f;
  paddle_speed = 200.0f;
}

Paddle::~Paddle()
{
  std::cout << "Paddle removed\n";
}

int Paddle::getScore()
{
  return score;
}

void Paddle::addScore()
{
  score++;
}

void Paddle::setColor(int player)
{
  if (player == 1)
  {
    paddle_sprite.setTexture(paddle_texture_blue);
  }
  else if (player == 2)
  {
    paddle_sprite.setTexture(paddle_texture_red);
  }
}

float Paddle::getDir()
{
  return y_dir;
}

void Paddle::setDir(float dir)
{
  if (dir > 0.0)
  {
    y_dir = 1.0;
  }
  else if (dir < 0.0)
  {
    y_dir = -1.0;
  }
  else if (dir == 0.0)
  {
    y_dir = 0.0;
  }
}

float Paddle::getSpeed()
{
  return paddle_speed;
}