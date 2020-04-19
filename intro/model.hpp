//
// model.hpp for bomberman in /home/lecler_k/GL/src/intro
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Fri Jun 13 15:08:48 2014 Brice Leclercq
// Last update Fri Jun 13 16:48:51 2014 Brice Leclercq
//

#ifndef		__MODEL__HPP__
# define	__MODEL__HPP__

class	Model
{
private:
  _model;
  _pos;
  gdl::BasicShader _shader;
  gdl::SdlContext _context;
  public:

  Model();
  ~Model();
  
  bool	init();
}

#endif		/* __MODEL__HPP__ */
