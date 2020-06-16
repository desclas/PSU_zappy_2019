/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** commande: take object
*/

#include "server.h"

/*!
** @brief client take an object from his place
**
** @param cli client triggered
** @param cmd need for object
*/
void take_object(client_t *cli, char *cmd)
{
	size_t i;

	for (i = 0; i != 7; i++)
		if (strncmp(g_items[i], cmd + 5, strlen(g_items[i])) == 0)
			break;
	if (i != 7) {
		if (server->map[cli->game.x]
			[cli->game.y]->resources[i].number > 0) {
			tile_del_resource(i, 1,
				server->map[cli->game.x][cli->game.y]);
			cli->game.inv[i]++;
			dprintf(cli->fd, "ok\n");
		} else
			dprintf(cli->fd, "ko\n");
	} else
		dprintf(cli->fd, "ko\n");
}