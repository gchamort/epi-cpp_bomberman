//
// Map.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 15:05:56 2014 Julien ANDRE
// Last update Sun Jun 15 18:36:19 2014 Brice Leclercq
//

#ifndef		__MAP__HH__
# define	__MAP__HH__

# include	<string>
# include	<list>

# include	"IObject.hh"
# include	"Factory.hh"
# include	"Bomb.hh"

# define	WALL	'w'
# define	FLOOR	'f'
# define	SPAWN	's'
# define	EXPLO	'e'

class			Map
{
private:
  unsigned int		_length;
  unsigned int		_width;
  std::string		_map;
  std::list<Player *>	_players;
  std::list<IObject *>	_objects;
  Factory		*_factory;

public:
  Map(unsigned int, unsigned int);
  ~Map();
  std::string		getMap() const;
  std::list<Player *> &	getPlayers();
  std::list<IObject *> &getObjects();
  Factory		*getFactory() const;
  unsigned int		getLength() const;
  unsigned int		getWidth() const;

  void			setFactory(Factory *);
  void			m_addPlayer(Player *);

  bool			m_checkPosPlayer(unsigned int, unsigned int, Player &) const;
  bool			m_checkPosBomb(Bomb &, Direction) const;
  Direction		m_getDirFromPos(int, int, int, int) const;

  void			m_placeBox();
  void			m_placeWall();
  void			m_placeSpawn();
  void			m_generateMap();
};

#endif		/* __MAP__HH__ */
