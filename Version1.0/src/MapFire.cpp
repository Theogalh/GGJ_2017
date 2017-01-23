//
// MapFire.cpp for MapFire in /home/theogalh/git/GGJ_2017/src
//
// Made by Thomas Bouillon
// Login   <theogalh@epitech.net>
//
// Started on  Sun Jan 22 09:21:29 2017 Thomas Bouillon
// Last update Sun Jan 22 13:54:18 2017 Mewen Le Reste
//

#include "MapFire.hpp"
#include "Define.hpp"
#include <cstdlib>
#include <iostream>

MapFire::MapFire(const std::string &s):Map(s)
{
  fire = true;
  _y = 1100;
  _x = 0;
  if (!txt.loadFromFile(LAVA))
    exit(84);
  rec.setSize(sf::Vector2f(1290, 1050));
  rec.setTexture(&txt);
  rec.setPosition(_x, _y);
}

MapFire::~MapFire()
{

}

MapFire::MapFire(const Map& s):Map(s)
{
  fire = true;
}

MapFire::MapFire(const MapFire& s):Map(s)
{
}

void	MapFire::operator=(const MapFire&s)
{
  _Map = s.getMap();
  _y_max = s.getYMax();
  _x_max = s.getXMax();
  _y_min = s.getYMin();
  _x_min = s.getXMin();
}

bool	MapFire::contamine(sf::RenderWindow &win, const Character &chara)
{
  if (time.getElapsedTime().asSeconds() >= 0.0001)
    {
      _y = _y - 2;
      rec.setTexture(&txt);
      rec.setPosition(sf::Vector2f(_x, _y));
      if ((chara.getY() + 60) > _y)
	return false;
      time.restart();
    }
  win.draw(rec);
  return true;
}
