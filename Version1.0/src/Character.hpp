//
// Character.hpp for CHaracter in /home/theogalh/git/GGJ_2017
//
// Made by Thomas Bouillon
// Login   <theogalh@epitech.net>
//
// Started on  Fri Jan 20 23:30:26 2017 Thomas Bouillon
// Last update Sun Jan 22 00:59:40 2017 Mewen Le Reste
//

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <SFML/Graphics.hpp>
#include <string>

class	Character
{
  bool			_live;
  unsigned int		_width;
  unsigned int		_height;
  float			_grav;
  sf::Clock		_cTime;
  bool			_right;
  float			_speed;
  sf::Texture		_faint;
  sf::Texture		_run;
  sf::Texture		_jump;
  sf::Texture		_idle;
  sf::Sprite		_sprite;
  unsigned int		_y;
  unsigned int		_x;
  unsigned int		_Acc;
  bool			_JumpFlag;
  bool			_TmpFlag;

public:

  Character();
  Character(const Character &);
  ~Character();
  void	operator=(const Character &);

  /* Get / Set stats */

  void	setLive(bool);
  bool	getLive() const;

  void	setWidth(unsigned int);
  unsigned int	getWidth() const;

  void	setHeight(unsigned int);
  unsigned int	getHeight() const;

  void	setGrav(float);
  float getGrav() const;

  float getCTime() const;
  void	restartCTime();

  float getSpeed() const;
  void	setSpeed(float);

  unsigned int	getY() const;
  void		setY(unsigned int);

  unsigned int	getX() const;
  void		setX(unsigned int);

  bool		getJumpFlag() const;
  void		setJumpFlag(bool);

  bool		getTmpFlag() const;
  void		setTmpFlag(bool);

  unsigned int	getAcc() const;
  void		setAcc(unsigned int);

  bool		getRight() const;

  void		setSpritePos();
  sf::Sprite	getSprite();

  /* Chargement animations */

  void		loadTexture(const std::string&,const std::string&,const std::string&,const std::string&);

  /* Fonction de déplacements */

  void		runRight();
  void		runLeft();
  void		death();
  void		idle();
  bool		jump();
};

#endif
