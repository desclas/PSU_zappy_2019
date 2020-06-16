/*
** EPITECH PROJECT, 2018
** place_player_on_map.c
** File description:
** place_player_on_map.c
*/

#include "server.h"

int	place_player_on_map(void *client)
{
	int	new_x = rand() % (server->input->width - 1);
	int	new_y = rand() % (server->input->height - 1);

	((client_t *)client)->game.x = new_x;
	((client_t *)client)->game.y = new_y;
	if (add_player_to_map(((client_t *)client)->fd,
		server->map[new_y][new_x]) == -1)
		return (-1);
	return (0);
}