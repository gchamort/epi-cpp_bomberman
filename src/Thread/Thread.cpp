//
// Thread.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 14:09:53 2014 Guillaume
// Last update Wed Jun  4 18:36:17 2014 Brice Leclercq
//

#include		"Thread/Threadpool.hh"
#include		"MyError.hh"

Thread::Thread(Threadpool *ptr) : AThread(), _threadpoolPtr(ptr) {}

Thread::~Thread() {}

void                    Thread::create(threadFunc func, void *param)
{
  this->_param = param;
  this->_func = func;
  if (pthread_create(&(this->_threadid), NULL, func, param) != 0)
    throw MyError("function pthread_create() failed");
}

void*			Thread::join() const
{
  void			*ret;

  pthread_join(this->_threadid, &(ret));
  // TODO checker si ret == "EDEADLK"
  return (ret);
}

void			Thread::exit(void *ret) const
{
  pthread_exit(ret);
}

void			Thread::start()
{
  this->_stop = false;
}

void			Thread::stop()
{
  this->_stop = true;
}

void			Thread::exec()
{
  Task*			task = NULL;

  while (!this->_stop)
    {
      if (this->_threadpoolPtr->takeTask(task) == false)
	this->_threadpoolPtr->condVarWait();
      else {
	task->run();
	delete task;
      }
    }
}
