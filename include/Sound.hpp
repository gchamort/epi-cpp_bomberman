//
// Sounds.hpp for bomberman in /home/lecler_k/rendu/cpp_bomberman/include
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Fri May 30 14:34:37 2014 Brice Leclercq
// Last update Fri May 30 14:59:44 2014 Brice Leclercq
//

#ifndef		__SOUNDS__HH__
# define	__SOUNDS__HH__

class	Sounds
{
private:
  std::string	_sLifeUp;
  std::string	_sSpeedUp;
  std::string	_sPush;
public:
  Sounds();
  ~Sounds();
  void playSounds(const std::string);
};

#endif		/* __SOUNDS__HH__ */
