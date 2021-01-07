
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddles.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  void initTextures();
  bool init();
  void update(float dt);
  void render();
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);

 private:
  sf::RenderWindow& window;

  // Sprites and Textures
  sf::Sprite background;
  sf::Texture bg_texture;
  // Main menu sprites and textures
  sf::Sprite main_menu_sp;
  sf::Texture main_menu_texture;
  sf::Sprite start_game;
  sf::Texture start_game_active;
  sf::Texture start_game_inactive;
  sf::Sprite options;
  sf::Texture options_active;
  sf::Texture options_inactive;
  sf::Sprite quit_game;
  sf::Texture quit_game_active;
  sf::Texture quit_game_inactive;
  // Options menu sprites and textures
  sf::Sprite options_menu_sp;
  sf::Texture options_menu_texture;
  sf::Texture one_active;
  sf::Texture one_inactive;
  sf::Sprite one_button;
  sf::Texture two_active;
  sf::Texture two_inactive;
  sf::Sprite two_button;
  sf::Texture three_active;
  sf::Texture three_inactive;
  sf::Sprite three_button;
  sf::Texture seven_active;
  sf::Texture seven_inactive;
  sf::Sprite seven_button;
  sf::Texture eleven_active;
  sf::Texture eleven_inactive;
  sf::Sprite eleven_button;
  sf::Texture fifteen_active;
  sf::Texture fifteen_inactive;
  sf::Sprite fifteen_button;
  sf::Texture pvp_active;
  sf::Texture pvp_inactive;
  sf::Sprite pvp_button;
  sf::Texture pvai_active;
  sf::Texture pvai_inactive;
  sf::Sprite pvai_button;
  sf::Texture selection_box_texture;
  sf::Sprite selection_box_sp;
  // Game over menu sprites and textures
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

  enum MainMenuSelected
  {
    START_GAME = 0,
    OPTIONS_MENU = 1,
    QUIT_GAME = 2
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
  GameOptionsSelector selected_game_option;
  MainMenuSelected selected_menu_option;

  Ball* balls = nullptr;
  Paddle p1_paddle;
  Paddle p2_paddle;

  float paddle_offset = 40.0;

};

#endif // PONG_GAME_H
