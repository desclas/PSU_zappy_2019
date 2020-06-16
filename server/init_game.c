/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** init game struct
*/

#include "server.h"

/*!
** @brief init game stat
**
** @param game game struct
** @param food food
*/
void init_game(game_t *game, bool food)
{
	game->inv[FOOD] = food * 10;
	game->lvl = 1;
}