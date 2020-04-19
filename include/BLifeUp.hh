//
// BLifeUp.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 17:38:51 2014 Julien ANDRE
// Last update Sun Jun 15 18:32:29 2014 Brice Leclercq
//

#ifndef		__BLIFEUP__HH__
# define	__BLIFEUP__HH__

# include	"ABonus.hh"

class		BLifeUp : public ABonus
{
public:
		BLifeUp(unsigned int, unsigned int);
  virtual	~BLifeUp();
  virtual void	m_doBonus(Player &) const;
};

#endif		/* __BLIFEUP__HH__ */
