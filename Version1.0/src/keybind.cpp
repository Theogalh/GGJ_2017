//
// keybind.cpp for keybind in /home/theogalh/git/GGJ_2017/src
//
// Made by Thomas Bouillon
// Login   <theogalh@epitech.net>
//
// Started on  Sat Jan 21 11:05:11 2017 Thomas Bouillon
// Last update Sun Jan 22 04:27:15 2017 Ambroise DAMIER
//

#include "Character.hpp"
#include <SFML/Graphics.hpp>

void    keybinding(Character &chara)
{
  int	flag = 0;;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      if (chara.getCTime() >= 0.25)
	{
	  chara.setJumpFlag(true);
	  chara.setTmpFlag(true);
	  flag = 1;
	  chara.restartCTime();
	}
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      chara.runRight();
      flag = 1;
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      chara.runLeft();
      flag = 1;
    }
  if (flag == 0)
    chara.idle();
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    chara.setLive(false);
}
