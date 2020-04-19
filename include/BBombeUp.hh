//
// BBombeUp.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 17:46:41 2014 Julien ANDRE
// Last update Sun Jun 15 18:31:00 2014 Brice Leclercq
//

#ifndef		__BBOMBEUP__HH__
# define	__BBOMBEUP__HH__

#include	"ABonus.hh"

class		BBombeUp : public ABonus
{
public:
		BBombeUp(unsigned int, unsigned int);
  virtual	~BBombeUp();
  virtual void	m_doBonus(Player &) const;
};

#endif		/* __BBOMBEUP__HH__ */
