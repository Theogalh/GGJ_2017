//
// UnitWall.hpp for uniwall in /home/ambroise/GGJ_2017/src/map
// 
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
// 
// Started on  Sat Jan 21 05:44:21 2017 Ambroise DAMIER
// Last update Sat Jan 21 06:33:15 2017 Ambroise DAMIER
//

#ifndef UNIT_VOID_HPP_
# define UNIT_VOID_HPP_

#include "Unit.hpp"

class UnitVoid : public Unit
{
public:
  UnitVoid();
  UnitVoid(const Unit &);
  ~UnitVoid();

  UnitVoid	&operator=(const Unit &);
};

#endif /* !UNIT_VOID_HPP_ */
