
CC	=	g++

SRC	=	beatTheWave.cpp \
		Main.cpp \
		Character.cpp \
		Game.cpp \
		Map.cpp \
		UnitWall.cpp \
		UnitVoid.cpp \
		Unit.cpp \
		keybind.cpp \
		Menu.cpp	\
		Gravity.cpp \
		GameInterface.cpp \
		Wave.cpp \
		UnitWave.cpp \
		MapFire.cpp \

NAME	= ../release/Beat\ The\ Wave\ Linux\ Edition

OBJ	=	$(SRC:.cpp=.o)

NCURSE	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

CPPFLAGS	=	-c -W -Wall -Wextra -ansi -pedantic

$(NAME): $(OBJ)
	 $(CC) $(FLAGS) -o $(NAME) $(OBJ) $(NCURSE)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
