//
// Unit.cpp for unit in /home/ambroise/GGJ_2017/src/map
// 
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
// 
// Started on  Sat Jan 21 06:26:52 2017 Ambroise DAMIER
// Last update Sat Jan 21 06:54:19 2017 Ambroise DAMIER
//

#include "Unit.hpp"

Unit::Unit()
{
  _Type = "unit";
}

Unit::Unit(const Unit & other)
{
  _Type = other.getType();
}

Unit::~Unit()
{
}

Unit		&Unit::operator=(const Unit & other)
{
  _Type = other.getType();
  return *this;
}

std::string	Unit::getType() const
{
  return _Type;
}

void		Unit::setType(std::string type)
{
  _Type = type;
}
