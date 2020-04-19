//
// Core.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Wed May 28 15:11:58 2014 Guillaume
// Last update Fri May 30 16:41:32 2014 Guillaume
//

#ifndef			CORE_HH_
# define		CORE_HH_

# include		"ACore.hh"
# include		"Thread/Threadpool.hh"
# include		<string>
# include		<iostream>

class			GCore;

class			Core : public ACore
{
private:
  bool			_sound;
  GCore*		_gCore;
  Threadpool*		_threadpool;

public:
  Core();
  virtual ~Core();

  void			intro();
  void			launchMenu();
  void			startGame();
  void			end();
};

#endif
