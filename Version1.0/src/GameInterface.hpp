//
// GameInterface.hpp for GameInterface in /home/lerest_m/PersonnalProgramming/C++/GGJ/GGJ_2017/include/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sat Jan 21 15:02:54 2017 Mewen Le Reste
// Last update Sun Jan 22 11:42:08 2017 Mewen Le Reste
//

#ifndef GAMEINTERFACE_HPP_
# define GAMEINTERFACE_HPP_

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <fstream>
# include <iostream>
# include <sstream>
# include "Define.hpp"
# include "Game.hpp"

class GameInterface
{
  private:
    sf::Text highscoreText;
    sf::Text scoreText;
    sf::Text timerText;
    sf::Text levelText;
    sf::Text escText;
    sf::Clock clock;
    sf::Music gameMusic;
    sf::Sprite background;
    sf::Texture texture;
    sf::Font m12;
    unsigned int _score;
    unsigned int _highscore;
    unsigned int _level;
    int charSize;

  public:
    GameInterface(Game &);
    GameInterface(const GameInterface &);
    ~GameInterface();
    GameInterface &operator=(const GameInterface &);
    GameInterface &operator+=(unsigned int add);
    GameInterface &operator++();
    GameInterface &operator++(int);
    void update(Game &, const bool &);
    unsigned int getScore() const;
    unsigned int getLevel() const;
    void save();

  private:
    std::string clockToString();
};

#endif /* GAMEINTERFACE_HPP_ */
