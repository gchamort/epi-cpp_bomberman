//
// Serial.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Tue May 20 10:54:45 2014 Julien ANDRE
// Last update Sun Jun 15 18:37:53 2014 Brice Leclercq
//

#ifndef		__SERIAL__HH__
# define	__SERIAL__HH__

# include	<iostream>
# include	<iomanip>
# include	<fstream>
# include	<sstream>

# include	"Map.hh"

# define	DEF_SAVE_FILE	"saves/game.save"

class			Serial
{
private:
  std::streambuf	*_backup;
  std::ofstream		_file;

public:
			Serial(const char *);
			~Serial();

  void			m_serializeGame(Map &);

  void			m_serialPlayers(Map &);
  void			m_serialObjects(Map &);
  void			m_createHeader(Map &);
  void			m_serialMap(Map &);
  unsigned int		m_getSaveSize(Map &);
};

#endif
