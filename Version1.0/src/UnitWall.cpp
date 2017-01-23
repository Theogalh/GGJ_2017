//
// UnitVoid.cpp for univoid in /home/ambroise/GGJ_2017/src/map
// 
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
// 
// Started on  Sat Jan 21 06:39:44 2017 Ambroise DAMIER
// Last update Sat Jan 21 06:53:58 2017 Ambroise DAMIER
//

#include "UnitWall.hpp"

UnitWall::UnitWall()
{
  _Type = "wall";
}

UnitWall::UnitWall(const Unit &other)
{
  _Type = other.getType();
}

UnitWall::~UnitWall()
{
}

UnitWall	&UnitWall::operator=(const Unit &other)
{
  _Type = other.getType();
  return *this;
}
