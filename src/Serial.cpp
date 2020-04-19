//
// Serial.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Tue May 20 10:59:03 2014 Julien ANDRE
// Last update Sun Jun 15 18:43:53 2014 Brice Leclercq
//

#include	<cstring>
#include	<unistd.h>
#include	"Serial.hh"

Serial::Serial(const char *filename)
{
  _file.open(filename);
  if (_file.fail() == true)
    std::cout << "Erreur lors de l'ouverture du fichier de sauvegarde" << std::endl;
}

Serial::~Serial()
{
  
}

void	Serial::m_serializeGame(Map &map)
{
  std::streambuf	*filestrm;

  _backup = std::cout.rdbuf();
  filestrm = _file.rdbuf();
  std::cout.rdbuf(filestrm);
  m_createHeader(map);
  std::cout << "//";
  m_serialMap(map);
  std::cout << "//";
  m_serialPlayers(map);
  std::cout << "//";
  m_serialObjects(map);
  std::cout.rdbuf(_backup);
  _file.close();
}

void	Serial::m_serialPlayers(Map &map)
{
  std::cout << std::setbase(16);
  for (std::list<Player *>::iterator iterPlayers = map.getPlayers().begin(); iterPlayers != map.getPlayers().end(); ++iterPlayers)
    {
      std::cout << "05"
		<< std::setfill('0') << std::setw(1)
		<< (*iterPlayers)->getNbrLife()
		<< std::setfill('0') << std::setw(1)
		<< (*iterPlayers)->getNbrBombe()
		<< std::setfill('0') << std::setw(1)
		<< (*iterPlayers)->getSpeed()
		<< std::setfill('0') << std::setw(1)
		<< (*iterPlayers)->getPush()
		<< std::setfill('0') << std::setw(8)
		<< (*iterPlayers)->getId()
		<< std::setfill('0') << std::setw(4)
		<< (*iterPlayers)->getPosX()
		<< std::setfill('0') << std::setw(4)
		<< (*iterPlayers)->getPosY()
		<< std::setfill('0') << std::setw(8)
		<< (*iterPlayers)->getScore();
    }
}

void	Serial::m_serialObjects(Map &map)
{
  for (std::list<IObject *>::iterator iterObjects = (map.getObjects()).begin(); iterObjects != map.getObjects().end(); iterObjects++)
    {
      switch((*iterObjects)->getType())
  	{
  	case 'B':
	  std::cout << "07" 
		    << std::setfill('0') << std::setw(2) 
		    << "10" /*time to explode a get ou implementer*/
		    << std::setfill('0') << std::setw(4)
		    << (*iterObjects)->getPosX()
		    << std::setfill('0') << std::setw(4)
		    << (*iterObjects)->getPosY();
  	  break;
  	case 'X':
	  std::cout << "06"
		    << std::setfill('0') << std::setw(4)
		    << (*iterObjects)->getPosX()
		    << std::setfill('0') << std::setw(4)
		    << (*iterObjects)->getPosY();
  	  break;
  	case 'S':
	  std::cout << "08"
		    << "1" // CODE BONUS A DEFINIR
		    << std::setfill('0') << std::setw(4)
		    << (*iterObjects)->getPosX()
		    << std::setfill('0') << std::setw(4)
		    << (*iterObjects)->getPosY();
  	  break;
  	default:
	  (void)map;
	  // throw exception undefined symbol
  	}
    }
}

void	Serial::m_createHeader(Map &map)
{
  std::cout << std::setbase(16)
	    << std::setfill('0') << std::setw(4)
	    << map.getLength()
	    << std::setfill('0') << std::setw(4)
	    << map.getWidth()
	    << std::setfill('0') << std::setw(4)
	    << map.getPlayers().size()
	    << std::setfill('0') << std::setw(4)
	    << m_getSaveSize(map);
}

void	Serial::m_serialMap(Map &map)
{   
  std::cout << map.getMap();
}

unsigned int	Serial::m_getSaveSize(Map &map)
{
  unsigned int	res = 0;

  for (std::list<IObject *>::iterator iterObjects = (map.getObjects()).begin(); iterObjects != map.getObjects().end(); iterObjects++)
    {
      switch((*iterObjects)->getType())
  	{
  	case 'B':
	  res += 12;
  	  break;
  	case 'X':
	  res += 10;
  	  break;
  	case 'S':
	  res += 11;
  	  break;
  	default:
	  // THROW EXCEPTION "undefined symbol"
  	  res += 0; // TEST pour check la presence d'objets sans type (il N'y en a PLUS). A reset a += 0
  	}
    }
  res += 2 * map.getMap().size();
  res += 30 * map.getPlayers().size();
  return res;
}
