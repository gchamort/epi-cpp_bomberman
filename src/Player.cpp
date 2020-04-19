//
// Player.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 16:15:21 2014 Julien ANDRE
// Last update Sun Jun 15 18:43:40 2014 Brice Leclercq
//

#include	"Player.hh"

Player::Player(unsigned int pos_x, unsigned int pos_y)
{
  _pos_x = pos_x;
  _pos_y = pos_y;
  _nbr_bombe = DEF_BOMBE;
  _nbr_life = DEF_LIFE;
  _speed = DEF_SPEED;
  _id = m_create_id();
  _push = false;
}

Player::~Player()
{
}

unsigned int	Player::getPosX() const
{
  return _pos_x;
}

unsigned int	Player::getPosY() const
{
  return _pos_y;
}

unsigned int	Player::getNbrBombe() const
{
  return _nbr_bombe;
}

unsigned int	Player::getNbrLife() const
{
  return _nbr_life;
}

unsigned int	Player::getSpeed() const
{
  return _speed;
}

unsigned int	Player::getId() const
{
  return _id;
}

bool		Player::getPush() const
{
  return _push;
}

Factory		*Player::getFactory() const
{
  return _factory;
}

unsigned int	Player::m_create_id() const
{
  unsigned int	res;

  srand(time(NULL));
  res = rand() % 1000 + 1000;
  return res;
}

void		Player::setSpeed(unsigned int value)
{
  _speed = value;
}

void		Player::setNbrBombe(unsigned int value)
{
  _nbr_bombe = value;
}

void		Player::setNbrLife(unsigned int value)
{
  _nbr_life = value;
}

void		Player::setPush(bool push)
{
  _push = push;
}

void		Player::setFactory(Factory *factory)
{
  _factory = factory;
}

void		Player::m_goRight()
{
  ++_pos_x;
  _state = Standing;
}

void		Player::m_goLeft()
{
  --_pos_x;
  _state = Standing;
}

void		Player::m_goUp()
{
  --_pos_y;
  _state = Standing;
}

void		Player::m_goDown()
{
  ++_pos_y;
  _state = Standing;
}

unsigned int	Player::getScore() const
{
  return _score;
}
