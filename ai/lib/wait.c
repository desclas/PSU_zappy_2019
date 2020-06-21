/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** epoll_wait_it
*/

#include "AI.h"

/*!
** @brief process_select func
**
** @param client just a storage
** @return int SUCCESS or FAILURE
*/
int process_select(client_t *client)
{
    int activity = 0;
    struct timeval tv = {0, 100};

    activity = select(client->fd, &client->rfds, &client->wfds, NULL, &tv);
    if (activity < 0 && (errno != EINTR)) {
        perror("select() fail");
        return (FAILURE);
    }
    return (SUCCESS);
}