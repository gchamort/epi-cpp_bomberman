//
// GCore.cpp for bomber in /home/chanut_g/rendu/cpp_bomberman/src
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Wed May 28 15:20:46 2014 Guillaume
// Last update Fri May 30 15:06:48 2014 Guillaume
//

#include		<iostream>
#include		<string>
#include		"Core/GCore.hh"

GCore::GCore(Core* core) : ACore(core)
{
  this->_WSizeX = DEF_WX;
  this->_WSizeY = DEF_WY;
  //  this->_map = new Map(this);
}

GCore::~GCore()
{
}

void			GCore::loadGDL()
{
  std::cout << "// chargement des paramètres de la GDL" << std::endl;
}
