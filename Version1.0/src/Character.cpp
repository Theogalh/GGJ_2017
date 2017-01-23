//
// Character.cpp for Character in /home/theogalh/git/GGJ_2017
//
// Made by Thomas Bouillon
// Login   <theogalh@epitech.net>
//
// Started on  Sat Jan 21 00:20:15 2017 Thomas Bouillon
// Last update Sun Jan 22 11:25:33 2017 Mewen Le Reste
// Last update Sun Jan 22 01:38:52 2017 Mewen Le Reste
//

#include "Character.hpp"
#include <iostream>
#include <cstdlib>

Character::Character():_live(1), _width(83), _height(120), _grav(10), _cTime(sf::Clock()), _Acc(50), _JumpFlag(false), _TmpFlag(false)
{
  _right = true;
  _x = 0;
  _y = 900;
  _speed = 10;
}

Character::Character(const Character &cpy)
{
  this->setLive(cpy.getLive());
  this->setWidth(cpy.getWidth());
  this->setHeight(cpy.getHeight());
  this->setGrav(cpy.getGrav());
  this->_cTime = sf::Clock();
  this->setAcc(cpy.getAcc());
  this->setJumpFlag(cpy.getJumpFlag());
  this->setTmpFlag(cpy.getTmpFlag());
  _x = cpy._x;
  _y = cpy._y;

}

Character::~Character()
{
}

void	Character::operator=(const Character &cpy)
{
  this->setLive(cpy.getLive());
  this->setWidth(cpy.getWidth());
  this->setHeight(cpy.getHeight());
  this->setGrav(cpy.getGrav());
  this->_cTime = sf::Clock();
  this->setAcc(cpy.getAcc());
  this->setJumpFlag(cpy.getJumpFlag());
  this->setTmpFlag(cpy.getTmpFlag());
  _x = cpy._x;
  _y = cpy._y;

}

bool	Character::getLive() const
{
  return (_live);
}

unsigned int	Character::getWidth() const
{
  return (_width);
}

unsigned int	Character::getHeight() const
{
  return (_height);
}

unsigned int	Character::getX() const
{
  return (_x);
}

unsigned int	Character::getY() const
{
  return (_y);
}

float		Character::getSpeed() const
{
  return (_speed);
}


float	Character::getGrav() const
{
  return (_grav);
}

void		Character::setSpeed(float n)
{
  _speed = n;
}

void	Character::setLive(bool n)
{
  _live = n;
  if (_live)
    idle();
}

void	Character::setWidth(unsigned int n)
{
  _width = n;
}

void	Character::setHeight(unsigned int n)
{
  _height = n;
}

void	Character::setY(unsigned int n)
{
  _y = n;
}

void	Character::setX(unsigned int n)
{
  _x = n;
}

void	Character::setGrav(float n)
{
  _grav = n;
}

float	Character::getCTime() const
{
  return (_cTime.getElapsedTime().asSeconds());
}

void	Character::restartCTime()
{
  _cTime.restart();
}

void	Character::loadTexture(const std::string &faint,const std::string &run,const std::string &jump, const std::string &idle)
{
  if (!_faint.loadFromFile(faint) ||
      !_run.loadFromFile(run) ||
      !_jump.loadFromFile(jump) ||
      !_idle.loadFromFile(idle))
    exit(84);
  _faint.setSmooth(true);
  _run.setSmooth(true);
  _jump.setSmooth(true);
  _idle.setSmooth(true);
}

bool		Character::getJumpFlag() const
{
  return _JumpFlag;
}

void		Character::setJumpFlag(bool b)
{
  _JumpFlag = b;
}

bool		Character::getTmpFlag() const
{
  return _TmpFlag;
}

void		Character::setTmpFlag(bool b)
{
  _TmpFlag = b;
}

unsigned int	Character::getAcc() const
{
  return _Acc;
}

void		Character::setAcc(unsigned int u)
{
  _Acc = u;
}

bool	Character::jump()
{
  if (_Acc > 0)
    {
      if (_y > _Acc)
        _y = _y - _Acc;
      else
        _y = 0;
      if (_y <= 0)
        return true;
      _Acc = _Acc - 10;
    }
  else
    _TmpFlag = false;
  return false;
}

void	Character::setSpritePos()
{
  _sprite.setPosition(_x, _y);
}

sf::Sprite	Character::getSprite()
{
  return (_sprite);
}

void	Character::runRight()
{
  static int	anim = 0;

  if (_live)
    {
      if (anim == 5)
	anim = 0;
      _sprite.setTexture(_run);
      _sprite.setTextureRect(sf::IntRect(_width * anim, 0, _width, _height));
      anim++;
      if ((_x + _speed) < 1225)
	_x = _x + _speed;
      _right = true;
    }
}

void	Character::runLeft()
{
  static int	anim = 0;

  if (_live)
    {
      if (anim == 5)
	anim = 0;
      _sprite.setTexture(_run);
      _sprite.setTextureRect(sf::IntRect(_width * anim, _height, _width, _height));
      anim++;
      if (_x >= _speed)
	_x = _x - _speed;
      _right = false;
    }
}

void	Character::idle()
{
  int	y;
  static int	anim = 0;

  if (_live)
    {
      y = 1;
      if (_right == true)
	y = 0;
      if (anim == 2)
	anim = 0;
      _sprite.setTexture(_idle);
      _sprite.setTextureRect(sf::IntRect(_width * anim, _height * y, _width, _height));
      anim++;
    }
}

void	Character::death()
{
  int	y;
  int	fac;
  static int	anim = 0;

  _width = 120;
  y = 1;
  _sprite.setTexture(_faint);
  if (_right == true)
    {
      y = 0;
      _sprite.setTextureRect(sf::IntRect(_width * anim, _height * y, _width, _height));
    }
  else
    {
      fac = (_width * 5) - (_width * anim);
      _sprite.setTextureRect(sf::IntRect(fac, _height * y, _width, _height));
    }
  if (anim < 5)
    anim++;
}

bool	Character::getRight() const
{
  return _right;
}
