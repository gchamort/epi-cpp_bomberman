//
// ACond.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Mon May 26 15:50:45 2014 Guillaume
// Last update Mon May 26 15:51:00 2014 Guillaume
//

#ifndef			ACOND_HH_
# define		ACOND_HH_

class			ACond
{
protected:
  bool			_isLock;
  bool			_isInit;

public:
  ACond();
  virtual ~ACond() {}
  virtual void		create(void) = 0;
  virtual void		destroy(void) = 0;
  virtual void		wait(void) = 0;
  virtual int		waitTimer(long) = 0;
  virtual void		signal(void) = 0;
  virtual void		broadcast(void) = 0;
  virtual void		unlock(void) = 0;
  virtual bool		getIsInit(void) const;
  virtual bool		getIsLock(void) const;
};

#endif
