//
// Bomb.hh for bomberman in /home/lecler_k/rendu/cpp_bomberman/include
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Tue May 13 17:36:07 2014 Brice Leclercq
// Last update Sun Jun 15 18:32:51 2014 Brice Leclercq
//

#ifndef		__BOMB__HH__
# define	__BOMB__HH__

#include	"IObject.hh"

class			Bomb : public IObject
{
private:
  unsigned int		_pos_x;
  unsigned int		_pos_y;
  unsigned int		_range;
  unsigned int		_type;

public:
			Bomb(unsigned int, unsigned int);
  virtual		~Bomb();
  
  virtual unsigned int	getType() const;
  virtual unsigned int	getPosX() const;
  virtual unsigned int	getPosY() const;
  unsigned int		getRange() const;

  void			setX(unsigned int);
  void			setY(unsigned int);
  void			setRange(unsigned int);

  void			m_pushed(Direction);
  bool			m_destroy();
  bool			m_explose();
};

#endif		/* __BOMB__HH__ */
