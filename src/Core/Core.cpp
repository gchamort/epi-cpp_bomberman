//
// Core.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Wed May 28 15:14:49 2014 Guillaume
// Last update Mon Jun  2 15:37:13 2014 Guillaume
//

#include		<unistd.h>
#include		"Core/GCore.hh"
#include		"Thread/Threadpool.hh"
#include		"MyError.hh"

Core::Core() :  ACore(NULL)
{
  try {
    this->_threadpool = new Threadpool();
    this->_gCore = new GCore(this);
    this->_threadpool->init();
    this->_threadpool->launch();
  }
  catch (MyError& e) {
    std::cerr << e.what() << std::endl;
  }
  this->_sound = true;
}

Core::~Core()
{
  this->_threadpool->destroy();
  delete this->_gCore;
  delete this->_threadpool;
}

void			*tmp(void *abc)
{
  std::string* str = static_cast<std::string*>(abc);
  std::cout << "Fonction tmp " << *str << std::endl;
  return NULL;
}

void			Core::intro()
{
  this->_threadpool->addTask(new Task(&tmp, new std::string("d'intro")));
  usleep(500000);
}

void			Core::launchMenu()
{
  this->_threadpool->addTask(new Task(&tmp, new std::string("du menu")));
  usleep(500000);
  this->startGame();
}

void			Core::startGame()
{
  this->_threadpool->addTask(new Task(&tmp, new std::string("du jeu")));
}

void			Core::end()
{
  this->_threadpool->stop();
}
