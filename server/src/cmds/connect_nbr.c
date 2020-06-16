/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** command: connect_nbr
*/

#include "server.h"

/*!
** @brief count connection remaining
**
** @param client client list
** @param cmd UNUSED
*/
void connect_nbr(client_t *client, UNUSED char *cmd)
{
	int count = 0;
	char *team = client->game.team;
	int eggnl = 0;
	client_t *tmp = client;

	while (client->prev != NULL)
		client = client->prev;
	while (client != NULL) {
		if (client->log && client->status != EGG &&
				strcmp(client->game.team, team) == 0)
			count++;
		else if (!client->log && client->status == EGG &&
				strcmp(client->game.team, team) == 0)
			eggnl++;
		client = client->next;
	}
	if (server->input->client_nb - count == 0)
		dprintf(tmp->fd, "%d\n", eggnl);
	else
		dprintf(tmp->fd, "%d\n", server->input->client_nb - count);
}