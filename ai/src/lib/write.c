/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** write epoll
*/

#include "AI.h"

/*!
** @brief writing to server
**
** @param client just a storage
** @param index index of event
** @param str what to write
** @return int res of write
*/
int epoll_write(client_t *client, char *str)
{
	int res;

	res = dprintf(client->fd, "%s\n", str);
	return (res);
}