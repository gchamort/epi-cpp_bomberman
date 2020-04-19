//
// ABonus.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 16:40:29 2014 Julien ANDRE
// Last update Sun Jun 15 18:30:23 2014 Brice Leclercq
//

#ifndef		__ABONUS__HH__
# define	__ABONUS__HH__

# include	"IObject.hh"

class		ABonus : public IObject
{
private:
  unsigned int	_pos_x;
  unsigned int	_pos_y;
  unsigned int	_type;
  
public:
			ABonus(unsigned int, unsigned int);
  virtual		~ABonus();

  virtual unsigned int	getPosX() const;
  virtual unsigned int	getPosY() const;
  virtual unsigned int	getType() const;

  virtual void		m_doBonus(Player &) const = 0;
};

#endif		/* __ABONUS__HH__ */
