/*
** EPITECH PROJECT, 2018
** add_client_to_list.c
** File description:
** add_client_to_list.c
*/

#include "server.h"

/*!
** @brief add the first node of the chained list
**
** @param fd fd for communicating with client
** @return int sucess 0 error -1
*/
int	add_first_client_to_list(int fd)
{
	client_t	*elem = calloc(1, sizeof(client_t));

	if (elem == NULL)
		return (-1);
	elem->fd = fd;
	elem->game.lvl = 1;
	elem->next = NULL;
	elem->prev = NULL;
	server->client = elem;
	server->tail = elem;
	return (0);
}

/*!
** @brief add last element of the chained list
**
** @param fd fd for communicating with client
** @return int sucess 0 error -1
*/
int	add_last_client_to_list(int fd)
{
	client_t	*elem = calloc(1, sizeof(client_t));
	client_t	*tmp;

	if (elem == NULL)
		return (-1);
	elem->fd = fd;
	elem->game.lvl = 1;
	elem->next = NULL;
	server->tail = elem;
	for (tmp = server->client; tmp->next != NULL; tmp = tmp->next);
	tmp->next = elem;
	elem->prev = tmp;
	return (0);
}

/*!
** @brief add ellement in chained list
**
** @param fd fd for communicating with client
** @return int sucess 0 error -1
*/
int	add_client_to_list(int fd)
{
	if (server->client == NULL) {
		if (add_first_client_to_list(fd) == -1)
			return (-1);
	}
	else {
		if (add_last_client_to_list(fd) == -1)
			return (-1);
	}
	return (0);
}

void	display_clients(void)
{
	client_t	*tmp = server->client;

	printf("START########\n");
	for (; tmp != NULL; tmp = tmp->next)
		printf("%d\n", tmp->fd);
	printf("END########\n");
}