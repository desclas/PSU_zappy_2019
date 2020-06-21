/*
** EPITECH PROJECT, 2019
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
    FD_CLR(client->fd, &client->rfds);
    FD_CLR(client->fd, &client->wfds);
    free(client);
    return ;
}