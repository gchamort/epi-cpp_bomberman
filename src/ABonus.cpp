//
// ABonus.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 16:49:41 2014 Julien ANDRE
// Last update Thu Jun  5 07:21:52 2014 Pierre Morel
//

#include	"ABonus.hh"

ABonus::ABonus(unsigned int pos_x, unsigned int pos_y)
{
  _pos_x = pos_x;
  _pos_y = pos_y;
  _type = 'S';
}

ABonus::~ABonus()
{
}

unsigned int	ABonus::getPosX() const
{
  return _pos_x;
}

unsigned int	ABonus::getPosY() const
{
  return _pos_y;
}

unsigned int	ABonus::getType() const
{
  return _type;
}
