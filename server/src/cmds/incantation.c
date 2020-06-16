/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** command: incantation
*/

#include "server.h"

const int up_cond[7][7] = { {1, 0, 0, 0, 0, 0, 1 }, { 1, 1, 1, 0, 0, 0, 2 },
		{ 2, 0, 1, 0, 2, 0, 2 }, { 1, 1, 2, 0, 1, 0, 4 },
		{ 1, 2, 1, 3, 0, 0, 4 }, { 1, 2, 3, 0, 1, 0, 6 },
		{ 2, 2, 2, 2, 2, 1, 6 } };

/*!
** @brief upgrade player
**
** @param client client triggered
** @param cmd UNUSED
*/
void incantation(client_t *client, UNUSED char *cmd)
{
	size_t i;

	for (i = 0; i != 6; i++)
		if (client->game.inv[i + 1] != up_cond[client->game.lvl][i])
			break;
	if (i == 6 && server->map[client->game.x][client->game.y]
			->resources[7] == up_cond[client->game.lvl][6]) {
		client->game.lvl++;
		for (i = 0; i != 6; i++)
			client->game.inv[i + 1] -=
				up_cond[client->game.lvl - 1][i];
		dprintf(client->fd, "Elevation underway\n"
			"Current level: %lu\n", client->game.lvl);
	} else
		dprintf(client->fd, "ko\n");
}