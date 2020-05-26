##
## EPITECH PROJECT, 2019
## PSU_zappy_2019
## File description:
## Makefile
##

SRC	=	

## pour utiliser le mode debug il suffit d'ecrire dans le terminal:
## make re DEBUG=yes

DEBUG	=

ifeq ($(DEBUG), yes)
	CFLAGS = -W -Wall -Werror -Wextra -Iincludes -g3 -ofast
else
	CFLAGS = -W -Wall -Werror -Wextra -Iincludes
endif

OBJ	=	($SRC:.c=.o)

NAME	=	zappy_server

all: $(NAME)

$(NAME): $(OBJ)
	gcc $@ $^
	ln -s ./src/server/$(NAME) ../../$(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f ../../$(NAME)

re: fclean all

.PHONY: clean fclean all re zappy_server serveur ai