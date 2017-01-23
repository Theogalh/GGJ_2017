//
// Game.cpp for Game in /home/theogalh/git/GGJ_2017/src
//
// Made by Thomas Bouillon
// Login   <theogalh@epitech.net>
//
// Started on  Sat Jan 21 05:42:26 2017 Thomas Bouillon
// Last update Sat Jan 21 21:09:04 2017 Mewen Le Reste
//

#include "Game.hpp"

Game::Game()
{
  win.create(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "Beat the Wave", sf::Style::Fullscreen);
  win.setPosition(sf::Vector2i(0,0));
  win.setFramerateLimit(60);
  time.restart();
}

Game::~Game()
{

}

bool	Game::winIsOpen() const
{
  return (win.isOpen());
}

bool	Game::getEvent(sf::Event &event)
{
  return (win.pollEvent(event));
}

void	Game::close()
{
  win.close();
}

sf::RenderWindow	&Game::getWin()
{
  return (win);
}
