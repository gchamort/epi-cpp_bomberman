//
// TextManager.hh for bomberman in /home/lecler_k/rendu/cpp_bomberman/include
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Fri Jun 13 10:51:30 2014 Brice Leclercq
// Last update Sun Jun 15 18:38:20 2014 Brice Leclercq
//

#ifndef		__TEXTMANAGER__HH__
#define		__TEXTMANAGER__HH__

class	TextManager
{
private:
  std::string	_content;
  TextManager();
  ~TextManager();

  void	LoadImg(std::string const &);
  void	PopUp();
  void	GdlPutchar();
  void	GdlPutstr();
};

#endif		/* __TEXTMANAGER__HH__ */
