//
// Lexer.cpp for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/src
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Wed May 14 18:52:35 2014 Julien ANDRE
// Last update Thu May 15 16:24:50 2014 Pierre Morel
//

#include	"Lexer.hh"

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
}

int	Lexer::getFd() const
{
  return _fd;
}

void	Lexer::setFd(int fd)
{
  _fd = fd;
}

void		Lexer::m_epureString(std::string &str) const
{
  size_t	pos;

  while ((pos = str.find(TAB)) != std::string::npos)
    str.replace(pos, 1, TOKEN);
  while ((pos = str.find(DSPACE)) != std::string::npos)
    str.erase(pos, 1);
  if (str[0] == SPACE)
    str.erase(0, 1);
  if (str[str.size() - 1] == SPACE)
    str.erase(str.size() - 1, 1);
}

void		Lexer::m_tokenize(std::string const &str)
{
  size_t	pos;
  std::string	tmp;
  size_t	last;

  pos = 0;
  last = 0;
  while ((pos = str.find(TOKEN, pos)) != std::string::npos)
    {
      tmp = str.substr(last, pos - 1);
      this->_tokenList.push_back(tmp);
      last = pos;
    }  
}

std::string		Lexer::m_fetchToken(void)
{
  std::string		tmp;
  if (!(this->_tokenList.empty()))
    {
      tmp = this->_tokenList.front();
      this->_tokenList.pop_front();
      return (tmp);
    }
  else
    return (NULL);
}

bool			Lexer::m_isListEmpty(void) const
{
  return (this->_tokenList.empty());
}

std::list<std::string>	Lexer::getTokenList(void) const
{
  return (this->_tokenList);
}
