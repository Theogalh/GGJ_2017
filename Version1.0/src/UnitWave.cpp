//
// UnitWave.cpp for zeaze in /home/ambroise/GGJ_2017/src
//
// Made by Ambroise DAMIER
// Login   <ambroise.damier@epitech.eu>
//
// Started on  Sun Jan 22 04:53:15 2017 Ambroise DAMIER
// Last update Sun Jan 22 09:49:14 2017 Mewen Le Reste
//

#include "UnitWave.hpp"

UnitWave::UnitWave(unsigned int x, sf::RenderWindow &win)
{
  _Type = "wave";
  _x = x;
  _y = 0;
  if (!_text.loadFromFile(WAVE))
    exit(84);
  _sprite.setTexture(_text);
  _sprite.setPosition(sf::Vector2f(_x, _y));
  win.draw(_sprite);
}

UnitWave::UnitWave(const Unit &other)
{
  _Type = other.getType();
  _x = 0;
  _y = 0;
}

UnitWave::~UnitWave()
{

}

UnitWave	&UnitWave::operator=(const Unit &other)
{
  _Type = other.getType();
  _x = 0;
  _y = 0;
  return *this;
}

void	UnitWave::setX(unsigned int x)
{
  _x = x;
}

unsigned int	UnitWave::getX() const
{
  return _x;
}

void	UnitWave::setY(unsigned int y)
{
  _y = y;
}

unsigned int	UnitWave::getY() const
{
  return _y;
}

void		UnitWave::update(sf::RenderWindow &win)
{
  _sprite.setTexture(_text);
  _sprite.setPosition(_x, _y);
  win.draw(_sprite);
}
