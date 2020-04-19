//
// Thread.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 14:03:53 2014 Guillaume
// Last update Fri May 30 16:16:17 2014 Guillaume
//

#ifndef			THREAD_HH_
# define		THREAD_HH_

# include		<pthread.h>
# include		"AThread.hh"

class			Threadpool;

class			Thread : public AThread
{
private:
  bool			_stop;
  pthread_t		_threadid;
  Threadpool*		_threadpoolPtr;

public:
  Thread(Threadpool*);
  virtual ~Thread();
  virtual void		create(threadFunc, void *);
  virtual void		*join() const;
  virtual void		exit(void *) const;
  virtual void		start();
  virtual void		stop();
  virtual void		exec();
};

#endif
