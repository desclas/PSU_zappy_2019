/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** delete_client_from_list.c
*/

#include "server.h"

static void eject_close_free(client_t *client)
{
    if (client != NULL) {
        if (client->fd != -1) {
            FD_CLR(client->fd, &server->readfds);
            close(client->fd);
        }
        free(client);
    }
}

/*!
** @brief delete the first element of chained list
**
*/
void delete_first_from_list(void)
{
    client_t *tmp;

    tmp = server->client->next;
    if (tmp != NULL)
        tmp->prev = NULL;
    if (server->tail == server->client)
        server->tail = tmp;
    eject_close_free(server->client);
    server->client = tmp;
}

/*!
** @brief delete the last element of chained list
**
*/
void delete_last_from_list(void)
{
    client_t *tmp;

    tmp = server->tail->prev;
    if (tmp != NULL)
        tmp->next = NULL;
    if (server->tail == server->client)
        server->client = tmp;
    eject_close_free(server->tail);
    server->tail = tmp;
}

/*!
** @brief delete an element of the chained list
**
** @param node node to remove
*/
void delete_from_list(client_t *node)
{
    client_t *tmp = server->client;

    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->next != NULL && tmp->next == node) {
            tmp->next = tmp->next->next;
            (tmp->next != NULL)
            ? (tmp->next->prev = tmp) : ((void)tmp);
            eject_close_free(node);
            break;
        }
}

/*!
** @brief delete element of the chained list
**
** @param node node to remove
** @return int sucess 0 error -1
*/
int delete_client_from_list(client_t *node)
{
    if (node == NULL)
        return (-1);
    if (node == server->client)
        delete_first_from_list();
    else if (node == server->tail)
        delete_last_from_list();
    else
        delete_from_list(node);
    return (0);
}