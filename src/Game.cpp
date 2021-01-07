
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window)
  : window(window)
{
  srand(time(NULL));
}

Game::~Game()
{
  if (balls != nullptr)
  {
    delete[] balls;
  }
  std::cout << "Game closing\n";
}

void Game::initTextures()
{
  if(!bg_texture.loadFromFile("Data/Images/bground.png"))
  {
    std::cout << "background texture didn't load\n";
  }
  background.setTexture(bg_texture);

  if(!main_menu_texture.loadFromFile("Data/Images/main_menu.png"))
  {
    std::cout << "Main menu texture didn't load\n";
  }
  main_menu_sp.setTexture(main_menu_texture);
  main_menu_sp.setPosition(
    window.getSize().x / 2 - main_menu_sp.getGlobalBounds().width / 2,
    window.getSize().y / 2 - main_menu_sp.getGlobalBounds().height / 2);

  if(!start_game_active.loadFromFile("Data/Images/start_active.png"))
  {
    std::cout << "Start game button (active) texture didn't load\n";
  }
  if(!start_game_inactive.loadFromFile("Data/Images/start_inactive.png"))
  {
    std::cout << "Start game button (inactive) texture didn't load\n";
  }
  start_game.setTexture(start_game_active);
  start_game.setPosition(
    window.getSize().x / 2 - start_game.getGlobalBounds().width / 2,
    window.getSize().y / 2 - start_game.getGlobalBounds().height / 2 - 74);

  if(!options_active.loadFromFile("Data/Images/options_active.png"))
  {
    std::cout << "Options button (active) texture didn't load\n";
  }
  if(!options_inactive.loadFromFile("Data/Images/options_inactive.png"))
  {
    std::cout << "Options button (inactive) texture didn't load\n";
  }
  options.setTexture(options_inactive);
  options.setPosition(
    window.getSize().x / 2 - options.getGlobalBounds().width / 2,
    window.getSize().y / 2 - options.getGlobalBounds().height / 2);

  if(!quit_game_active.loadFromFile("Data/Images/quit_active.png"))
  {
    std::cout << "Quit button (active) texture didn't load\n";
  }
  if(!quit_game_inactive.loadFromFile("Data/Images/quit_inactive.png"))
  {
    std::cout << "Quit button (inactive) texture didn't load\n";
  }
  quit_game.setTexture(quit_game_inactive);
  quit_game.setPosition(
    window.getSize().x / 2 - quit_game.getGlobalBounds().width / 2,
    window.getSize().y / 2 - quit_game.getGlobalBounds().height / 2 + 74);

  if(!options_menu_texture.loadFromFile("Data/Images/options_menu.png"))
  {
    std::cout << "Options menu texture didn't load\n";
  }
  options_menu_sp.setTexture(options_menu_texture);
  options_menu_sp.setPosition(
    window.getSize().x / 2 - options_menu_sp.getGlobalBounds().width / 2,
    window.getSize().y / 2 - options_menu_sp.getGlobalBounds().height / 2);

  if(!seven_active.loadFromFile("Data/Images/7_active.png"))
  {
    std::cout << "7 button (active) texture didn't load\n";
  }
  if(!seven_inactive.loadFromFile("Data/Images/7_inactive.png"))
  {
    std::cout << "7 button (inactive) texture didn't load\n";
  }
  seven_button.setTexture(seven_inactive);
  seven_button.setPosition(
    window.getSize().x / 2 - seven_button.getGlobalBounds().width / 2 + 39,
    window.getSize().y / 2 - seven_button.getGlobalBounds().height / 2);

  if(!eleven_active.loadFromFile("Data/Images/11_active.png"))
  {
    std::cout << "11 button (active) texture didn't load\n";
  }
  if(!eleven_inactive.loadFromFile("Data/Images/11_inactive.png"))
  {
    std::cout << "11 button (inactive) texture didn't load\n";
  }
  eleven_button.setTexture(eleven_active);
  eleven_button.setPosition(
    window.getSize().x / 2 - eleven_button.getGlobalBounds().width / 2 + 150,
    window.getSize().y / 2 - eleven_button.getGlobalBounds().height / 2);

  if(!fifteen_active.loadFromFile("Data/Images/15_active.png"))
  {
    std::cout << "15 button (active) texture didn't load\n";
  }
  if(!fifteen_inactive.loadFromFile("Data/Images/15_inactive.png"))
  {
    std::cout << "15 button (inactive) texture didn't load\n";
  }
  fifteen_button.setTexture(fifteen_inactive);
  fifteen_button.setPosition(
    window.getSize().x / 2 - fifteen_button.getGlobalBounds().width / 2 + 261,
    window.getSize().y / 2 - fifteen_button.getGlobalBounds().height / 2);

  if(!one_active.loadFromFile("Data/Images/1_active.png"))
  {
    std::cout << "1 button (active) texture didn't load\n";
  }
  if(!one_inactive.loadFromFile("Data/Images/1_inactive.png"))
  {
    std::cout << "1 button (inactive) texture didn't load\n";
  }
  one_button.setTexture(one_active);
  one_button.setPosition(
    window.getSize().x / 2 - one_button.getGlobalBounds().width / 2 + 39,
    window.getSize().y / 2 - one_button.getGlobalBounds().height / 2 + 80);

  if(!two_active.loadFromFile("Data/Images/2_active.png"))
  {
    std::cout << "2 button (active) texture didn't load\n";
  }
  if(!two_inactive.loadFromFile("Data/Images/2_inactive.png"))
  {
    std::cout << "11 button (inactive) texture didn't load\n";
  }
  two_button.setTexture(two_inactive);
  two_button.setPosition(
    window.getSize().x / 2 - two_button.getGlobalBounds().width / 2 + 150,
    window.getSize().y / 2 - two_button.getGlobalBounds().height / 2 + 80);

  if(!three_active.loadFromFile("Data/Images/3_active.png"))
  {
    std::cout << "3 button (active) texture didn't load\n";
  }
  if(!three_inactive.loadFromFile("Data/Images/3_inactive.png"))
  {
    std::cout << "3 button (inactive) texture didn't load\n";
  }
  three_button.setTexture(three_inactive);
  three_button.setPosition(
    window.getSize().x / 2 - three_button.getGlobalBounds().width / 2 + 261,
    window.getSize().y / 2 - three_button.getGlobalBounds().height / 2 + 80);

  if(!pvp_active.loadFromFile("Data/Images/pvp_active.png"))
  {
    std::cout << "PvP button (active) texture didn't load\n";
  }
  if(!pvp_inactive.loadFromFile("Data/Images/pvp_inactive.png"))
  {
    std::cout << "PvP button (inactive) texture didn't load\n";
  }
  pvp_button.setTexture(pvp_active);
  pvp_button.setPosition(
    window.getSize().x / 2 - pvp_button.getGlobalBounds().width / 2 - 161,
    window.getSize().y / 2 - pvp_button.getGlobalBounds().height / 2 - 80);

  if(!pvai_active.loadFromFile("Data/Images/pvai_active.png"))
  {
    std::cout << "PvAI button (active) texture didn't load\n";
  }
  if(!pvai_inactive.loadFromFile("Data/Images/pvai_inactive.png"))
  {
    std::cout << "PvAI button (inactive) texture didn't load\n";
  }
  pvai_button.setTexture(pvai_inactive);
  pvai_button.setPosition(
    window.getSize().x / 2 - pvai_button.getGlobalBounds().width / 2 + 161,
    window.getSize().y / 2 - pvai_button.getGlobalBounds().height / 2 - 80);

  if(!selection_box_texture.loadFromFile("Data/Images/selection_box.png"))
  {
    std::cout << "Selection box button texture didn't load\n";
  }
  selection_box_sp.setTexture(selection_box_texture);
  selection_box_sp.setPosition(
    window.getSize().x / 2 - selection_box_sp.getGlobalBounds().width / 2,
    window.getSize().y / 2 - selection_box_sp.getGlobalBounds().height / 2 - 80);
}

