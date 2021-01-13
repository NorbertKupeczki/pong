
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window)
  : window(window)
{
  srand(time(NULL));

  number_of_balls = ONE;
  game_length = MEDIUM;
  game_type = PVP;
  active_scene = MAIN_MENU;
  selected_game_option = GAME_TYPE_SELECTED;
  selected_menu_option = START_GAME;
  game_over_option = BACK_TO_MAIN;
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

  if(!press_enter_texture.loadFromFile("Data/Images/enter.png"))
  {
    std::cout << "Press ENTER... texture didn't load\n";
  }
  press_enter.setTexture(press_enter_texture);
  press_enter.setPosition(
    window.getSize().x / 2 - press_enter.getGlobalBounds().width / 2,
    window.getSize().y - press_enter.getGlobalBounds().height - 20);

  if(!keys_texture.loadFromFile("Data/Images/keys.png"))
  {
    std::cout << "Press ENTER... texture didn't load\n";
  }
  keys.setTexture(keys_texture);
  keys.setPosition(
    window.getSize().x / 2 - keys.getGlobalBounds().width / 2,
    window.getSize().y / 2 - keys.getGlobalBounds().height / 2 +
    main_menu_sp.getLocalBounds().height / 2 + keys.getLocalBounds().height / 2 + 14);

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

  if(!game_over_blue.loadFromFile("Data/Images/gameover_b_menu.png"))
  {
    std::cout << "Game Over menu (BLUE) texture didn't load\n";
  }
  if(!game_over_red.loadFromFile("Data/Images/gameover_r_menu.png"))
  {
    std::cout << "Game Over menu (RED) texture didn't load\n";
  }
  game_over_sp.setTexture(game_over_red);
  game_over_sp.setPosition(
    window.getSize().x / 2 - game_over_sp.getGlobalBounds().width / 2,
    window.getSize().y / 2 - game_over_sp.getGlobalBounds().height / 2);

  if(!main_active.loadFromFile("Data/Images/main_active.png"))
  {
    std::cout << "Main menu button (active) texture didn't load\n";
  }
  if(!main_inactive.loadFromFile("Data/Images/main_inactive.png"))
  {
    std::cout << "Main menu (inactive) texture didn't load\n";
  }
  main_button.setTexture(main_active);
  main_button.setPosition(
    window.getSize().x / 2 - main_button.getGlobalBounds().width / 2,
    window.getSize().y / 2 - main_button.getGlobalBounds().height / 2);
  exit_button.setTexture(quit_game_inactive);
  exit_button.setPosition(
    window.getSize().x / 2 - exit_button.getGlobalBounds().width / 2,
    window.getSize().y / 2 - exit_button.getGlobalBounds().height / 2 + 74);
}

bool Game::init()
{
  initTextures();
  // Initialising sounds
  if (!victory_buffer.loadFromFile("Data/Sounds/victory.wav"))
  {
    std::cout << "Victory sound didn't load to buffer!\n";
  }
  victory_sound.setBuffer(victory_buffer);

  if (!menu_buffer.loadFromFile("Data/Sounds/menu.wav"))
  {
    std::cout << "Menu sound didn't load to buffer!\n";
  }
  menu_sound.setBuffer(menu_buffer);

  // Initialising font
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font did not load \n";
  }

  // Initialising score trackers
  p1_score_text.setString("0");
  p1_score_text.setFont(font);
  p1_score_text.setCharacterSize(50);
  p1_score_text.setFillColor(sf::Color(0,100,255,200));
  p1_score_text.setPosition
    (window.getSize().x / 2 - p1_score_text.getLocalBounds().width / 2 - 45.0,
     5.0);

  p2_score_text.setString("0");
  p2_score_text.setFont(font);
  p2_score_text.setCharacterSize(50);
  p2_score_text.setFillColor(sf::Color(255,0,0,200));
  p2_score_text.setPosition
    (window.getSize().x / 2 - p2_score_text.getLocalBounds().width / 2 + 40.0,
     5.0);

  // Initialising Player 1
  p1_paddle.setColor(1);
  p1_paddle.paddle_sprite.setPosition(
    paddle_offset - p1_paddle.paddle_sprite.getLocalBounds().width / 2,
    window.getSize().y / 2 - p1_paddle.paddle_sprite.getLocalBounds().height /2
    );

  // Initialising Player 2
  p2_paddle.setColor(2);
  p2_paddle.paddle_sprite.setPosition(
    window.getSize().x - paddle_offset - p2_paddle.paddle_sprite.getLocalBounds().width / 2,
    window.getSize().y / 2 - p2_paddle.paddle_sprite.getLocalBounds().height /2
  );

  return true;
}

