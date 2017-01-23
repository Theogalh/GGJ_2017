//
// UnitWall.hpp for uniwall in /home/ambroise/GGJ_2017/src/map
// 
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
// 
// Started on  Sat Jan 21 05:44:21 2017 Ambroise DAMIER
// Last update Sat Jan 21 06:33:34 2017 Ambroise DAMIER
//

#ifndef UNIT_WALL_HPP_
# define UNIT_WALL_HPP_

#include "Unit.hpp"

class UnitWall : public Unit
{
public:
  UnitWall();
  UnitWall(const Unit &);
  ~UnitWall();

  UnitWall	&operator=(const Unit &);
};

#endif /* !UNIT_WALL_HPP_ */
