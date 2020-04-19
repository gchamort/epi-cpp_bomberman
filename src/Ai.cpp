//
// Ai.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Fri May 30 12:47:26 2014 Julien ANDRE
// Last update Fri Jun 13 16:37:29 2014 Julien ANDRE
//

#include	"Ai.hh"

Ai::Ai(Map *map)
{
  _mapPointer = map;
}

Ai::~Ai()
{
}

bool		Ai::m_moveBot(Player *bot)
{
  _L = luaL_newstate();
  luaL_openlibs(_L);
  if (luaL_dofile(_L, "lua/ai.lua") != 0)
    {
      std::cerr << "Invalid script for ai." << std::endl;
      return false;
    }
  m_loadMap();
  m_loadSize();
  m_loadPlayer(bot);
  m_loadObjects();
  m_updateMap();
  m_getDir();
  lua_pop(_L, 1);
  return true;
}

bool		Ai::m_loadMap() const
{
  lua_getglobal(_L, "getString");
  if (!lua_isfunction(_L, -1))
    {
      std::cerr << "getString is not a fonction." << std::endl;
      lua_pop(_L, 1);
      return false;
    }
  lua_pushstring(_L, _mapPointer->getMap().c_str());
  lua_call(_L, 1, 0);
  return true;
}

bool		Ai::m_loadPlayer(Player *bot) const
{
  lua_getglobal(_L, "getPlayer");
  if (!lua_isfunction(_L, -1))
    {
      std::cerr << "getPlayer is not a fonction." << std::endl;
      lua_pop(_L, 1);
      return false;
    }
  lua_pushnumber(_L, bot->getPosX());
  lua_pushnumber(_L, bot->getPosY());
  lua_pushnumber(_L, bot->getNbrBombe());
  lua_call(_L, 3, 0);
  m_loadEnemy(bot);
  return true;
}

bool		Ai::m_loadEnemy(Player *bot) const
{
  std::list<Player *>::iterator	it = _mapPointer->getPlayers().begin();
  std::list<Player *>::iterator	it_end = _mapPointer->getPlayers().end();

  while (it != it_end)
    {
      if ((*it) != bot)
	{
	  lua_getglobal(_L, "addPlayer");
	  if (!lua_isfunction(_L, -1))
	    {
	      std::cerr << "addPlayer is not a fonction." << std::endl;
	      lua_pop(_L, 1);
	      return false;
	    }
	  lua_pushnumber(_L, (*it)->getPosX());
	  lua_pushnumber(_L, (*it)->getPosY());
	  lua_call(_L, 2, 0);
	}
      ++it;
    }
  return true;
}

bool		Ai::m_loadSize() const
{
  lua_getglobal(_L, "getSize");
  if (!lua_isfunction(_L, -1))
    {
      std::cerr << "getSize is not a fonction." << std::endl;
      lua_pop(_L, 1);
      return false;
    }
  lua_pushnumber(_L, _mapPointer->getLength());
  lua_pushnumber(_L, _mapPointer->getWidth());
  lua_call(_L, 2, 0);
  return true;
}

bool		Ai::m_loadObjects() const
{
  std::list<IObject *>::const_iterator	it = _mapPointer->getObjects().begin();
  std::list<IObject *>::const_iterator	it_end = _mapPointer->getObjects().end();
  int					type;
  
  while (it != it_end)
    {
      type = (*it)->getType();
      if (type == 'B')
	m_loadBomb(it);
      if (type == 'S')
	m_loadBonus(it);
      if (type == 'X')
	m_loadBox(it);
     ++it;
    }
  return true;
}

bool		Ai::m_loadBomb(std::list<IObject *>::const_iterator it) const
{
  lua_getglobal(_L, "addBomb");
  if (!lua_isfunction(_L, -1))
    {
      std::cerr << "addBomb is not a fonction." << std::endl;
      lua_pop(_L, 1);
      return false;
    }
  lua_pushnumber(_L, (*it)->getPosX());
  lua_pushnumber(_L, (*it)->getPosY());
  lua_pushnumber(_L, dynamic_cast<Bomb *>((*it))->getRange());
  lua_call(_L, 3, 0);
  return true;
}

bool		Ai::m_loadBonus(std::list<IObject *>::const_iterator it) const
{
  lua_getglobal(_L, "addBonus");
  if (!lua_isfunction(_L, -1))
    {
      std::cerr << "addBonus is not a fonction." << std::endl;
      lua_pop(_L, 1);
      return false;
    }
  lua_pushnumber(_L, (*it)->getPosX());
  lua_pushnumber(_L, (*it)->getPosY());
  lua_call(_L, 2, 0);
  return true;
}

bool		Ai::m_loadBox(std::list<IObject *>::const_iterator it) const
{
  lua_getglobal(_L, "addBox");
  if (!lua_isfunction(_L, -1))
    {
      std::cerr << "addBox is not a fonction." << std::endl;
      lua_pop(_L, 1);
      return false;
    }
  lua_pushnumber(_L, (*it)->getPosX());
  lua_pushnumber(_L, (*it)->getPosY());
  lua_call(_L, 2, 0);
  return true;
}

bool	Ai::m_updateMap() const
{
  lua_getglobal(_L, "updateMap");
  if (!lua_isfunction(_L, -1))
    {
      std::cerr << "updateMap is not a fonction." << std::endl;
      lua_pop(_L, 1);
      return false;
    }
  lua_call(_L, 0, 0);
  return true;
}

Direction	Ai::m_getDir() const
{
  Direction	ret[5] = {STAND, RIGHT, LEFT, UP, DOWN};

  lua_getglobal(_L, "moveBot");
  if (!lua_isfunction(_L, -1))
    {
      std::cerr << "moveBot is not a fonction." << std::endl;
      lua_pop(_L, 1);
      return ret[0];
    }
  lua_call(_L, 0, 1);
  return ret[static_cast<int>(lua_tonumber(_L, 1))];
}

// bool	Ai::m_dumpStack()
// {
//   int i;
//   int top = lua_gettop(_L);
 
//   lua_getglobal(_L, "dump");
//   if (!lua_isfunction(_L, -1))
//     {
//       std::cerr << "dump is not a fonction." << std::endl;
//       lua_pop(_L, 1);
//       return false;
//     }
//   lua_call(_L, 0, 0);
//   printf("total in stack %d\n",top);
 
//   for (i = 1; i <= top; i++)
//     {  /* repeat for each level */
//       int t = lua_type(_L, i);
//       switch (t) {
//       case LUA_TSTRING:  /* strings */
// 	printf("string: '%s'\n", lua_tostring(_L, i));
// 	break;
//       case LUA_TBOOLEAN:  /* booleans */
// 	printf("boolean %s\n",lua_toboolean(_L, i) ? "true" : "false");
// 	break;
//       case LUA_TNUMBER:  /* numbers */
// 	printf("number: %g\n", lua_tonumber(_L, i));
// 	break;
//       default:  /* other values */
// 	printf("%s\n", lua_typename(_L, t));
// 	break;
//       }
//       printf("  ");  /* put a separator */
//     }
//   printf("\n");  /* end the listing */
//   return true;
// }
