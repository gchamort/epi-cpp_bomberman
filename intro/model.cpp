//
// model.cpp for bomberman in /home/lecler_k/GL/src/intro
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Fri Jun 13 15:12:14 2014 Brice Leclercq
// Last update Fri Jun 13 18:42:40 2014 Brice Leclercq
//

#include "model.hpp"

Model::Model()
{

}

Model::~Model()
{

}

bool		Model::init()
{
  if (!_context.start(800, 600, "Bomberman"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (_model.load("./assets/marvin.fbx" == false))
    {
      std::cerr << "Can't load the marvin texture" << std::endl;
      return false;
    }
  return true;
  //il faut seter la position du marvin dans la fenetre.
}

void		Model::init(float &x, float &y, float &z)
{
  //init de la 
}    

void		Model::update()
{
  
}

void		Model::draw()
{
  
  _model.draw() //refaire une draw avec les nouvelles informations, a mettre avant
}
