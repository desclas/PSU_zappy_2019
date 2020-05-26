##
## EPITECH PROJECT, 2019
## PSU_zappy_2019
## File description:
## Makefile
##

SERVER	=	server

AI	=	ai

all: zappy_server zappy_ai

zappy_server:
	$(MAKE) -c src/$(SERVER)

zappy_ai:
	$(MAKE) -c src/$(AI)

clean:
	$(MAKE) -c src/$(SERVER) clean
	$(MAKE) -c src/$(AI) clean

fclean:
	$(MAKE) -c src/$(SERVER) fclean
	$(MAKE) -c src/$(AI) fclean

re: fclean all

.PHONY: clean fclean all re zappy_ai zappy_server serveur ai