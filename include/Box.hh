//
// Box.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Tue May 13 17:35:26 2014 Julien ANDRE
// Last update Sun Jun 15 18:33:29 2014 Brice Leclercq
//

#ifndef		__BOX__HH__
# define	__BOX__HH__

#include	"IObject.hh"

class		Box : public IObject
{
private:
  unsigned int	_pos_x;
  unsigned int	_pos_y;
  unsigned int	_type;
  Factory	*_factory;

public:
			Box(unsigned int, unsigned int);
  virtual		~Box();
  virtual unsigned int	getPosX() const;
  virtual unsigned int	getPosY() const;
  virtual unsigned int	getType() const;
  
  IObject		*m_freeBonus() const;
};

#endif		/* __BOX__HH__ */
