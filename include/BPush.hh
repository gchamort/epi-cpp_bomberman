//
// BPush.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 18:04:12 2014 Julien ANDRE
// Last update Sun Jun 15 18:33:52 2014 Brice Leclercq
//

#ifndef		__BPUSH__HH__
# define	__BPUSH__HH__

#include	"ABonus.hh"

class		BPush : public ABonus
{
public:
		BPush(unsigned int, unsigned int);
  virtual	~BPush();
  virtual void	m_doBonus(Player &) const;
};

#endif		/* __BPUSH__HH__ */
