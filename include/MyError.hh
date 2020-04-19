//
// MyError.hh for bomber in /home/chanut_g/rendu/cpp_bomberman/include
// 
// Made by Guillaume
// Login   <chanut_g@epitech.net>
// 
// Started on  Tue May 20 14:23:54 2014 Guillaume
// Last update Sun Jun 15 18:37:07 2014 Brice Leclercq
//

#ifndef			__MYERROR__HH__
# define		__MYERROR__HH__

# include		<iostream>
# include		<ostream>
# include		<string>
# include		<stdexcept>

class			MyError : public std::runtime_error
{
private:
  std::string		_err;

public:
  MyError(const std::string &);
  virtual ~MyError() throw();
  virtual const char	*what() const throw();
};

#endif			/* __MYERROR__HH__ */
