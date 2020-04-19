//
// Deserial.cpp for lol in /home/morel_i/depots/tek2/c++/cpp_bomberman/src
// 
// Made by Pierre Morel
// Login   <morel_i@epitech.net>
// 
// Started on  Tue Jun 10 12:07:52 2014 Pierre Morel
// Last update Wed Jun 11 13:09:42 2014 Pierre Morel
//


# include "Deserial.hh"

Deserial::Deserial(char const *filename)
{
  _file.open(filename);
  if (_file.fail())
    {
      //EXCEPTION
      std::cerr << "Erreur lors de l'ouverture du fichier de sauvegarde specifie" << std::endl;
    }
  // _file.seekg(0, _file.end);
  // int length = _file.tellg();
  // file.seekg(0, _file.beg);
  while (std::getline(_file, _header, '\n'))
    {
      std::cout << _header << std::endl;
    }
  // std::getline(_file, _players, '/');
  // std::getline(_file, _objects, '/');
  // std::cout << "deserial1" << this->_header << this->_players << this->_objects << std::endl;
}

Deserial::~Deserial()
{
  _file.close();
}

void		Deserial::m_deSerializeGame(Map &map)
{
  //  std::cout << "deserial" << this->_header << this->_players << this->_objects << std::endl;
  (void)map;
}

// Deserial::~Deserial()
// {
  
// }

// void		Deserial::m_lexer()
// {
  
// }
