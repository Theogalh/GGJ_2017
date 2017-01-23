//
// Wave.hpp for zae in /home/ambroise/GGJ_2017/include
//
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
//
// Started on  Sun Jan 22 03:34:16 2017 Ambroise DAMIER
// Last update Sun Jan 22 09:54:11 2017 Mewen Le Reste
//

#ifndef WAVE_HPP_
# define WAVE_HPP_

#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include "UnitWave.hpp"
#include "Unit.hpp"

class Wave
{
protected:
  std::list <UnitWave>	_Elem;
  unsigned int _n;

public:
  Wave();
  Wave(const Wave &);
  ~Wave();
  Wave &operator=(const Wave &);
  bool	launch_wave(sf::RenderWindow &, unsigned int, unsigned int);
};

#endif /* !WAVE_HPP_ */
