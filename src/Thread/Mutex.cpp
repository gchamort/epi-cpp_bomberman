//
// Mutex.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 14:06:49 2014 Guillaume
// Last update Fri May 30 15:59:40 2014 Guillaume
//

#include		"Thread/Mutex.hh"

Mutex::Mutex()
{
  this->create();
}

Mutex::~Mutex()
{
  this->destroy();
}

void			Mutex::create(void)
{
  pthread_mutex_init(&(this->_mutex), NULL);
}

void			Mutex::lock(void)
{
  pthread_mutex_lock(&(this->_mutex));
}

int			Mutex::trylock(void)
{
  return (pthread_mutex_trylock(&(this->_mutex)));
}

void			Mutex::unlock(void)
{
  pthread_mutex_unlock(&(this->_mutex));
}

void			Mutex::destroy(void)
{
  pthread_mutex_destroy(&(this->_mutex));
}
