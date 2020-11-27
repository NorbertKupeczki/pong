#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
 public:
  Ball(sf::RenderWindow& window);
  ~Ball();

 private:
  float x;
  float y;
  float speed;
  float radius;

  bool collisionCheck();
  void changeDirection();
  void score();
  void spawnTheBall();

};

#endif // PONG_BALL_H
