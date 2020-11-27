#include "Ball.h"
#include <iostream>

Ball::Ball(sf::RenderWindow& window)
{
  radius = 10.0f;
  x = window.getSize().x - radius;
  y = window.getSize().y - radius;
  speed = 100.0f;
}

Ball::~Ball()
{
  std::cout << "Ball is out of play area";
}

bool Ball::collisionCheck()
{
  // Function to check whether the ball collided with a wall or paddle
  return false;
}

void Ball::changeDirection()
{
  // Function to set new direction to the direction after a collision
}

void Ball::score()
{
  // To add point to the scoring player's tally based on which side the
  // ball left the field
}

void Ball::spawnTheBall()
{
  // Function to spawn the ball
}