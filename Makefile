##
## Makefile for bomberman in /home/andre_j/Project/C++/Bomberman/cpp_bomberman
## 
## Made by Julien ANDRE
## Login   <andre_j@epitech.net>
## 
## Started on  Wed May 14 10:29:41 2014 Julien ANDRE
## Last update Sun Jun 15 23:36:58 2014 Julien ANDRE
##

##	tmp unused :
##			$(SRC_PATH)Menu.cpp			
##			$(SRC_PATH)ModelManager.cpp		\

NAME		=	bomberman

SRC_PATH	=	src/

INCLUDE_PATH	=	include/
T_PATH		=	Thread/
C_PATH		=	Core/
L_PATH		=	lua/

SRC		=	$(SRC_PATH)ABonus.cpp			\
			$(SRC_PATH)BBombeUp.cpp			\
			$(SRC_PATH)BLifeUp.cpp			\
			$(SRC_PATH)Bomb.cpp			\
			$(SRC_PATH)Box.cpp			\
			$(SRC_PATH)BPush.cpp			\
			$(SRC_PATH)BSpeedUp.cpp			\
			$(SRC_PATH)$(C_PATH)ACore.cpp		\
			$(SRC_PATH)$(C_PATH)Core.cpp		\
			$(SRC_PATH)$(C_PATH)GCore.cpp		\
			$(SRC_PATH)Deserial.cpp			\
			$(SRC_PATH)Factory.cpp			\
			$(SRC_PATH)Lexer.cpp			\
			$(SRC_PATH)main.cpp			\
			$(SRC_PATH)Map.cpp			\
			$(SRC_PATH)MyError.cpp			\
			$(SRC_PATH)Page.cpp			\
			$(SRC_PATH)Player.cpp			\
			$(SRC_PATH)Serial.cpp			\
			$(SRC_PATH)Ai.cpp			\
			$(SRC_PATH)$(T_PATH)ACond.cpp		\
			$(SRC_PATH)$(T_PATH)AMutex.cpp		\
			$(SRC_PATH)$(T_PATH)AThread.cpp		\
			$(SRC_PATH)$(T_PATH)Cond.cpp		\
			$(SRC_PATH)$(T_PATH)Mutex.cpp		\
			$(SRC_PATH)$(T_PATH)Task.cpp		\
			$(SRC_PATH)$(T_PATH)Thread.cpp		\
			$(SRC_PATH)$(T_PATH)Threadpool.cpp	\

CXXFLAGS	=	-W -Wall -Werror -Wextra -I$(INCLUDE_PATH)

OBJS		=	$(SRC:.cpp=.o)

LIB		=	-llua -L$(INCLUDE_PATH)$(L_PATH)

CC		=	g++

RM		=	rm -f

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			$(CC) -o $@ $^ -pthread $(LIB)

clean		:
			$(RM) $(OBJS)

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

debug		:	CXXFLAGS += -g
debug		:	re

rec		:	re
			$(RM) $(OBJS)