void Game::update(float dt)
{
  p1_score_text.setString(std::to_string(p1_paddle.getScore()));
  p2_score_text.setString(std::to_string(p2_paddle.getScore()));

  // Setting up the game based on the options
  if (active_scene == START_UP && balls == nullptr)
  {
    balls = new Ball[number_of_balls];
    for (int i = 0; i < number_of_balls; i++)
    {
      // Distributing the balls evenly across the centre line
      balls[i].setStartLocation
        (window.getSize().y / (number_of_balls + 1) * (i + 1) -
         balls[i].ball_sprite.getLocalBounds().height / 2);

      balls[i].ball_sprite.setPosition
        (window.getSize().x / 2 - balls[i].ball_sprite.getGlobalBounds().width / 2,
        balls[i].getStartLocation());

      // Setting up variable speeds for the balls to start with
      balls[i].setSpeed(350.00 - i * 50.0);
    }

    // To give the player a better chance to win, reducing the AI player's
    // paddle's speed.
    if (game_type == PVCPU)
    {
      p2_paddle.setSpeed(140.0);
    }
    balls_in_play = number_of_balls;
  }

  else if (active_scene == IN_GAME)
  {
    // Checking whether the balls score point
    for (int i = 0; i < number_of_balls; i++)
    {
      if (balls[i].ball_sprite.getPosition().x <= 0 && balls[i].in_play)
      {
        p2_paddle.addScore();
        balls_in_play--;
        balls[i].reverseX();
        balls[i].in_play = false;
      }
      else if (balls[i].ball_sprite.getPosition().x +
               balls[i].ball_sprite.getLocalBounds().width >=
               window.getSize().x && balls[i].in_play)
      {
        p1_paddle.addScore();
        balls_in_play--;
        balls[i].reverseX();
        balls[i].in_play = false;
      }

      // Move the balls still in play based on their vectors and speed
      if (balls[i].in_play)
      {
        balls[i].ball_sprite.move(
          balls[i].getX() * balls[i].getSpeed() * dt,
          balls[i].getY() * balls[i].getSpeed() * dt);
      }
    }

    // If there are no more balls in play, the paddles and the balls are all set
    // back to their initial positions.
    if (balls_in_play == 0)
    {
      for (int i = 0; i < number_of_balls; i++)
      {
        balls[i].ball_sprite.setPosition
          (window.getSize().x / 2 - balls[i].ball_sprite.getGlobalBounds().width / 2,
           balls[i].getStartLocation());
        balls[i].setSpeed(350.00 - i * 50.0);
        balls[i].in_play = true;
      }
      balls_in_play = number_of_balls;
      p1_paddle.resetPaddle(window);
      p2_paddle.resetPaddle(window);

      active_scene = START_UP;
    }

    // If either player reaches the scores determined by the game length option
    if (p1_paddle.getScore() >= game_length || p2_paddle.getScore() >= game_length)
    {
      std::cout << "GAME OVER\n";
      p1_paddle.resetPaddle(window);
      p2_paddle.resetPaddle(window);
      if (p1_paddle.getScore() > p2_paddle.getScore())
      {
        game_over_sp.setTexture(game_over_blue);
      }
      else
      {
        game_over_sp.setTexture(game_over_red);
      }
      victory_sound.play();
      active_scene = GAME_OVER;
    }

    // Calling the collision check method of the balls
    for (int i = 0; i < number_of_balls; i++)
    {
      balls[i].collisionCheck(window,p1_paddle.paddle_sprite,p2_paddle.paddle_sprite);
    }

    // Moving the paddle of Player 1
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

    // Moving the paddle of Player 2 in case of the second players is AI
    if (game_type == PVCPU)
    {
      if((p2_paddle.paddle_sprite.getPosition().y +
          p2_paddle.paddle_sprite.getLocalBounds().height / 2) >
          (balls[0].ball_sprite.getPosition().y +
           balls[0].ball_sprite.getLocalBounds().height /2))
      {
        p2_paddle.setDir(-1);
      }
      else if (
        (p2_paddle.paddle_sprite.getPosition().y +
         p2_paddle.paddle_sprite.getLocalBounds().height / 2) <
        (balls[0].ball_sprite.getPosition().y +
         balls[0].ball_sprite.getLocalBounds().height /2))
      {
        p2_paddle.setDir(1);
      }
      else
      {
        p2_paddle.setDir(0);
      }
    }

    // Moving the paddle of Player 2 in case of a two player game
    p2_paddle.paddle_sprite.move(
      0.0,
      p2_paddle.getDir() * dt * p2_paddle.getSpeed()
    );
    if (p2_paddle.paddle_sprite.getPosition().y <= 0)
    {
      p2_paddle.paddle_sprite.setPosition
        (window.getSize().x - paddle_offset -
            p2_paddle.paddle_sprite.getLocalBounds().width / 2,
        0.0);
    }
    else if (p2_paddle.paddle_sprite.getPosition().y +
             p2_paddle.paddle_sprite.getLocalBounds().height >= window.getSize().y)
    {
      p2_paddle.paddle_sprite.setPosition
        (window.getSize().x - paddle_offset -
            p2_paddle.paddle_sprite.getLocalBounds().width / 2,
        window.getSize().y - p2_paddle.paddle_sprite.getLocalBounds().height);
    }
  }
}

