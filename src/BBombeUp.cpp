//
// BBombeUp.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 17:46:19 2014 Julien ANDRE
// Last update Mon May 12 17:50:22 2014 Julien ANDRE
//

#include	"BBombeUp.hh"

BBombeUp::BBombeUp(unsigned int pos_x, unsigned int pos_y) : ABonus(pos_x, pos_y)
{
}

BBombeUp::~BBombeUp()
{
}

void	BBombeUp::m_doBonus(Player &player) const
{
  player.setNbrBombe(player.getNbrBombe() + 1);
}
