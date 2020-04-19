//
// TextManager.cpp for bomberman in /home/lecler_k/rendu/cpp_bomberman/src
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Fri Jun 13 10:50:57 2014 Brice Leclercq
// Last update Sun Jun 15 18:38:52 2014 Brice Leclercq
//

TextManager::TextManager()
{

}

TextManager::~TextManager()
{

}

void		TextManager::Show(std::string const & sentence)
{
  _img = Sdl::Load(sentence);
}

void		TextManager::GdlPutchar()
{
  
}

void		TextManager::GdlPutstr()
{

}

void		TextManager::PopUp()
{
  
}
