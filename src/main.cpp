//
// main.cpp for bomberman in /home/lecler_k/rendu/cpp_bomberman/src
// 
// Made by Brice Leclercq
// Login   <lecler_k@epitech.net>
// 
// Started on  Sat May 10 17:56:29 2014 Brice Leclercq
// Last update Sun Jun 15 23:35:26 2014 Julien ANDRE
//

#include <unistd.h>

#include	<iostream>
#include	"Serial.hh"
#include	"BBonus.hh"
#include	"Core/Core.hh"
#include	"Ai.hh"


int main()
{
  Core		core;

  core.intro();
  core.launchMenu();
  usleep(500000);
  core.end();
  return 0;
}







