/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** commande: inventory
*/

#include "server.h"

/*!
** @brief display content of player inventory
**
** @param cli client conserned
** @param cmd UNUSED
*/
void inventory(client_t *cli, UNUSED char *cmd)
{
	char *inv = NULL;

	asprintf(&inv,"[%s %d, %s %d, %s %d, %s %d, %s %d, %s %d, %s %d]"
		, g_items[0], cli->game.inv[0], g_items[1], cli->game.inv[1],
		g_items[2], cli->game.inv[2], g_items[3], cli->game.inv[3],
		g_items[4], cli->game.inv[4], g_items[5], cli->game.inv[5],
		g_items[6], cli->game.inv[6]);
	dprintf(cli->fd, "%s\n", inv);
	dprintf(cli->fd, "ok\n");
	free(inv);
}