//
// Menu.hh for bomberman in /home/lecler_k/rendu/cpp_bomberman/include
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Thu May 15 14:28:01 2014 Brice Leclercq
// Last update Sun Jun 15 18:36:34 2014 Brice Leclercq
//

#ifndef		__MENU__HH__
# define	__MENU__HH__

# define	IS_INTRO	0

typedef enum e_options 
{
  NEW = 1,
  LOAD = 2,
  MAP = 3,
  HELP = 4,
  OPTIONS = 5,
  EXIT = 6
}             e_menuOptions; // enum pour le choix de l'option

typedef enum e_pOptions 
{
  RESUME = 1,
  SAVE = 2,
  OPTIONS = 3,
  HELP = 4,
  EXIT = 5
}             e_menuPOptions; // enum pour le choix de l'option dans le menu pause pendant une partie

typedef enum e_map
{
  NONE = 0,
  ONE = 1,
  TWO = 2,
  THREE = 3,
  FOUR = 4,
  FIVE = 5,
  RANDOM = 6
}             e_menuMap; // enum pour le choix de la map

class		Menu : public gdl::Game
{
private:
  int		_width;
  int		_height;
  int		_type;
  int		_options;
  int		_map;
  bool		_introMenu;
  bool		_startGame;
  bool		_pauseGame;
  Music		_music;
  SdlContext	_window;
  gdl::Texture	_texture;
  gdl::Texture	_background;
public:
  void	m_intro(Menu &) const;
  void	m_launchIntro(Menu &) const;
  void	m_menuInit(Menu &) const;
  void	m_startMenu(Menu &) const;
  void	m_newGame(Menu &) const;
  void	m_iaChoice(Menu &);
  void	m_iaNb(Menu &);
  void	m_wait(Menu &);
  void	m_mapChoice(Menu &);
  void	m_pauseMenu(Menu &);
  void	m_startGameMenu(Menu &);
  void	m_loadGame(Menu &) const;
  void	m_mapEditor(Menu &) const;
  void  m_help(Menu &) const;
  void	m_options(Menu &) const;
  void	m_end(Menu &) const;
  void  m_drawMenu(Menu &) const;
  void	m_updateDraw(Menu &);
  void	m_popUp(Menu &) const;
  void	m_popUpReload(Menu &) const;
  void	m_pResume(Menu &) const;
  void	m_pSave(Menu &) const;
  void  m_pHelp(Menu &) const;
  void	m_pOptions(Menu &) const;
};

#endif		/* __MENU__HH__ */
