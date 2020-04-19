//
// Task.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Fri May 30 16:49:24 2014 Guillaume
// Last update Mon Jun  2 14:14:51 2014 Guillaume
//

#ifndef			TASK_HH_
# define		TASK_HH_

# include		<string>

class			Task
{
private:
  void			*(*_funcPtr)(void*);
  void*			_arg;

public:
  Task(Task const &);
  Task(void *(*funcPtr)(void*), void *);
  ~Task();

  void			run();
};

#endif
