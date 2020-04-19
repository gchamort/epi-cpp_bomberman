//
// Cond.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Mon May 26 15:50:27 2014 Guillaume
// Last update Mon May 26 17:08:35 2014 Guillaume
//

#ifndef			COND_HH_
# define		COND_HH_

# include		<pthread.h>
# include		<sys/time.h>
# include		"ACond.hh"

class			Cond : public ACond
{
  pthread_cond_t	_cond;
  pthread_mutex_t	_mutex;

public:
  virtual ~Cond();
  virtual void		create(void);
  virtual void		destroy(void);
  virtual void		wait(void);
  virtual int		waitTimer(long);
  virtual void		signal(void);
  virtual void		broadcast(void);
  virtual void		unlock(void);
};

#endif
