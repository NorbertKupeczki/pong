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

  bool in_play;
  float getSpeed();
  void setSpeed(float speed);
  void increaseSpeed();
  float getX();
  float getY();
  void normalise();
  void randomiseDirection(float& x, float& y);
  bool collisionCheck(sf::RenderWindow& window, sf::Sprite p1, sf::Sprite p2);
  void wallBounce();
  void adjustAngle(sf::Sprite paddle);
  void setStartLocation(float loc);
  float getStartLocation();

 private:

  float ball_speed;
  float x;
  float y;

  float y_loc;

};

#endif // PONG_BALL_H
