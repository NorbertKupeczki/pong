
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
  std::cout << "Game closing";
}

bool Game::init()
{
  if(!bg_texture.loadFromFile("Data/Images/bground.png"))
  {
    std::cout << "background texture didn't load\n";
  }
  background.setTexture(bg_texture);

  number_of_balls = ONE;
  game_length = MEDIUM;
  game_type = PVP;
  active_scene = MAIN_MENU;

  return true;
}

void Game::update(float dt)
{


}

void Game::render()
{
  window.draw(background);

  switch (active_scene) // Placeholders, needs to add objects to render
  {
    case MAIN_MENU:
    {
      std::cout << "Main menu";
    }
    case OPTIONS:
    {
      std::cout << "Option";
    }
    case START_UP:
    {
      std::cout << "Starting the game";
    }
    case IN_GAME:
    {
      std::cout << "In game";
    }
    case GAME_OVER:
    {
      std::cout << "Game over";
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Escape)
  {
    window.close();
  }
}


