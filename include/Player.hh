//
// Player.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 15:14:17 2014 Julien ANDRE
// Last update Sun Jun 15 18:37:39 2014 Brice Leclercq
//

#ifndef		__PLAYER__HH__
# define	__PLAYER__HH__

# include	<cstdlib>
# include	<ctime>
# include	<string>

# include	"Factory.hh"

# define	DEF_BOMBE	1
# define	DEF_LIFE	3
# define	DEF_SPEED	1

typedef		enum {
  Standing,
  GoingRight,
  GoingLeft,
  GoingUp,
  GoingDown
}		State;

class		Player
{
private:
  unsigned int	_pos_x;
  unsigned int	_pos_y;
  unsigned int	_nbr_bombe;
  unsigned int	_nbr_life;
  unsigned int	_speed;
  unsigned int	_id;
  bool		_push;
  State		_state;
  Factory	*_factory;
  std::string	_name;
  unsigned int	_score;

public:
		Player(unsigned int, unsigned int);
		~Player();
  unsigned int	getPosX() const;
  unsigned int	getPosY() const;
  unsigned int	getNbrBombe() const;
  unsigned int	getNbrLife() const;
  unsigned int	getSpeed() const;
  unsigned int	getId() const;
  bool		getPush() const;
  Factory	*getFactory() const;
  unsigned int	getScore() const;

  void		setSpeed(unsigned int);
  void		setNbrLife(unsigned int);
  void		setNbrBombe(unsigned int);
  void		setPush(bool);
  void		setFactory(Factory *);

  unsigned int	m_create_id() const;

  void		m_goRight();
  void		m_goLeft();
  void		m_goUp();
  void		m_goDown();
};



#endif		/* __PLAYER__HH__ */
