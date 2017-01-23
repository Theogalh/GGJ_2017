//
// UnitVoid.cpp for univoid in /home/ambroise/GGJ_2017/src/map
// 
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
// 
// Started on  Sat Jan 21 06:39:44 2017 Ambroise DAMIER
// Last update Sat Jan 21 06:53:38 2017 Ambroise DAMIER
//

#include "UnitVoid.hpp"

UnitVoid::UnitVoid()
{
  _Type = "void";
}

UnitVoid::UnitVoid(const Unit &other)
{
  _Type = other.getType();
}

UnitVoid::~UnitVoid()
{
}

UnitVoid	&UnitVoid::operator=(const Unit &other)
{
  _Type = other.getType();
  return *this;
}
