//
// GameInterface.cpp for GameInterface in /home/lerest_m/PersonnalProgramming/C++/GGJ/GGJ_2017/src/
//
// Made by Mewen Le Reste
// Login   <mewen.lereste@epitech.eu>
//
// Started on  Sat Jan 21 17:23:32 2017 Mewen Le Reste
// Last update Sun Jan 22 11:58:29 2017 Mewen Le Reste
//

#include "GameInterface.hpp"

GameInterface::GameInterface(Game &game)
{
  sf::RenderWindow &win = game.getWin();
  std::ifstream file(HIGHSCORE, std::ios::in);
  if (file.is_open())
    {
      file >> _highscore;
      file.close();
    }
  else
    _highscore = 0;
  charSize = 30;
  _level = 1;
  _score = 0;
  clock.restart();
  gameMusic.openFromFile(GAME_MUSIC);
  gameMusic.setLoop(true);
  gameMusic.play();
  m12.loadFromFile(FONTM12);
  texture.loadFromFile(INTERFACE);
  background.setTexture(texture);
  background.setPosition(sf::Vector2f(0, 0));
  highscoreText.setFont(m12);
  highscoreText.setColor(sf::Color::White);
  std::stringstream highStr;
  highStr << "Highscore " << _highscore;
  highscoreText.setString(highStr.str());
  highscoreText.setCharacterSize(charSize);
  highscoreText.setPosition(sf::Vector2f(1340, 45));
  scoreText.setFont(m12);
  scoreText.setColor(sf::Color::White);
  std::stringstream scoreStr;
  scoreStr << "Score " << _score;
  scoreText.setString(scoreStr.str());
  scoreText.setCharacterSize(charSize);
  scoreText.setPosition(sf::Vector2f(1340, 225));
  timerText.setFont(m12);
  timerText.setColor(sf::Color::White);
  std::stringstream timeStr;
  timeStr << "Time " << clockToString();
  timerText.setString(timeStr.str());
  timerText.setCharacterSize(charSize);
  timerText.setPosition(sf::Vector2f(1340, 405));
  levelText.setFont(m12);
  levelText.setColor(sf::Color::White);
  std::stringstream levelStr;
  levelStr << "Level " << _level;
  levelText.setString(levelStr.str());
  levelText.setCharacterSize(charSize);
  levelText.setPosition(sf::Vector2f(1340, 585));
  escText.setFont(m12);
  escText.setColor(sf::Color::White);
  escText.setString("Press ESC to exit the beat");
  escText.setCharacterSize(18);
  escText.setPosition(sf::Vector2f(1320, 1010));
  win.draw(background);
  win.draw(highscoreText);
  win.draw(scoreText);
  win.draw(timerText);
  win.draw(levelText);
  win.draw(escText);
}

GameInterface::GameInterface(const GameInterface &other)
{
  highscoreText = other.highscoreText;
  scoreText = other.scoreText;
  timerText = other.timerText;
  levelText = other.levelText;
  escText = other.escText;
  clock = other.clock;
  background = other.background;
  texture = other.texture;
  _score = other._score;
  _highscore = other._highscore;
  _level = other._level;
  charSize = other.charSize;
  m12 = other.m12;
}

GameInterface::~GameInterface() {}

GameInterface &GameInterface::operator=(const GameInterface &other)
{
  highscoreText = other.highscoreText;
  scoreText = other.scoreText;
  timerText = other.timerText;
  levelText = other.levelText;
  escText = other.escText;
  clock = other.clock;
  background = other.background;
  texture = other.texture;
  _score = other._score;
  _highscore = other._highscore;
  _level = other._level;
  charSize = other.charSize;
  m12 = other.m12;
  return *this;
}

void GameInterface::save()
{
  std::ofstream file(HIGHSCORE, std::ios::out | std::ios::trunc);
  if (file.is_open())
  {
    file << _highscore;
    file.close();
  }
}

void GameInterface::update(Game &game, const bool &gameOver)
{
  if (gameOver)
    gameMusic.stop();
  sf::RenderWindow &win = game.getWin();
  std::stringstream highStr;
  highStr << "Highscore " << _highscore;
  highscoreText.setString(highStr.str());
  std::stringstream scoreStr;
  scoreStr << "Score " << _score;
  scoreText.setString(scoreStr.str());
  if (!gameOver)
  {
    std::stringstream timeStr;
    timeStr << "Time " << clockToString();
    timerText.setString(timeStr.str());
  }
  std::stringstream levelStr;
  levelStr << "Level " << _level;
  levelText.setString(levelStr.str());
  win.draw(background);
  win.draw(highscoreText);
  win.draw(scoreText);
  win.draw(timerText);
  win.draw(levelText);
  win.draw(escText);
}

unsigned int GameInterface::getScore() const
{
  return _score;
}

unsigned int GameInterface::getLevel() const
{
  return _level;
}

std::string GameInterface::clockToString()
{
  sf::Time elapsed = clock.getElapsedTime();
  std::stringstream str;
  int hour = 0, min = 0, sec = elapsed.asSeconds();
  while (sec > 60)
  {
    sec -= 60;
    ++min;
  }
  while (min > 60)
  {
    min -= 60;
    ++hour;
  }
  if (hour != 0)
    str << hour << "h " << min << "." << sec;
  else if (min != 0)
    str << min << "." << sec;
  else
    str << "0." << sec;
  return str.str();
}

GameInterface &GameInterface::operator++()
{
  _level++;
  return *this;
}

GameInterface &GameInterface::operator++(int value)
{
  (void)value;
  _level++;
  return *this;
}

GameInterface &GameInterface::operator+=(unsigned int add)
{
  _score += add;
  if (_score > _highscore)
    _highscore = _score;
  save();
  return *this;
}
