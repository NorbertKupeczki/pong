#include "Ball.h"
#include <iostream>
#include <cmath>

Ball::Ball()
{
  std::cout << "Ball appears\n";
  ball_speed = 0.0f;

  if(!ball_texture.loadFromFile("Data/Images/ballGrey.png"))
  {
    std::cout << "ball texture didn't load\n";
  }
  ball_sprite.setTexture(ball_texture);

  y = ((rand() % 8) / 10.0);
  x = sqrt(1-pow(y,2));
  normalise();
  randomiseDirection(x,y);

  in_play = true;
}

Ball::~Ball()
{
  std::cout << "Ball object removed\n";
}

float Ball::getSpeed()
{
  return ball_speed;
}

void Ball::setSpeed(float speed)
{
  ball_speed = speed;
}

void Ball::increaseSpeed()
{
  ball_speed += 20.0;
  std::cout << "New speed: " << ball_speed << "\n";
}

void Ball::normalise()
{
  float magnitude = sqrt(pow(x,2) + pow(y,2));
  x = x/magnitude;
  y = y/magnitude;
  std::cout << "X=" << x << " Y=" << y << "\n";
}

void Ball::randomiseDirection(float& x_dir, float& y_dir)
{
  if (rand() % 2 == 1)
  {
    x_dir = -1.0 * x_dir;
  }
  if (rand() % 2 == 1)
  {
    y_dir = -1.0 * y_dir;
  }
}

float Ball::getX()
{
  return x;
}

float Ball::getY()
{
  return y;
}

bool Ball::collisionCheck(sf::RenderWindow& window, sf::Sprite p1, sf::Sprite p2)
{
  float ballRadius = ball_sprite.getLocalBounds().width / 2;

  if ((y < 0.0 && ball_sprite.getPosition().y <= 0) ||
      (y > 0.0 && ball_sprite.getPosition().y +
       ball_sprite.getLocalBounds().height >= window.getSize().y))
  {
    wallBounce();
    return true;
  }

  if (ball_sprite.getPosition().x < p1.getPosition().x + p1.getLocalBounds().width &&
      ball_sprite.getPosition().x > p1.getPosition().x &&
      ball_sprite.getPosition().y + 2* ballRadius >= p1.getPosition().y &&
      ball_sprite.getPosition().y <= p1.getPosition().y + p1.getLocalBounds().height &&
      x < 0.0)
  {
    adjustAngle(p1);
    increaseSpeed();
    return true;
  }

  if (ball_sprite.getPosition().x + 2* ballRadius > p2.getPosition().x &&
      ball_sprite.getPosition().x + 2* ballRadius < p2.getPosition().x + p2.getLocalBounds().width &&
      ball_sprite.getPosition().y + 2* ballRadius >= p2.getPosition().y &&
      ball_sprite.getPosition().y <= p2.getPosition().y + p2.getLocalBounds().height &&
      x > 0.0)
  {
    adjustAngle(p2);
    increaseSpeed();
    return true;
  }

  return false;
}

void Ball::wallBounce()
{
  y = -1.0 * y;
}

void Ball::adjustAngle(sf::Sprite paddle)
{
  float ball_mid = ball_sprite.getPosition().y + ball_sprite.getLocalBounds().height / 2;
  float paddle_mid = paddle.getPosition().y + paddle.getLocalBounds().height / 2;
  float dist = paddle_mid - ball_mid;
  float new_y = dist / (paddle.getLocalBounds().height / 2 + ball_sprite.getLocalBounds().height / 2)
                * (1 / sqrt(2)) * -1.0;
  y = new_y;
  if (x < 0.0)
  {
    x = sqrt(1-pow(new_y,2));
  }
  else
  {
    x = -1.0 * sqrt(1-pow(new_y,2));
  }
  normalise();
}

void Ball::setStartLocation(float loc)
{
  y_loc = loc;
}

float Ball::getStartLocation()
{
  return y_loc;
}