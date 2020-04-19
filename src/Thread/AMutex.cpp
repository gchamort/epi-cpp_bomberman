//
// AMutex.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 14:06:08 2014 Guillaume
// Last update Mon May 26 17:05:25 2014 Guillaume
//

#include		"Thread/AMutex.hh"

AMutex::AMutex()
{
  this->_isInit = false;
}

bool			AMutex::isInit(void) const
{
  return (this->_isInit);
}
