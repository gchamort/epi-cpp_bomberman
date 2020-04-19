//
// Ai.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Fri May 30 12:43:51 2014 Julien ANDRE
// Last update Sun Jun 15 18:30:32 2014 Brice Leclercq
//

#ifndef		__AI__HH__
# define	__AI__HH__

#include	<iostream>

#include	"Map.hh"
#include	"lua/lua.hpp"
#include	"lua/lualib.h"

class		Ai
{
private:
  Map		*_mapPointer;
  lua_State	*_L;

public:
  Ai(Map *);
  ~Ai();
  bool		m_moveBot(Player *);
  bool		m_loadMap() const;
  bool		m_loadPlayer(Player *) const;
  bool		m_loadObjects() const;
  bool		m_loadSize() const;
  bool		m_updateMap() const;
  bool		m_dumpStack();
  bool		m_loadEnemy(Player *) const;
  bool		m_loadBomb(std::list<IObject *>::const_iterator it) const;
  bool		m_loadBonus(std::list<IObject *>::const_iterator it) const;
  bool		m_loadBox(std::list<IObject *>::const_iterator it) const;
  Direction	m_getDir() const;
};

#endif		/* __AI_HH__ */
