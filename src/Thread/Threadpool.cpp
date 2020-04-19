//
// Threadpool.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Fri May 30 16:04:05 2014 Guillaume
// Last update Tue Jun  3 15:41:45 2014 Guillaume
//

#include <iostream>
#include		"Thread/Threadpool.hh"

Threadpool::Threadpool() : _poolSize(DEFAULT_THREADPOOL_SIZE) {}

Threadpool::Threadpool(int poolSize) : _poolSize(poolSize) {}

Threadpool::~Threadpool()
{
  if (this->_poolState != POOL_STOP)
    this->destroy();
}

void			Threadpool::start()
{
  this->_poolState = POOL_START;
  for (unsigned int i = 0; i < this->_poolThreads.size(); ++i)
    this->_poolThreads[i].start();
}

void			Threadpool::stop()
{
  this->_poolState = POOL_STOP;
  for (unsigned int i = 0; i < this->_poolThreads.size(); ++i)
    this->_poolThreads[i].stop();
}

void			Threadpool::init()
{
  this->_poolState = POOL_START;
  this->_poolThreads.resize(this->_poolSize, Thread(this));
  this->_condVar.create();
}

void*			start_thread(void* arg)
{
  Thread* thread = static_cast<Thread*>(arg);
  thread->exec();
  return NULL;
}

void			Threadpool::launch()
{
  for (unsigned int i = 0; i < this->_poolThreads.size(); ++i)
    this->_poolThreads[i].create(&start_thread, &(this->_poolThreads[i]));
}

void			Threadpool::destroy()
{
  this->_mutex.lock();
  this->_poolState = POOL_STOP;
  this->_mutex.unlock();
  this->_condVar.broadcast();
  for (unsigned int i = 0; i < this->_poolThreads.size(); ++i)
    this->_poolThreads[i].join();
}

void			Threadpool::addTask(Task* task)
{
  this->_mutex.lock();
  this->_poolTasks.push_back(task);
  this->_condVar.signal();
  this->_condVar.broadcast();
  this->_mutex.unlock();
}

bool			Threadpool::takeTask(Task* &task)
{
  this->_mutex.lock();
  if (this->_poolTasks.empty()) {
    this->_mutex.unlock();
    return false;
  }
  task = new Task(*(this->_poolTasks[0]));
  this->_poolTasks.pop_front();
  this->_mutex.unlock();
  return true;
}

void			Threadpool::condVarWait()
{
  this->_condVar.wait();
}
