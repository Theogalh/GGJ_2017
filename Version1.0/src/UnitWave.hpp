//
// UnitWave.hpp for ok in /home/ambroise/GGJ_2017/include
//
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
//
// Started on  Sun Jan 22 04:01:58 2017 Ambroise DAMIER
// Last update Sun Jan 22 09:51:01 2017 Mewen Le Reste
//

#ifndef UNIT_WAVE_HPP_
# define UNIT_WAVE_HPP_

# include <SFML/Graphics.hpp>
# include "Unit.hpp"
# include "Define.hpp"

class UnitWave : public Unit
{
protected:
  unsigned int	_x;
  unsigned int	_y;
  sf::Texture	_text;
  sf::Sprite	_sprite;

public:
  UnitWave(unsigned int, sf::RenderWindow &);
  UnitWave(const Unit &);
  ~UnitWave();

  UnitWave	&operator=(const Unit &);

  void		setX(unsigned int x);
  unsigned int	getX() const;

  void		setY(unsigned int y);
  unsigned int	getY() const;

  void		update(sf::RenderWindow &);
};

#endif /* !UNIT_WAVE_HPP_ */
