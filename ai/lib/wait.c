/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** epoll_wait_it
*/

#include "AI.h"

/*!
** @brief epoll_wait func
**
** @param client just a storage
** @return int result of epoll_wait
*/
int epoll_wait_it(client_t *client)
{
	return (epoll_wait(client->epfd, client->event, 2, 50));
}