bool Game::init()
{
  initTextures();

  number_of_balls = ONE;
  game_length = MEDIUM;
  game_type = PVP;
  active_scene = MAIN_MENU;
  selected_game_option = GAME_TYPE_SELECTED;
  selected_menu_option = START_GAME;

  p1_paddle.setColor(1);
  p1_paddle.paddle_sprite.setPosition(
    paddle_offset - p1_paddle.paddle_sprite.getLocalBounds().width / 2,
    window.getSize().y / 2 - p1_paddle.paddle_sprite.getLocalBounds().height /2
    );

  p2_paddle.setColor(2);
  p2_paddle.paddle_sprite.setPosition(
    window.getSize().x - paddle_offset - p2_paddle.paddle_sprite.getLocalBounds().width / 2,
    window.getSize().y / 2 - p2_paddle.paddle_sprite.getLocalBounds().height /2
  );

  return true;
}

void Game::update(float dt)
{
  if (active_scene == START_UP)
  {
    balls = new Ball[number_of_balls];
    for (int i = 0; i < number_of_balls; i++)
    {
      balls[i].ball_sprite.setPosition(
        window.getSize().x / 2 - balls[i].ball_sprite.getGlobalBounds().width / 2,
        250 + i*100
        );
    }

    active_scene = IN_GAME;
  }
  else if (active_scene == IN_GAME)
  {
    for (int i = 0; i < number_of_balls; i++)
    {
      balls[i].ball_sprite.move
        (balls[i].getX() * balls[i].getSpeed() * dt,
         balls[i].getY() * balls[i].getSpeed() * dt);
    }

    for (int i = 0; i < number_of_balls; i++)
    {
      balls[i].collisionCheck(window,p1_paddle.paddle_sprite,p2_paddle.paddle_sprite);
    }

    p1_paddle.paddle_sprite.move(
      0.0,
      p1_paddle.getDir() * dt * p1_paddle.getSpeed()
    );
    if (p1_paddle.paddle_sprite.getPosition().y <= 0)
    {
      p1_paddle.paddle_sprite.setPosition(
        paddle_offset - p1_paddle.paddle_sprite.getLocalBounds().width / 2,
        0.0
        );
    }
    else if (p1_paddle.paddle_sprite.getPosition().y +
             p1_paddle.paddle_sprite.getLocalBounds().height >= window.getSize().y)
    {
      p1_paddle.paddle_sprite.setPosition(
        paddle_offset - p1_paddle.paddle_sprite.getLocalBounds().width / 2,
        window.getSize().y - p1_paddle.paddle_sprite.getLocalBounds().height
      );
    }

    p2_paddle.paddle_sprite.move(
      0.0,
      p2_paddle.getDir() * dt * p2_paddle.getSpeed()
    );
    if (p2_paddle.paddle_sprite.getPosition().y <= 0)
    {
      p2_paddle.paddle_sprite.setPosition(
        window.getSize().x - paddle_offset - p2_paddle.paddle_sprite.getLocalBounds().width / 2,
        0.0
      );
    }
    else if (p2_paddle.paddle_sprite.getPosition().y +
             p2_paddle.paddle_sprite.getLocalBounds().height >= window.getSize().y)
    {
      p2_paddle.paddle_sprite.setPosition(
        window.getSize().x - paddle_offset - p2_paddle.paddle_sprite.getLocalBounds().width / 2,
        window.getSize().y - p2_paddle.paddle_sprite.getLocalBounds().height
      );
    }
  }

}

