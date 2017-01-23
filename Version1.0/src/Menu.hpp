//
// Menu.hpp for Menu in /home/lerest_m/PersonnalProgramming/C++/GGJ/GGJ_2017/include/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sat Jan 21 09:43:18 2017 Mewen Le Reste
// Last update Sun Jan 22 09:53:07 2017 Mewen Le Reste
//

#ifndef MENU_HPP_
# define MENU_HPP_

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <iostream>
# include "Define.hpp"
# include "Game.hpp"

class Menu
{
  private:
    double x1;
    double x2;
    int selectedButton;
    bool increaseText;
    bool isStop;
    bool menu2;
    bool returnPressed;
    unsigned int charSize;
    sf::Sprite background1;
    sf::Sprite background2;
    sf::Texture texture1;
    sf::Texture texture2;
    sf::Font m12;
    sf::Text beatTheWave;
    sf::Text play;
    sf::Text _exit;
    sf::Music menuMusic;

  public:
    Menu(sf::RenderWindow &);
    Menu(const Menu &);
    ~Menu();
    Menu &operator=(const Menu &);
    void scroll(sf::RenderWindow &);
    std::string getEvent(sf::RenderWindow &);
    void stop();
    void start();
    bool loop(Game &);
};

#endif /* !MENU_HPP_ */
