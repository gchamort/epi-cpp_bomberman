//
// Bomb.cpp for bomberman in /home/lecler_k/rendu/cpp_bomberman/src
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Sat May 10 17:55:36 2014 Brice Leclercq
// Last update Thu Jun  5 07:22:14 2014 Pierre Morel
//

#include	"Bomb.hh"

Bomb::Bomb(unsigned int pos_x, unsigned int pos_y)
{
  _pos_x = pos_x;
  _pos_y = pos_y;
  _range = 3;
  _type = 'B';
}

Bomb::~Bomb()
{ 
}

bool		Bomb::m_destroy()
{
  return true;
}

bool		Bomb::m_explose()
{
  return true;
}

unsigned int	Bomb::getPosX() const
{
  return _pos_x;
}

unsigned int	Bomb::getPosY() const
{
  return _pos_y;
}

unsigned int	Bomb::getRange() const
{
  return _range;
}

unsigned int	Bomb::getType() const
{
  return _type;
}

void		Bomb::setX(unsigned int x)
{
  _pos_x = x;
}

void		Bomb::setY(unsigned int y)
{
  _pos_y = y;
}

void		Bomb::setRange(unsigned int range)
{
  _range = range;
}

void		Bomb::m_pushed(Direction dir)
{
  (void)dir;
}