void Game::render()
{
  window.draw(background);
  window.draw(p1_paddle.paddle_sprite);
  window.draw(p2_paddle.paddle_sprite);

  if (active_scene == MAIN_MENU)
  {
    window.draw(main_menu_sp);
    window.draw(start_game);
    window.draw(options);
    window.draw(quit_game);
  }
  else if (active_scene == OPTIONS)
  {
    window.draw(options_menu_sp);
    window.draw(one_button);
    if (game_type == PVP)
    {
      window.draw(two_button);
      window.draw(three_button);
    }
    window.draw(seven_button);
    window.draw(eleven_button);
    window.draw(fifteen_button);
    window.draw(pvp_button);
    window.draw(pvai_button);
    window.draw(selection_box_sp);
  }
  else if (active_scene == START_UP)
  {
    std::cout << "Starting the game";
  }
  else if (active_scene == IN_GAME)
  {
    for (int i = 0; i < number_of_balls; i++)
    {
      window.draw(balls[i].ball_sprite);
    }
  }
  else if (active_scene == GAME_OVER)
  {
    std::cout << "Game Over";
  }
}

void Game::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Escape)
  {
    window.close();
  }

  if (active_scene == MAIN_MENU)
  {
    if (event.key.code == sf::Keyboard::Up)
    {
      if (selected_menu_option == START_GAME)
      {
        selected_menu_option = QUIT_GAME;
        start_game.setTexture(start_game_inactive);
        quit_game.setTexture(quit_game_active);
      }
      else if (selected_menu_option == OPTIONS_MENU)
      {
        selected_menu_option = START_GAME;
        options.setTexture(options_inactive);
        start_game.setTexture(start_game_active);
      }
      else if (selected_menu_option == QUIT_GAME)
      {
        selected_menu_option = OPTIONS_MENU;
        quit_game.setTexture(quit_game_inactive);
        options.setTexture(options_active);
      }
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
      if (selected_menu_option == START_GAME)
      {
        selected_menu_option = OPTIONS_MENU;
        start_game.setTexture(start_game_inactive);
        options.setTexture(options_active);
      }
      else if (selected_menu_option == OPTIONS_MENU)
      {
        selected_menu_option = QUIT_GAME;
        options.setTexture(options_inactive);
        quit_game.setTexture(quit_game_active);
      }
      else if (selected_menu_option == QUIT_GAME)
      {
        selected_menu_option = START_GAME;
        quit_game.setTexture(quit_game_inactive);
        start_game.setTexture(start_game_active);
      }
    }
    else if (event.key.code == sf::Keyboard::Enter)
    {
      if (selected_menu_option == START_GAME)
      {
        active_scene = START_UP;
      }
      else if (selected_menu_option == OPTIONS_MENU)
      {
        active_scene = OPTIONS;
      }
      else if (selected_menu_option == QUIT_GAME)
      {
        window.close();
      }
    }
  }
  else if (active_scene == OPTIONS)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      active_scene = MAIN_MENU;
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
      if (selected_game_option == GAME_TYPE_SELECTED)
      {
        selected_game_option = BALLS_SELECTED;
        selection_box_sp.move(0.0f,160.0f);
      }
      else if (selected_game_option == GAME_LENGTH_SELECTED)
      {
        selected_game_option = GAME_TYPE_SELECTED;
        selection_box_sp.move(0.0f,-80.0f);
      }
      else if (selected_game_option == BALLS_SELECTED)
      {
        selected_game_option = GAME_LENGTH_SELECTED;
        selection_box_sp.move(0.0f,-80.0f);
      }
    }
    else if (event.key.code == sf::Keyboard::Down)
    {
      if (selected_game_option == GAME_TYPE_SELECTED)
      {
        selected_game_option = GAME_LENGTH_SELECTED;
        selection_box_sp.move(0.0f,80.0f);
      }
      else if (selected_game_option == GAME_LENGTH_SELECTED)
      {
        selected_game_option = BALLS_SELECTED;
        selection_box_sp.move(0.0f,80.0f);
      }
      else if (selected_game_option == BALLS_SELECTED)
      {
        selected_game_option = GAME_TYPE_SELECTED;
        selection_box_sp.move(0.0f,-160.0f);
      }
    }
    else if (event.key.code == sf::Keyboard::Left)
    {
      if (selected_game_option == GAME_TYPE_SELECTED)
      {
        if (game_type == PVP)
        {
          game_type = PVCPU;
          pvp_button.setTexture(pvp_inactive);
          pvai_button.setTexture(pvai_active);

          number_of_balls = ONE;
          one_button.setTexture(one_active);
          two_button.setTexture(two_inactive);
          three_button.setTexture(three_inactive);
        }
        else if (game_type == PVCPU)
        {
          game_type = PVP;
          pvp_button.setTexture(pvp_active);
          pvai_button.setTexture(pvai_inactive);
        }
      }
      else if (selected_game_option == GAME_LENGTH_SELECTED)
      {
        if (game_length == SHORT)
        {
          game_length = LONG;
          seven_button.setTexture(seven_inactive);
          fifteen_button.setTexture(fifteen_active);
        }
        else if (game_length == MEDIUM)
        {
          game_length = SHORT;
          eleven_button.setTexture(eleven_inactive);
          seven_button.setTexture(seven_active);
        }
        else if (game_length == LONG)
        {
          game_length = MEDIUM;
          fifteen_button.setTexture(fifteen_inactive);
          eleven_button.setTexture(eleven_active);
        }
      }
      else if (selected_game_option == BALLS_SELECTED && game_type == PVP)
      {
        if (number_of_balls == ONE)
        {
          number_of_balls = THREE;
          one_button.setTexture(one_inactive);
          three_button.setTexture(three_active);
        }
        else if (number_of_balls == TWO)
        {
          number_of_balls = ONE;
          two_button.setTexture(two_inactive);
          one_button.setTexture(one_active);
        }
        else if (number_of_balls == THREE)
        {
          number_of_balls = TWO;
          three_button.setTexture(three_inactive);
          two_button.setTexture(two_active);
        }
      }
    }
    else if (event.key.code == sf::Keyboard::Right)
    {
      if (selected_game_option == GAME_TYPE_SELECTED)
      {
        if (game_type == PVP)
        {
          game_type = PVCPU;
          pvp_button.setTexture(pvp_inactive);
          pvai_button.setTexture(pvai_active);

          number_of_balls = ONE;
          one_button.setTexture(one_active);
          two_button.setTexture(two_inactive);
          three_button.setTexture(three_inactive);
        }
        else if (game_type == PVCPU)
        {
          game_type = PVP;
          pvp_button.setTexture(pvp_active);
          pvai_button.setTexture(pvai_inactive);
        }
      }
      else if (selected_game_option == GAME_LENGTH_SELECTED)
      {
        if (game_length == SHORT)
        {
          game_length = MEDIUM;
          seven_button.setTexture(seven_inactive);
          eleven_button.setTexture(eleven_active);
        }
        else if (game_length == MEDIUM)
        {
          game_length = LONG;
          eleven_button.setTexture(eleven_inactive);
          fifteen_button.setTexture(fifteen_active);
        }
        else if (game_length == LONG)
        {
          game_length = SHORT;
          fifteen_button.setTexture(fifteen_inactive);
          seven_button.setTexture(seven_active);
        }
      }
      else if (selected_game_option == BALLS_SELECTED && game_type == PVP)
      {
        if (number_of_balls == ONE)
        {
          number_of_balls = TWO;
          one_button.setTexture(one_inactive);
          two_button.setTexture(two_active);
        }
        else if (number_of_balls == TWO)
        {
          number_of_balls = THREE;
          two_button.setTexture(two_inactive);
          three_button.setTexture(three_active);
        }
        else if (number_of_balls == THREE)
        {
          number_of_balls = ONE;
          three_button.setTexture(three_inactive);
          one_button.setTexture(one_active);
        }
      }
    }
  }
  else if (active_scene == IN_GAME)
  {
    if (event.key.code == sf::Keyboard::Q)
    {
      p1_paddle.setDir(-1.0);
    }
    else if (event.key.code == sf::Keyboard::A)
    {
      p1_paddle.setDir(1.0);
    }

    if (event.key.code == sf::Keyboard::O)
    {
      p2_paddle.setDir(-1.0);
    }
    else if (event.key.code == sf::Keyboard::L)
    {
      p2_paddle.setDir(1.0);
    }
  }
}

void Game::keyReleased(sf::Event event)
{
  if (active_scene == IN_GAME)
  {
    if ((event.key.code == sf::Keyboard::Q) ||
        (event.key.code == sf::Keyboard::A))
    {
      p1_paddle.setDir(0.0);
    }
    if ((event.key.code == sf::Keyboard::O) ||
        (event.key.code == sf::Keyboard::L))
    {
      p2_paddle.setDir(0.0);
    }
  }
}

