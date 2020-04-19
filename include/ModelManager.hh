//
// ModelManager.hh for bomberman in /home/lecler_k/rendu/cpp_bomberman/include
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Tue May 27 14:29:54 2014 Brice Leclercq
// Last update Fri May 30 14:37:23 2014 Guillaume
//

#ifndef		__MODELMANAGER__HH__
# define	__MODELMANAGER__HH__

class	ModelManager
{
private:
  bool _used;
  float	_x;
  float	_y;
  float	_z;
public:
  ModelManager();
  ~ModelManager();

  void	init();
  void	chooseSkin();x
};

#endif		/* __MODELMANAGER__HH__ */
