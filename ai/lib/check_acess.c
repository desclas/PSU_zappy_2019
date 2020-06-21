/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** testing access
*/

#include "AI.h"

/*!
** @brief check sets read or write
**
** @param client
** @param set_to_check fdset to check
** @return true
** @return false
*/
bool check_activity(client_t *client, fd_set *set_to_check)
{
    if (FD_ISSET(client->fd, set_to_check))
        return (true);
    return (false);
}