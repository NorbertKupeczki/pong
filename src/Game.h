
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;

  // Sprites and Textures
  sf::Sprite ball;
  sf::Texture ball_texture;
  sf::Sprite background;
  sf::Texture bg_texture;
  sf::Sprite main_menu_sp;
  sf::Texture main_menu_texture;
  sf::Sprite options_sp;
  sf::Texture options_texture;
  sf::Sprite game_over_sp;
  sf::Texture game_over_texture;

  enum GameType
  {
    PVP = 0,
    PVCPU = 1
  };

  enum GameLength
  {
    SHORT = 7,
    MEDIUM = 11,
    LONG = 15
  };

  enum Balls
  {
    ONE = 1,
    TWO = 2,
    THREE = 3
  };

  enum Scene
  {
    MAIN_MENU = 0,
    OPTIONS = 1,
    START_UP = 2,
    IN_GAME = 3,
    GAME_OVER = 4
  };

  enum GameOptionsSelector
  {
    GAME_TYPE_SELECTED = 0,
    GAME_LENGTH_SELECTED = 1,
    BALLS_SELECTED = 2
  };

  // Game variables
  GameType game_type;
  GameLength game_length;
  Balls number_of_balls;
  Scene active_scene;

};

#endif // PONG_GAME_H
