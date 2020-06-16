/*
** EPITECH PROJECT, 2018
** false_cmd.c
** File description:
** false_cmd.c
*/

#include "server.h"

/*!
** @brief UNKNOWN command
**
** @param client client triggered
** @param cmd UNUSED
*/
void	false_cmd(client_t *client, UNUSED char *cmd)
{
	dprintf(client->fd, "ko\n");
}