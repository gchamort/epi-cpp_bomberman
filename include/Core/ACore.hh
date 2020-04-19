//
// ACore.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Wed May 28 16:54:49 2014 Guillaume
// Last update Fri May 30 14:25:26 2014 Guillaume
//

#ifndef			ACORE_HH_
# define		ACORE_HH_

# include		"Thread/Thread.hh"
# include		"Thread/Mutex.hh"

class			ACore
{
private:
  ACore*		_ptrCoreParent;

public:
  ACore(ACore*);
  virtual ~ACore();
};

#endif
