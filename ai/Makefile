##
## EPITECH PROJECT, 2018
## zappy
## File description:
## Makefile
##

SRC	=	lib/connection.c	\
		lib/check_acess.c	\
		lib/destruct.c		\
		lib/read.c		\
		lib/write.c		\
		lib/wait.c		\
		lib/epoll_st.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Werror -Wextra -Iinclude -fPIC

NAME	=	libzappy.so

all: $(NAME)
	cp ./zappy_ai ../

$(NAME): $(OBJ)
	gcc -shared -o ./lib/$@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ./lib/$(NAME)
	rm -f ../zappy_ai

re: fclean all
