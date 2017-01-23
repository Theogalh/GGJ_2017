//
// Main.hpp for Main in /home/lerest_m/PersonnalProgramming/C++/GGJ/GGJ_2017/include/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sun Jan 22 08:27:10 2017 Mewen Le Reste
// Last update Sun Jan 22 11:49:24 2017 Mewen Le Reste
//

#ifndef MAIN_HPP_
# define MAIN_HPP_

# include <SFML/Graphics.hpp>
# include <cstdlib>
# include <string>
# include <iostream>
# include <dirent.h>
# include "Define.hpp"
# include "Character.hpp"
# include "Menu.hpp"
# include "MapFire.hpp"
# include "GameInterface.hpp"
# include "Wave.hpp"

void keybinding(Character &chara);
void gravity(Character &chara, const Map *map);

class Main
{
  private:
    Game *game;
    bool top;
    Character *chara;
    Menu *menu;
    sf::RectangleShape rect;
    sf::Texture	txt;
    sf::Texture	txtBg;
    size_t size;
    std::string *maps;
    sf::Text gameOverText;
    sf::Font m12;
    unsigned int pos;
    Map	*map;
    bool gameOver;
    bool changeTexture;
    bool retry;

  public:
    Main();
    ~Main();
    void loop();

  private:
    void init();
    void topLoop(GameInterface &);
    void actLoop(sf::RenderWindow &);
    void gameOverLoop(sf::RenderWindow &, Wave &);
    void closeGame();
    std::string *getFiles(size_t &, const std::string &);
    void create_square(sf::RenderWindow &, const Map *);
};

#endif /* !MAIN_HPP_ */