void Game::render()
{
  window.draw(background);
  window.draw(p1_paddle.paddle_sprite);
  window.draw(p2_paddle.paddle_sprite);
  window.draw(p1_score_text);
  window.draw(p2_score_text);

  if (active_scene == MAIN_MENU)
  {
    window.draw(main_menu_sp);
    window.draw(keys);
    window.draw(start_game);
    window.draw(options);
    window.draw(quit_game);
  }
  else if (active_scene == OPTIONS)
  {
    window.draw(options_menu_sp);
    window.draw(keys);
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
    for (int i = 0; i < number_of_balls; i++)
    {
      window.draw(balls[i].ball_sprite);
    }
    window.draw(press_enter);
  }
  else if (active_scene == IN_GAME)
  {
    for (int i = 0; i < number_of_balls; i++)
    {
      if (balls[i].in_play)
      {
        window.draw(balls[i].ball_sprite);
      }
    }
  }
  else if (active_scene == GAME_OVER)
  {
    window.draw(game_over_sp);
    window.draw(main_button);
    window.draw(exit_button);
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
      menu_sound.play();
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
      menu_sound.play();
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
      menu_sound.play();
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
      menu_sound.play();
      active_scene = MAIN_MENU;
    }
    else if (event.key.code == sf::Keyboard::Up)
    {
      menu_sound.play();
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
      menu_sound.play();
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
      menu_sound.play();
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
      menu_sound.play();
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
  else if (active_scene == START_UP)
  {
    if (event.key.code == sf::Keyboard::Enter)
    {
      menu_sound.play();
      active_scene = IN_GAME;
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
    if (game_type == PVP)
    {
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
  else if (active_scene == GAME_OVER)
  {
    if ((event.key.code == sf::Keyboard::Up) ||
        (event.key.code == sf::Keyboard::Down))
    {
      menu_sound.play();
      if (game_over_option == BACK_TO_MAIN)
      {
        game_over_option = EXIT_GAME;
        main_button.setTexture(main_inactive);
        exit_button.setTexture(quit_game_active);
      }
      else if (game_over_option == EXIT_GAME)
      {
        game_over_option = BACK_TO_MAIN;
        exit_button.setTexture(quit_game_inactive);
        main_button.setTexture(main_active);
      }
    }
    if (event.key.code == sf::Keyboard::Enter)
    {
      if (game_over_option == BACK_TO_MAIN)
      {
        menu_sound.play();
        active_scene = MAIN_MENU;

        p1_paddle.resetPaddle(window);
        p1_paddle.resetScore();
        p1_paddle.setSpeed(200.0);
        p1_paddle.setDir(0.0);

        p2_paddle.resetPaddle(window);
        p2_paddle.resetScore();
        p2_paddle.setSpeed(200.0);
        p2_paddle.setDir(0.0);

        delete[] balls;
        balls = nullptr;
      }
      else if (game_over_option == EXIT_GAME)
      {
        window.close();
      }
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
    if (game_type == PVP)
    {
      if (
        (event.key.code == sf::Keyboard::O) ||
        (event.key.code == sf::Keyboard::L))
      {
        p2_paddle.setDir(0.0);
      }
    }
  }
}

