//
// MyError.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 14:29:54 2014 Guillaume
// Last update Mon May 26 16:58:38 2014 Guillaume
//

#include		<sstream>
#include		"MyError.hh"

MyError::MyError(const std::string &err) : std::runtime_error(err), _err("BOMBERMAN ERROR: " + err)
{
}

MyError::~MyError()	throw() {}

const char		*MyError::what() const throw()
{
  return (this->_err.c_str());
}
