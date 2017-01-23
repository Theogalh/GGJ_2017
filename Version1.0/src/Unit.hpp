//
// Unit.hpp for unit in /home/ambroise/GGJ_2017/src
// 
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
// 
// Started on  Sat Jan 21 05:36:53 2017 Ambroise DAMIER
// Last update Sat Jan 21 06:53:08 2017 Ambroise DAMIER
//

#ifndef UNIT_HPP_
# define UNIT_HPP_

#include <string>
#include <iostream>

class Unit
{
protected:
  std::string _Type;

public:
  Unit();
  Unit(const Unit &);
  ~Unit();

  Unit		&operator=(const Unit &);

  std::string	getType() const;
  void		setType(std::string type);
};

#endif /* !UNIT_HPP_ */
