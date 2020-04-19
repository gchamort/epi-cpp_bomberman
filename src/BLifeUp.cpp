//
// BLifeup.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 17:41:01 2014 Julien ANDRE
// Last update Mon May 12 17:45:59 2014 Julien ANDRE
//

#include	"BLifeUp.hh"

BLifeUp::BLifeUp(unsigned int pos_x, unsigned int pos_y) : ABonus(pos_x, pos_y)
{
}

BLifeUp::~BLifeUp()
{
}

void	BLifeUp::m_doBonus(Player &player) const
{
  player.setNbrLife(player.getNbrLife() + 1);
}
