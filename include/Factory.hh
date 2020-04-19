//
// Factory.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Mon May 12 18:12:09 2014 Julien ANDRE
// Last update Sun Jun 15 18:34:58 2014 Brice Leclercq
//

#ifndef		__FACTORY__HH__
# define	__FACTORY__HH__

class		IObject;

# define	NBR_OBJECT	6

typedef enum
  {
    LifeUp,
    SpeedUp,
    BombeUp,
    Push,
    Case,
    Bombe
  }	ObjectType;

class		Factory
{
public:
  IObject	*m_createLifeUp(unsigned int, unsigned int);
  IObject	*m_createSpeedUp(unsigned int, unsigned int);
  IObject	*m_createBombeUp(unsigned int, unsigned int);
  IObject	*m_createPush(unsigned int, unsigned int);
  IObject	*m_createBox(unsigned int, unsigned int);
  IObject	*m_createBombe(unsigned int, unsigned int);
public:
		Factory();
		~Factory();

  IObject	*m_createObject(ObjectType, unsigned int, unsigned int);

  struct		objectList
  {
    ObjectType	type;
    IObject *	(Factory::*ptr)(unsigned int, unsigned int);
  };
};

#endif		/* __FACTORY__HH__ */
