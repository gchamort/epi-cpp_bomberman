//
// BSpeedUp.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 16:54:10 2014 Julien ANDRE
// Last update Mon May 12 16:59:30 2014 Julien ANDRE
//

#include	"BSpeedUp.hh"

BSpeedUp::BSpeedUp(unsigned int pos_x, unsigned int pos_y) : ABonus(pos_x, pos_y)
{
}

BSpeedUp::~BSpeedUp()
{
}

void	BSpeedUp::m_doBonus(Player &player) const
{
  player.setSpeed(player.getSpeed() + 1);
}
