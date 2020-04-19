//
// Threadpool.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Fri May 30 16:04:51 2014 Guillaume
// Last update Mon Jun  2 16:51:44 2014 Guillaume
//

#ifndef			THREADPOOL_HH_
# define		THREADPOOL_HH_

# include		"Thread/Cond.hh"
# include		"Thread/Mutex.hh"
# include		"Thread/Thread.hh"
# include		"Thread/Task.hh"
# include		<vector>
# include		<deque>

# define		DEFAULT_THREADPOOL_SIZE		4
# define		POOL_START			0
# define		POOL_STOP			1

class			Thread;

class			Threadpool
{
private:
  Mutex			_mutex;
  Cond			_condVar;

  unsigned short	_poolSize;
  volatile short	_poolState;

  std::vector<Thread>	_poolThreads;
  std::deque<Task*>	_poolTasks;

public:
  Threadpool();
  Threadpool(int);
  ~Threadpool();

  void			stop();
  void			start();
  void			init();
  void			launch();
  void			destroy();
  void			addTask(Task*);
  bool			takeTask(Task* &);
  void			condVarWait();
};

#endif
