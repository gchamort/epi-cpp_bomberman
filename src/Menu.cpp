//
// Menu.cpp for bomberman in /home/lecler_k/rendu/cpp_bomberman/src
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Thu May 15 14:27:52 2014 Brice Leclercq
// Last update Sun Jun 15 18:43:09 2014 Brice Leclercq
//

#include	"Menu.hh"

Menu::Menu()
{
}

Menu::~Menu()
{
}

void		Menu::m_intro() const
{
  if (mainMenu._introMenu == true)
    {
      mainMenu.introMenu = false;
      launchIntro();
    }
  else
    mainMenu.m_startMenu();
}

void		Menu::m_launchIntro() const
{
  mainMenu.m_menuInit(&mainmenu);
  mainMenu.m_startMenu(&mainmenu);
}

void		Menu::m_menuInit() const
{
  mainMenu = new Menu;
  mainMenu.type = NEW;
  mainMenu.options = NONE;
  mainMenu.introMenu = true;  
  mainMenu._window.start(800, 600, "Bomberman");
  if(!(mainMenu._background("../Textures/mainMenu.tga")))
    {
      std::cerr << "Cannot load the main menu background" << std::endl;
      return (false);
    }
}

void		Menu::m_startMenu(Menu &mainMenu) const
{
  if (_input.getKey(SDKL_DOWN) == true)
    {
      switch()
	{
	case NEW:
	  {
	    mainMenu.m_newGame(Menu &mainMenu);
	    break;
	  }
	case LOAD:
	  {
	    mainMenu.m_loadGame(Menu &mainMenu);
	    break;
	  }
	case MAP:
	  {
	    mainMenu.m_mapEditor(Menu &mainMenu);
	    break;
	  }
	case Options:
	  {
	    mainMenu.m_options(Menu &mainMenu);
	    break;
	  }
	case Help:
	  {
	    mainMenu.m_help(Menu &mainMenu);
	    break;
	  }
	case Exit:
	  {
	    mainMenu.m_end(Menu &mainMenu);
	    break;
	  }
	}
    }
}
void		Menu::m_newGame(Menu &mainMenu)
{
  mainMenu.m_iaChoice(Menu);
}

void		Menu::m_iaChoice(Menu &mainMenu)
{
  mainMenu.m_iaNb(Menu);
  if (_input.getKey(SDKL_LEFT) == true)
    {
      if (nbIa <= 1)
	nbIa = 2;
      nbIa--;
      mainMenu.updateDraw();
    }
  if (_input.getKey(SDLK_RIGHT) == true)
    {
      if (nbIa > 10)
	nbIa = 10;
      nbIa++;
      mainMenu.updateDraw();
    }
  if (_input.getKey(SDKL_KP_ENTER) == true)
    mainMenu.m_iaNb(mainMenu);
  else
    mainMenu.m_wait();
}

void		Menu::m_updateDraw()
{

}

void		Menu::m_wait()
{

}

void		Menu::m_iaNb(Menu &mainMenu)
{
  mainMenu.m_iaDiff(mainMenu)
}

void		Menu::m_iaDiff(Menu &mainMenu)
{
  mainMenu.m_startMenuGame(mainMenu)
}

void		Menu::mapChoice(Menu &mainMenu)
{
}

void		Menu::m_pauseMenu(Menu &mainMenu)
{
  mainMenu._pauseGame = true;
  if (_input.getKey(SDKL_DOWN) == true)
    {
      switch()
	{
	case PRESUME:
	  {
	    mainMenu.m_pResume(Menu &mainMenu);
	    break;
	  }
	case PSAVE:
	  {
	    mainMenu.m_pSave(Menu &mainMenu);
	    break;
	  }
	case POPTIONS:
	  {
	    mainMenu.m_pOptions(Menu &mainMenu);
	    break;
	  }
	case PHELP:
	  {
	    mainMenu.m_pHelp(Menu &mainMenu);
	    break;
	  }
	case PEXIT:
	  {
	    mainMenu.m_end(Menu &mainMenu);
	    break;
	  }
	}
    }
}


void		Menu::m_popUp(Menu &mainMenu)
{
}

void		Menu::m_popUpSave(Menu &mainMenu)
{
}

void		Menu::m_popUpReload()
{
}

void		Menu::m_pResume(Menu &mainMenu)
{
  mainMenu._pauseGame = false;
}
void		Menu::m_pSave(Menu &mainMenu)
{
  mainMenu._pauseGame = false;
}
void		Menu::m_pOptions(Menu &mainMenu)
{
  mainMenu._pauseGame = false;
}
void		Menu::m_pHelp(Menu &mainMenu)
{
  mainMenu._pauseGame = false;
}
void		Menu:: m_end(Menu &mainMenu)
{
  mainMenu._pauseGame = false;
}

void		Menu::m_startGameMenu(Menu &mainMenu)
{
}

void		Menu::m_loadGame(Menu &mainMenu) const
{
  mainMenu._map = ONE;
  if (_input.getKey(SDKL_DOWN) == true)
    mainMenu._map = TWO;
  if (_input.getKey(SDLK_UP) == true)
    mainMenu._map = ONE;
  if (_input.getKey(SDKL_KP_ENTER) == true)
    mainMenu.m_loadGame(mainMenu._map);
  else
    mainMenu.m_wait();
}

void		Menu::m_mapEditor(Menu &mainMenu) const
{

}

void		Menu::m_help(Menu &mainMenu) const
{
  
}

void		Menu::m_options(Menu &mainMenu) const
{
  
}

void		Menu::m_end(Menu &mainMenu) const
{
}

void		Menu::drawMenu(Menu &mainMenu) const
{
}
