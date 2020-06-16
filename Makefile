##
## EPITECH PROJECT, 2018
## zappy
## File description:
## Makefile
##

SERVER	=	server

AI	=	ai

all:
	$(MAKE) -C $(SERVER)
	$(MAKE) -C $(AI)

clean:
	$(MAKE) -C $(SERVER) clean
	$(MAKE) -C $(AI) clean

fclean:
	$(MAKE) -C $(SERVER) fclean
	$(MAKE) -C $(AI) fclean

re:
	$(MAKE) -C $(SERVER) re
	$(MAKE) -C $(AI) re