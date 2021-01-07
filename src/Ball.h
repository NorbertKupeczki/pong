#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
 public:
  Ball();
  ~Ball();

  sf::Sprite ball_sprite;
  sf::Texture ball_texture;

  float getSpeed();

  float getX();
  float getY();
  void normalise(float& x,float& y);
  void randomiseDirection(float& x, float& y);

  bool collisionCheck(sf::RenderWindow& window, sf::Sprite p1, sf::Sprite p2);
  void wallBounce(float& y);
  void score();

 private:

  float speed;
  float x;
  float y;

};

#endif // PONG_BALL_H
