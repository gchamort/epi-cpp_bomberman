//
// Deserial.hh for bomberman in /home/morel_i/depots/tek2/c++/cpp_bomberman/src
// 
// Made by Pierre Morel
// Login   <morel_i@epitech.net>
// 
// Started on  Sun Jun  8 16:26:52 2014 Pierre Morel
// Last update Sun Jun 15 18:34:36 2014 Brice Leclercq
//

#ifndef		__DESERIAL_HH__
# define	__DESERIAL_HH__

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>

# include "Map.hh"

class			Deserial
{
private:
  std::ifstream		_file;
  std::string		_header;
  std::string		_map;
  std::string		_players;
  std::string		_objects;
public:
  Deserial(char const *);
  ~Deserial();
  
  void	m_deSerializeGame(Map &);
};

#endif		/* __DESERIAL_HH__ */
