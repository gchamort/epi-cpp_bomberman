//
// BPush.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 18:06:51 2014 Julien ANDRE
// Last update Mon May 12 18:08:35 2014 Julien ANDRE
//

#include	"BPush.hh"

BPush::BPush(unsigned int pos_x, unsigned int pos_y) : ABonus(pos_x, pos_y)
{
}

BPush::~BPush()
{
}

void	BPush::m_doBonus(Player &player) const
{
  player.setPush(true);
}
