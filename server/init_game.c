/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** init_game.c
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