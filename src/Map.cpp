//
// Map.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 15:09:44 2014 Julien ANDRE
// Last update Tue Jun 10 18:28:22 2014 Julien ANDRE
//

#include	"Map.hh"
#include	<iostream>


Map::Map(unsigned int length, unsigned int width)
{
  _length = length;
  _width = width;
}

Map::~Map()
{
}

std::string		Map::getMap() const
{
  return _map;
}

std::list<Player *> &	Map::getPlayers()
{
  return _players;
}

std::list<IObject *> &	Map::getObjects()
{
  return _objects;
}

Factory			*Map::getFactory() const
{
  return _factory;
}

unsigned int		Map::getLength() const
{
  return _length;
}

unsigned int		Map::getWidth() const
{
  return _width;
}

void			Map::setFactory(Factory *factory)
{
  _factory = factory;
}

void			Map::m_addPlayer(Player *player)
{
  _players.push_back(player);
}

bool			Map::m_checkPosPlayer(unsigned int pos_x, unsigned int pos_y, Player &player) const
{
  std::list<IObject *>::const_iterator	it = _objects.begin();

  if (_map[pos_x + pos_y * _length] == WALL)
    return false;
  while (it != _objects.end())
    {
      if ((*it)->getType() == 'X')
	{
	  if ((*it)->getPosX() == pos_x &&
	      (*it)->getPosY() == pos_y)
	    return false;
	}
      else
	if (player.getPush() == true)
	  {
	    dynamic_cast<Bomb *>
	      ((*it))->m_pushed(m_getDirFromPos(player.getPosX(), player.getPosY(), pos_x, pos_y));
	    return true;
	  }
	else
	  return false;
      ++it;
    }
  return true;
}

bool			Map::m_checkPosBomb(Bomb &bomb, Direction dir) const
{
  unsigned int		pos_x = bomb.getPosX();
  unsigned int		pos_y = bomb.getPosY();
  std::list<IObject *>::const_iterator	it = _objects.begin();
  std::list<Player *>::const_iterator	itp = _players.begin();

  dir == RIGHT ? ++pos_x : (dir == LEFT) ? --pos_x : pos_x;
  dir == DOWN ? ++pos_y : (dir == UP) ? --pos_y : pos_y;      
  if (_map[pos_x + pos_y * _length] == WALL)
    return false;
  while (it != _objects.end())
    {
      if ((*it)->getPosX() == pos_x &&
	  (*it)->getPosY() == pos_y)
	return false;
      ++it;
    }
  while (itp != _players.end())
    {
      if ((*itp)->getPosX() == pos_x &&
	  (*itp)->getPosY() == pos_y)
	return false;
      ++itp;
    }
  return true;
}

Direction		Map::m_getDirFromPos(int pos_x_o, int pos_y_o,
					     int pos_x_a, int pos_y_a) const
{
  if (pos_x_o - pos_x_a > 0)
    return LEFT;
  else if (pos_x_o - pos_x_a < 0)
    return RIGHT;
  if (pos_y_o - pos_y_a > 0)
    return UP;
  else if (pos_y_o - pos_y_a < 0)
    return DOWN;
  return STAND;
}

void			Map::m_placeBox()
{
}

void			Map::m_placeSpawn()
{
  unsigned int		nbr_player = _players.size();
  unsigned int		div_x = _length / nbr_player;
  unsigned int		div_y = _width / nbr_player;
  unsigned int		count = 0;
  unsigned int		affix_x;
  unsigned int		affix_y;
  unsigned int		pos_x;
  unsigned int		pos_y;

  srand(time(NULL));
  while (count != nbr_player)
    {
      affix_x = count * div_x;
      if (count % 2 == 0)
	affix_y = _width - (count + 1) * div_y;
      else
	affix_y = count * div_y;
      pos_x = (rand() % div_x + affix_x);
      pos_y = (rand() % div_y + affix_y);
      if (_map[pos_x + (_length * pos_y)] != SPAWN)
	{
	  _map[pos_x + (_length * pos_y)] = SPAWN;
	  ++count;
	}
    }
}

void			Map::m_placeWall()
{
}

void			Map::m_generateMap()
{
  for (unsigned int i = 0; i != _length * _width; i++)
    _map.push_back(FLOOR);
  if (_players.size() != 0)
    {
      m_placeSpawn();
      m_placeWall();
      m_placeBox();
    }
}
