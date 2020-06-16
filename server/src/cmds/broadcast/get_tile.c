/*
** EPITECH PROJECT, 2018
** get_tile.c
** File description:
** get_tile.c
*/

#include "server.h"

int	get_tile(client_t *receiver, int x, int y)
{
	if (receiver->direction % 2 == 0)
		return (get_tile_in_y(receiver, x, y));
	else
		return (get_tile_in_x(receiver, x, y));
	return (0);
}