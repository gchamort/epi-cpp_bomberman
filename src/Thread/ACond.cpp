//
// ACond.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src/Thread
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Mon May 26 15:51:21 2014 Guillaume
// Last update Mon May 26 15:51:22 2014 Guillaume
//

#include		"Thread/ACond.hh"

ACond::ACond()
{
  this->_isInit = false;
  this->_isLock = false;
}

bool			ACond::getIsInit(void) const
{
  return (this->_isInit);
}

bool			ACond::getIsLock(void) const
{
  return (this->_isLock);
}
