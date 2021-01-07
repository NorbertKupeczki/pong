#ifndef PONG_PADDLES_H
#define PONG_PADDLES_H

#include <SFML/Graphics.hpp>

class Paddle
{
 public:
  Paddle();
  ~Paddle();

  sf::Sprite paddle_sprite;

  int getScore();
  void addScore();

  float getDir();
  void setDir(float dir);

  float getSpeed();

  void setColor(int player);

 private:
  sf::Texture paddle_texture_red;
  sf::Texture paddle_texture_blue;
  int score;
  float paddle_speed;
  float y_dir;

};

#endif // PONG_PADDLES_H
