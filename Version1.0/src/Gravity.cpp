//
// Gravity.cpp for graivity in /home/ambroise/GGJ_2017/src
//
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
//
// Started on  Sat Jan 21 16:30:07 2017 Ambroise DAMIER
// Last update Sun Jan 22 00:30:00 2017 Thomas Bouillon
//

#include "Character.hpp"
#include "Map.hpp"
#include <iostream>
#include <string>

void	gravity(Character &chara, const Map *map)
{

  if (((chara.getY() + 120)) < (map->getYMax() * 30))
    {
      if (chara.getRight() == false)
	{
	  if (map->getUnit(((chara.getY() + 120) / 30), (chara.getX() / 30)) == "wall" ||
	      map->getUnit(((chara.getY() + 120) / 30), ((chara.getX() + 60) / 30)) == "wall")
	    {
	      chara.setJumpFlag(false);
	      chara.setAcc(50);
	    }
	  else
	    chara.setY((chara.getY() + chara.getGrav()));
	}
      else
	{
	  if (map->getUnit(((chara.getY() + 120) / 30), ((chara.getX() + 30) / 30)) == "wall")
	    {
	      chara.setJumpFlag(false);
	      chara.setAcc(50);
	    }
	  else
	    chara.setY((chara.getY() + chara.getGrav()));
	}
    }
}
