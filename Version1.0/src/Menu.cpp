//
// Menu.cpp for Menu in /home/lerest_m/PersonnalProgramming/C++/GGJ/GGJ_2017/menu/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sat Jan 21 09:34:21 2017 Mewen Le Reste
// Last update Sun Jan 22 09:50:29 2017 Mewen Le Reste
//

#include "Menu.hpp"

Menu::Menu(sf::RenderWindow &win)
{
  menuMusic.openFromFile(MENU_MUSIC);
  menuMusic.setLoop(true);
  menuMusic.play();
  m12.loadFromFile(FONTM12);
  texture1.loadFromFile(BACKGROUND);
  texture2.loadFromFile(BACKGROUND);
  background1.setTexture(texture1);
  background2.setTexture(texture2);
  x1 = 0;
  x2 = -3719;
  charSize = 75;
  increaseText = false;
  isStop = false;
  menu2 = false;
  returnPressed = false;
  selectedButton = 0;
  background1.setPosition(x1, 0);
  background2.setPosition(x2, 0);
  beatTheWave.setFont(m12);
  beatTheWave.setColor(sf::Color::White);
  beatTheWave.setString("Beat the Wave");
  beatTheWave.setCharacterSize(charSize);
  beatTheWave.setPosition(sf::Vector2f(666, 450));
  play.setFont(m12);
  play.setColor(sf::Color::White);
  play.setString("Play the Wave");
  play.setCharacterSize(charSize / 2);
  play.setPosition(sf::Vector2f(666, 550));
  _exit.setFont(m12);
  _exit.setColor(sf::Color::White);
  _exit.setString("Exit the Beat");
  _exit.setCharacterSize(charSize / 2);
  _exit.setPosition(sf::Vector2f(666, 650));
  win.draw(background1);
  win.draw(background2);
  win.draw(beatTheWave);
  win.display();
}

Menu::Menu(const Menu &other)
{
  x1 = other.x1;
  x2 = other.x2;
  selectedButton = other.selectedButton;
  increaseText = other.increaseText;
  isStop = other.isStop;
  menu2 = other.menu2;
  returnPressed = other.returnPressed;
  charSize = other.charSize;
  background1 = other.background1;
  background2 = other.background2;
  texture1 = other.texture1;
  texture2 = other.texture2;
  m12 = other.m12;
  beatTheWave = other.beatTheWave;
  play = other.play;
  _exit = other._exit;
}

Menu::~Menu() {}

Menu &Menu::operator=(const Menu &other)
{
  x1 = other.x1;
  x2 = other.x2;
  selectedButton = other.selectedButton;
  increaseText = other.increaseText;
  isStop = other.isStop;
  menu2 = other.menu2;
  returnPressed = other.returnPressed;
  charSize = other.charSize;
  background1 = other.background1;
  background2 = other.background2;
  texture1 = other.texture1;
  texture2 = other.texture2;
  m12 = other.m12;
  beatTheWave = other.beatTheWave;
  play = other.play;
  _exit = other._exit;
  return *this;
}

void Menu::start()
{
  menuMusic.play();
  isStop = false;
}

void Menu::stop()
{
  menuMusic.stop();
  isStop = true;
}

std::string Menu::getEvent(sf::RenderWindow &win)
{
  sf::Event event;
  if (win.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
      return "Exit";
    else if (event.type == sf::Event::KeyReleased)
    {
      if (event.key.code == sf::Keyboard::Return)
        returnPressed = false;
    }
    else if (event.type == sf::Event::KeyPressed)
    {
      if (!returnPressed && event.key.code == sf::Keyboard::Return)
      {
        returnPressed = true;
        if (!menu2)
          menu2 = true;
        else
        {
          if (selectedButton >= 0)
            stop();
          if (selectedButton == 0)
            return "Play";
          else if (selectedButton == 1)
            return "Exit";
        }
        return "";
      }
      else if (event.key.code == sf::Keyboard::Up)
        selectedButton = 0;
      else if (event.key.code == sf::Keyboard::Down)
        selectedButton = 1;
    }
  }
  return "";
}

void Menu::scroll(sf::RenderWindow &win)
{
  if (!isStop)
  {
    x1 += 10;
    x2 += 10;
    if (increaseText)
    {
      charSize += 5;
      if (charSize >= 70)
        ++charSize;
      if (charSize >= 75)
      {
        charSize = 75;
        increaseText = false;
      }
    }
    else
    {
      --charSize;
      if (charSize == 50)
        increaseText = true;
    }
    if (x2 >= 0 && x1 >= 3719)
      x1 = -3719 + x2;
    else if (x1 >= 0 && x2 >= 3719)
      x2 = -3719 + x1;
    background1.setPosition(x1, 0);
    background2.setPosition(x2, 0);
    beatTheWave.setCharacterSize(charSize);
    win.draw(background1);
    win.draw(background2);
    win.draw(beatTheWave);
    if (menu2)
    {
      _exit.setCharacterSize(charSize / 2);
      if (selectedButton == 1)
        _exit.setColor(sf::Color::Red);
      else
        _exit.setColor(sf::Color::White);
      play.setCharacterSize(charSize / 2);
      if (selectedButton == 0)
        play.setColor(sf::Color::Red);
      else
        play.setColor(sf::Color::White);
      win.draw(play);
      win.draw(_exit);
    }
  }
}

bool Menu::loop(Game &game)
{
  bool inGame = false;
  sf::RenderWindow &win = game.getWin();
  while(!inGame)
  {
    scroll(game.getWin());
    std::string menuEvent = getEvent(win);
    if (menuEvent == "Play")
      inGame = true;
    else if (menuEvent == "Exit")
    {
      game.close();
      return false;
    }
    win.display();
    win.clear();
  }
  return true;
}
