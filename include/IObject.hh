//
// IObject.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 16:37:32 2014 Julien ANDRE
// Last update Sun Jun 15 18:35:28 2014 Brice Leclercq
//

#ifndef		__IOBJECT__HH__
# define	__IOBJECT__HH__

# include	"Factory.hh"
# include	"Player.hh"

enum {B, X, S};

typedef	enum {
  STAND,
  RIGHT,
  LEFT,
  UP,
  DOWN
}	Direction;

class			IObject
{
public:
  virtual		~IObject() {}
  virtual unsigned int	getPosX() const = 0;
  virtual unsigned int	getPosY() const = 0;
  virtual unsigned int	getType() const = 0;
};

#endif		/* __IOBJECT__HH__ */
