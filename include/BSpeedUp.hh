//
// BSpeedUp.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 16:46:09 2014 Julien ANDRE
// Last update Sun Jun 15 18:34:15 2014 Brice Leclercq
//

#ifndef		__BSPEEDUP__HH__
# define	__BSPEEDUP__HH__

#include	"ABonus.hh"

class		BSpeedUp : public ABonus
{
public:
		BSpeedUp(unsigned int, unsigned int);
  virtual	~BSpeedUp();
  virtual void	m_doBonus(Player &) const;
};

#endif		/* __BSPEEDUP__HH__ */
