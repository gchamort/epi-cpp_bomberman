//
// Factory.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 18:30:10 2014 Julien ANDRE
// Last update Wed May 14 10:56:24 2014 Julien ANDRE
//

#include	"Factory.hh"
#include	"BBonus.hh"
#include	"Box.hh"
#include	"Bomb.hh"

Factory::Factory()
{
}

Factory::~Factory()
{
}

static Factory::objectList	creation[NBR_OBJECT] =
  {
    {LifeUp, &Factory::m_createLifeUp},
    {SpeedUp, &Factory::m_createSpeedUp},
    {BombeUp, &Factory::m_createBombeUp},
    {Push, &Factory::m_createPush},
    {Case, &Factory::m_createBox},
    {Bombe, &Factory::m_createBombe}
  };

IObject	*Factory::m_createObject(ObjectType type, unsigned int pos_x, unsigned int pos_y)
{
  int	count = 0;

  while (count != NBR_OBJECT)
    {
      if (type == creation[count].type)
	return ((this->*(creation[count].ptr))(pos_x, pos_y));
      ++count;
    }
  return NULL;
}

IObject	*Factory::m_createSpeedUp(unsigned int pos_x, unsigned int pos_y)
{
  return (new BSpeedUp(pos_x, pos_y));
}

IObject	*Factory::m_createLifeUp(unsigned int pos_x, unsigned int pos_y)
{
  return (new BLifeUp(pos_x, pos_y));
}

IObject	*Factory::m_createBombeUp(unsigned int pos_x, unsigned int pos_y)
{
  return (new BBombeUp(pos_x, pos_y));
}

IObject	*Factory::m_createPush(unsigned int pos_x, unsigned int pos_y)
{
  return (new BPush(pos_x, pos_y));
}

IObject	*Factory::m_createBox(unsigned int pos_x, unsigned int pos_y)
{
  return (new Box(pos_x, pos_y));
}

IObject	*Factory::m_createBombe(unsigned int pos_x, unsigned int pos_y)
{
  return (new Bomb(pos_x, pos_y));
}
