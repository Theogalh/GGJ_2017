//
// Map.cpp for map in /home/ambroise/GGJ_2017/src/map
//
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
//
// Started on  Sat Jan 21 06:59:55 2017 Ambroise DAMIER
// Last update Sun Jan 22 10:35:59 2017 Thomas Bouillon
//

#include "Map.hpp"

Map::Map(const std::string &file)
{
  char  c;
  std::vector<Unit*>	tmp;
  _y_max = 35;
  _x_max = 43;
  _x_min = 0;
  _y_min = 0;
  fire = false;

  std::ifstream flux(file.c_str(), std::ios::in);
  if (flux)
    {
      while (flux.get(c))
	{
	  if (c == '\n' || c == '\0')
	    {
	      _Map.push_back(tmp);
	      tmp.clear();
	    }
	  else
	    {
	      if (c == '0')
		tmp.push_back(new UnitVoid);
	      if (c == '1')
		tmp.push_back(new UnitWall);
	    }
	}
      flux.close();
    }
}

Map::Map(const Map &other)
{
  _Map = other._Map;
  _y_max = other._y_max;
  _x_max = other._x_max;
  _y_min = other._y_min;
  _x_min = other._x_min;
  fire = other.fire;
}

Map &Map::operator=(const Map &other)
{
  _Map = other._Map;
  _y_max = other._y_max;
  _x_max = other._x_max;
  _y_min = other._y_min;
  _x_min = other._x_min;
  fire = other.fire;
  return *this;
}

Map::~Map() {}

std::string	Map::getUnit(unsigned int y, unsigned int x) const
{
  return _Map[y][x]->getType();
}

std::vector<std::vector<Unit*> >	Map::getMap() const
{
  return _Map;
}

unsigned int				Map::getXMax() const
{
  return _x_max;
}

unsigned int				Map::getYMax() const
{
  return _y_max;
}

unsigned int				Map::getXMin() const
{
  return _x_min;
}

unsigned int				Map::getYMin() const
{
  return _y_min;
}

bool Map::isFire()
{
  return fire;
}
