//
// AMutex.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 13:38:56 2014 Guillaume
// Last update Tue May 20 13:38:57 2014 Guillaume
//

#ifndef			AMUTEX_HH_
# define		AMUTEX_HH_

class			AMutex
{
protected:
  bool			_isInit;

public:
  AMutex();
  virtual ~AMutex() {}
  virtual void		create(void) = 0;
  virtual void		lock(void) = 0;
  virtual int		trylock(void) = 0;
  virtual void		unlock(void) = 0;
  virtual void		destroy(void) = 0;
  virtual bool		isInit(void) const;
};

#endif
