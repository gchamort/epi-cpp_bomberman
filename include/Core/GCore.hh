//
// GCore.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Wed May 28 15:21:05 2014 Guillaume
// Last update Fri May 30 15:05:57 2014 Guillaume
//

#ifndef			GCORE_HH_
# define		GCORE_HH_

# include		"Core.hh"
//# include		"Map.hh"

# define		DEF_WX		800
# define		DEF_WY		600

class			Map;

class			GCore : public ACore
{
private:
  unsigned short	_WSizeX;
  unsigned short	_WSizeY;
  Map*			_map;

public:
  GCore(Core *core);
  virtual ~GCore();

  void			loadGDL();
};

#endif
