//
// Mutex.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 13:39:08 2014 Guillaume
// Last update Mon May 26 17:08:16 2014 Guillaume
//

#ifndef			MUTEX_HH_
# define		MUTEX_HH_

# include		<pthread.h>
# include		"AMutex.hh"

class			Mutex : public AMutex
{
private:
  pthread_mutex_t	_mutex;

public:
  Mutex();
  virtual ~Mutex();
  virtual void		create(void);
  virtual void		lock(void);
  virtual int		trylock(void);
  virtual void		unlock(void);
  virtual void		destroy(void);
};

#endif
