#include "Ball.h"
#include "Paddles.h"
#include <iostream>
#include <cmath>

Ball::Ball()
{
  std::cout << "Ball appears\n";
  speed = 150.0f;

  if(!ball_texture.loadFromFile("Data/Images/ballGrey.png"))
  {
    std::cout << "ball texture didn't load\n";
  }
  ball_sprite.setTexture(ball_texture);

  y = ((rand() % 8) / 10.0);
  x = sqrt(1-pow(y,2));
  normalise(x,y);
  randomiseDirection(x,y);
}

Ball::~Ball()
{
  std::cout << "Ball object removed\n";
}

float Ball::getSpeed()
{
  return speed;
}

void Ball::normalise(float& x, float& y)
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
    wallBounce(y);
    return true;
  }

  if (ball_sprite.getPosition().x < p1.getPosition().x + p1.getLocalBounds().width &&
      ball_sprite.getPosition().x > p1.getPosition().x &&
      ball_sprite.getPosition().y + 2* ballRadius >= p1.getPosition().y &&
      ball_sprite.getPosition().y <= p1.getPosition().y + p1.getLocalBounds().height)
  {
    std::cout << "Paddle hit\n";
    wallBounce(x);
    return true;
  }

  if (ball_sprite.getPosition().x + 2* ballRadius > p2.getPosition().x &&
      ball_sprite.getPosition().x + 2* ballRadius < p2.getPosition().x + p2.getLocalBounds().width &&
      ball_sprite.getPosition().y + 2* ballRadius >= p2.getPosition().y &&
      ball_sprite.getPosition().y <= p2.getPosition().y + p2.getLocalBounds().height)
  {
    std::cout << "Paddle hit\n";
    wallBounce(x);
    return true;
  }

  return false;
}

void Ball::wallBounce(float& dir)
{
  dir = -1 * dir;
}

void Ball::score()
{
  // To add point to the scoring player's tally based on which side the
  // ball left the field
}