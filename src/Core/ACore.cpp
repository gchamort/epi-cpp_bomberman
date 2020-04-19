//
// ACore.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Wed May 28 17:21:08 2014 Guillaume
// Last update Fri May 30 14:48:54 2014 Guillaume
//

#include		"Core/ACore.hh"

ACore::ACore(ACore* ptr)
{
  this->_ptrCoreParent = ptr;
}

ACore::~ACore() {}
