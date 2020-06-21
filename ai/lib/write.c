/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** write epoll
*/

#include "AI.h"

/*!
** @brief writing to server
**
** @param client just a storage
** @param str what to write
** @return int res of write
*/
int write_on_client(client_t *client, char *str)
{
    int res;

    res = dprintf(client->fd, "%s\n", str);
    return (res);
}