/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** destruction of struct
*/

#include "AI.h"

/*!
** @brief closing all fd
**
** @param client just a storage
*/
void destruct(client_t *client)
{
	close(client->fd);
	close(client->epfd);
	free(client->event);
	free(client);
}