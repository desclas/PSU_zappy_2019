/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
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
client_t *add_first_client_to_list(int fd)
{
    client_t *elem = calloc(1, sizeof(client_t));

    if (elem == NULL)
        return (NULL);
    elem->fd = fd;
    elem->game.lvl = 1;
    elem->next = NULL;
    elem->prev = NULL;
    server->client = elem;
    server->tail = elem;
    return (elem);
}

/*!
** @brief add last element of the chained list
**
** @param fd fd for communicating with client
** @return int sucess 0 error -1
*/
client_t *add_last_client_to_list(int fd)
{
    client_t *elem = calloc(1, sizeof(client_t));
    client_t *tmp = NULL;

    if (elem == NULL)
        return (NULL);
    elem->fd = fd;
    elem->game.lvl = 1;
    elem->next = NULL;
    server->tail = elem;
    for (tmp = server->client; tmp->next != NULL; tmp = tmp->next);
    tmp->next = elem;
    elem->prev = tmp;
    return (elem);
}

/*!
** @brief add ellement in chained list
**
** @param fd fd for communicating with client
** @return int sucess 0 error -1
*/
client_t *add_client_to_list(int fd)
{
    client_t *elem = NULL;

    if (server->client == NULL) {
        elem = add_first_client_to_list(fd);
        if (!elem)
            return (NULL);
    } else {
        elem = add_last_client_to_list(fd);
        if (!elem)
            return (NULL);
    }
    return (elem);
}

void display_clients(void)
{
    client_t *tmp = server->client;

    printf("START########\n");
    for (; tmp != NULL; tmp = tmp->next)
        printf("%d\n", tmp->fd);
    printf("END########\n");
}