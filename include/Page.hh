//
// Page.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Wed May 28 14:21:28 2014 Guillaume
// Last update Fri May 30 14:38:25 2014 Guillaume
//

#ifndef			PAGE_HH_
# define		PAGE_HH_

# include		<string>

class			Page
{
private:
  std::string		_name;
  Page*			_pagePrev;
  Page*			_pageNext;

public:
  Page();
  virtual ~Page();
};

#endif
