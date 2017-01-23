//
// Main.cpp for Main in /home/lerest_m/PersonnalProgramming/C++/GGJ/GGJ_2017/src/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sun Jan 22 08:35:36 2017 Mewen Le Reste
// Last update Sun Jan 22 13:23:44 2017 Ambroise DAMIER
//

#include "Main.hpp"

Main::Main()
{
  srand(time(NULL));
  size = 0;
  maps = getFiles(size, MAP);
  if (maps == NULL)
    exit(84);
  if (!txtBg.loadFromFile(BG_IMG))
    exit(84);
  init();
}

Main::~Main()
{
  delete(game);
  delete(chara);
  delete(menu);
  delete(map);
  delete[](maps);
}

void Main::init()
{
  game = new Game();
  chara = new Character();
  top = false;
  changeTexture = true;
  menu = new Menu(game->getWin());
  pos = rand() % size;
  map = new Map(maps[pos]);
  gameOver = false;
  retry = false;
  m12.loadFromFile(FONTM12);
  gameOverText.setFont(m12);
  gameOverText.setColor(sf::Color::Red);
  gameOverText.setString("Game Over\nPress return to retry");
  gameOverText.setCharacterSize(50);
  gameOverText.setPosition(sf::Vector2f(300, 500));
  rect.setSize(sf::Vector2f(1290, 1050));
  rect.setTexture(&txtBg);
  rect.setPosition(0, 0);
  chara->setLive(true);
  chara->loadTexture(ANIM_FAINT, ANIM_RUN, ANIM_JUMP, ANIM_IDLE);
}

void Main::actLoop(sf::RenderWindow &win)
{
  if (!gameOver)
  {
    keybinding(*chara);
    if (chara->getJumpFlag() == true)
      top = chara->jump();
    if (chara->getTmpFlag() == false)
      gravity(*chara, map);
    if (map->isFire())
      {
	if (((MapFire *)map)->contamine(win, *chara) == false)
	  {
	    gameOver = true;
	    chara->setLive(false);
	    chara->death();
	  }
	if (gameOver)
	  win.draw(gameOverText);
      }
  }
}

void Main::topLoop(GameInterface &interface)
{
  if (top)
  {
    delete(map);
    pos = rand() % size;
    int mapType = rand() % 4;
    if (mapType == 0)
      map = new MapFire(maps[pos]);
    else
      map = new Map(maps[pos]);
    ++interface;
    changeTexture = true;
    if (map->isFire())
      interface += 150;
    else
      interface += 100;
    chara->setY(900);
    top = false;
  }
}

void Main::gameOverLoop(sf::RenderWindow &win, Wave &wave)
{
  if (!gameOver && wave.launch_wave(win, chara->getX(), chara->getY()))
  {
    gameOver = true;
    chara->setLive(false);
    chara->death();
  }
  if (gameOver)
    win.draw(gameOverText);
}

void Main::closeGame()
{
  sf::Event event;
  while (game->getEvent(event))
  {
    if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
      game->close();
    if (gameOver && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
      retry = true;
  }
}

void Main::loop()
{
  retry = false;
  if (!menu->loop(*game))
    return ;
  GameInterface interface(*game);
  Wave wave;
  sf::RenderWindow &win = game->getWin();
  while(!retry && game->winIsOpen())
  {
    interface.save();
    win.draw(rect);
    closeGame();
    interface.update(*game, gameOver);
    create_square(win, map);
    actLoop(win);
    if (!chara->getLive())
	   chara->death();
    chara->setSpritePos();
    win.draw(chara->getSprite());
    gameOverLoop(win, wave);
    win.display();
    win.clear();
    topLoop(interface);
  }
  if (retry)
  {
    win.clear();
    delete(game);
    delete(chara);
    delete(menu);
    init();
    loop();
  }

}

void Main::create_square(sf::RenderWindow &win, const Map *map)
{
  unsigned int	x;
  unsigned int	y;

  y = map->getYMin();
  sf::RectangleShape rect;
  sf::Texture	text;
  if (changeTexture)
  {
    size_t size = 0;
    std::string *walls = getFiles(size, WALL);
    int pos = rand() % size;
    if (!txt.loadFromFile(walls[pos]))
      exit(84);
    delete[] (walls);
    changeTexture = false;
  }
  rect.setSize(sf::Vector2f(30, 30));
  while (y != map->getYMax())
  {
    x = map->getXMin();
    while (x != map->getXMax())
	  {
	    if (map->getUnit(y, x) == "wall")
	    {
	      rect.setTexture(&txt);
	      rect.setPosition((x * 30), (y * 30));
	      win.draw(rect);
	    }
	    x++;
	   }
     y++;
  }
}

std::string *Main::getFiles(size_t &size, const std::string &path)
{
  DIR *rep = opendir(path.c_str());
  if (rep == NULL)
    return NULL;
  size = 0;
  struct dirent *ent;
  while((ent = readdir(rep)) != NULL)
  {
    if (ent->d_name[0] != '.')
      ++size;
  }
  closedir(rep);
  rep = opendir(path.c_str());
  std::string *maps = new std::string[size];
  unsigned int n = 0;
  while((ent = readdir(rep)) != NULL)
  {
    if (ent->d_name[0] != '.')
    {
      maps[n] = path;
      maps[n].append(ent->d_name);
      ++n;
    }
  }
  closedir(rep);
  return maps;
}
