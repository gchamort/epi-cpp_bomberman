//
// Lexer.hh for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman/include
// 
// Made by Julien ANDRE
// Login   <andre_j@epitech.net>
// 
// Started on  Wed May 14 18:38:43 2014 Julien ANDRE
// Last update Sun Jun 15 18:35:55 2014 Brice Leclercq
//

#ifndef		__LEXER__HH__
# define	__LEXER__HH__

# include	<string>
# include	<list>

# define	CONF_FILE	"Bomber.conf"

# define	TAB		"/t"
# define	DSPACE		"  "
# define	TOKEN		" "
# define	SPACE		' '

class		Lexer
{
private:
  int				_fd;
  std::list<std::string>	_tokenList;

public:
  Lexer();
  ~Lexer();
  
  int					getFd() const;
  void					setFd(int);
  
  std::list<std::string>		getTokenList() const;
  std::string				m_fetchToken();
  bool					m_isListEmpty(void) const;

  void		m_epureString(std::string &) const;
  void		m_tokenize(std::string const &);
};

#endif		/* __LEXER__HH__ */
