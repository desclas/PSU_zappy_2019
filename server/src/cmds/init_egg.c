/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** init egg
*/

#include "server.h"

/*!
** @brief init hatching egg
**
** @param client egg triggered
** @param cmd UNUSED
*/
void init_egg(client_t *client, UNUSED char *cmd)
{
	if (client->log == true)
		client->eat = (((float)(126)) / server->input->freq) +
			(clock() / CLOCKS_PER_SEC);
	else
		client->eat = -1;
}