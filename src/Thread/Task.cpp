//
// Task.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Fri May 30 16:45:47 2014 Guillaume
// Last update Mon Jun  2 14:15:51 2014 Guillaume
//

#include		"Thread/Task.hh"

Task::Task(Task const &tmp)
{
  this->_funcPtr = tmp._funcPtr;
  this->_arg = tmp._arg;
}

Task::Task(void *(*funcPtr)(void*), void* arg) : _funcPtr(funcPtr), _arg(arg) {}

Task::~Task() {}

void			Task::run()
{
  if (_funcPtr != NULL)
    (*_funcPtr)(_arg);
}
