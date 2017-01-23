//
// Wave.cpp for wave in /home/ambroise/GGJ_2017/src
//
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
//
// Started on  Sun Jan 22 04:40:42 2017 Ambroise DAMIER
// Last update Sun Jan 22 09:31:15 2017 Mewen Le Reste
//

#include "Wave.hpp"

Wave::Wave()
{
  _n = 0;
}

Wave::Wave(const Wave &other)
{
  _Elem = other._Elem;
  _n = other._n;
}

Wave::~Wave() {}

Wave &Wave::operator=(const Wave &other)
{
  _Elem = other._Elem;
  _n = other._n;
  return *this;
}

bool	Wave::launch_wave(sf::RenderWindow &win, unsigned int x, unsigned int y)
{
  int	rd;

  rd = rand();
  rd = rd % 120;

  if (rd == 0 || _n != 0)
  {
    _n++;
    rd = rand();
    rd = rd % 1210;
    UnitWave	new_unit(rd, win);
    _Elem.push_back(new_unit);
    if (_n >= 3)
	   _n = 0;
  }
  std::list<UnitWave>::iterator it = _Elem.begin();
  while (it != _Elem.end())
  {
    if (it->getY() > 980)
      it =_Elem.erase(it);
    else
    {
      it->setY((it->getY() + 15));
      it->update(win);
      if (((x + 80) > it->getX() && (x + 80) < (it->getX() + 80) && (y + 80) > it->getY() && (y + 80) < (it->getY() + 80))
	      || (x < (it->getX() + 80) && x > it->getX() && (y + 80) > it->getY() && (y + 80) < (it->getY() + 80))
	      || ((x + 80) > it->getX() && (x + 80) < (it->getX() + 80) && y < (it->getY() + 80) && y > it->getY())
	      || (x > (it->getX() + 80) && x < it->getX() && y > it->getY() && y < (it->getY() + 80)))
	    return true;
	   }
     ++it;
   }
   return false;
}
