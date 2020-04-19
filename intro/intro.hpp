//
// intro.hpp for bomberman in /home/lecler_k/GL/src/intro
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Fri Jun 13 14:22:18 2014 Brice Leclercq
// Last update Fri Jun 13 14:54:56 2014 Brice Leclercq
//

#ifndef		__INTRO__HH__
# define	__INTRO__HH__

class	Intro
{
private:
  _model;
  _texture;
  _input;
public:
  Intro();
  ~Intro();

  void	init();
  int	update();
  void	draw();
}

#endif		/* __INTRO__HH__ */
