//
// intro.cpp for bomberman in /home/lecler_k/GL/src/intro
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Fri Jun 13 14:19:45 2014 Brice Leclercq
// Last update Fri Jun 13 18:26:14 2014 Brice Leclercq
//

Intro::Intro()
{

}

Intro::~Intro()
{

}

void		Intro::init()
{
  _model.init();
  _model.init(x, y, z);//faire des test pour les valeurs de x y z (x et y devraient être négatif aux alentours de -250 et -500) z positif
}

int		Intro::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return (0);
  _model.update();
}

void		Intro::draw()
{
  _model.draw();
  _ 
}
