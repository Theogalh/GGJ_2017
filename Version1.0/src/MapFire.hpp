//
// MapFire.hpp for MapFire in /home/theogalh/git/GGJ_2017/include
//
// Made by Thomas Bouillon
// Login   <theogalh@epitech.net>
//
// Started on  Sun Jan 22 09:19:45 2017 Thomas Bouillon
// Last update Sun Jan 22 13:48:54 2017 Ambroise DAMIER
//

#ifndef MAPFIRE_HPP_
#define MAPFIRE_HPP_

#include "Map.hpp"
#include "Character.hpp"

#include <SFML/Graphics.hpp>

class MapFire: public Map
{
  sf::RectangleShape	rec;
  sf::Texture		txt;
  unsigned int			_y;
  unsigned int			_x;
  sf::Clock	time;

public:
  MapFire(const std::string &);
  ~MapFire();
  MapFire(const MapFire&);
  MapFire(const Map&);
  void operator=(const MapFire&);
  bool	contamine(sf::RenderWindow &, const Character &chara);
};

#endif
