//
// Game.hpp for Game in /home/theogalh/git/GGJ_2017/include
//
// Made by Thomas Bouillon
// Login   <theogalh@epitech.net>
//
// Started on  Sat Jan 21 05:42:20 2017 Thomas Bouillon
// Last update Sat Jan 21 17:53:27 2017 Mewen Le Reste
//

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>

class Game
{
  sf::RenderWindow win;
  sf::Clock	   time;

public:

  Game();
  ~Game();

  bool	winIsOpen() const;
  bool	getEvent(sf::Event &);
  void	close();
  sf::RenderWindow &getWin();
};

#endif
