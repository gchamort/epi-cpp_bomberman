//
// AThread.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 14:03:19 2014 Guillaume
// Last update Tue May 20 14:03:20 2014 Guillaume
//

#ifndef			ATHREAD_HH_
# define		ATHREAD_HH_

# include		<stdlib.h>

typedef void		*(*threadFunc)(void*);

class			AThread
{
protected:
  threadFunc		_func;
  void			*_param;

public:
  AThread();
  virtual ~AThread() {}
  virtual void		create(threadFunc, void *) = 0;
  virtual void		*join() const = 0;
  virtual void		exit(void *) const = 0;
  virtual void		stop() = 0;
  virtual void		exec() = 0;
};

#endif
