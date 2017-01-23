//
// Map.hpp for map in /home/ambroise/GGJ_2017/src
//
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
//
// Started on  Sat Jan 21 05:30:36 2017 Ambroise DAMIER
// Last update Sun Jan 22 10:35:34 2017 Thomas Bouillon
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include <vector>
# include <iostream>
# include <string>
# include <fstream>
# include <SFML/Graphics.hpp>
# include "Unit.hpp"
# include "UnitVoid.hpp"
# include "UnitWall.hpp"

class Map
{
protected:
  std::vector<std::vector<Unit*> >	_Map;
  unsigned int					_y_max;
  unsigned int					_x_max;
  unsigned int					_y_min;
  unsigned int					_x_min;
  bool fire;

public:
  Map(const std::string &file);
  Map(const Map &);
  virtual ~Map();
  Map	&operator=(const Map &);
  std::string	getUnit(unsigned int y, unsigned int x) const;
  std::vector<std::vector<Unit*> >	getMap() const;
  unsigned int					getXMax() const;
  unsigned int					getYMax() const;
  unsigned int					getXMin() const;
  unsigned int					getYMin() const;
  bool isFire();
};

#endif /* !MAP_HPP_ */
