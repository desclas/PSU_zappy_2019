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
bool check_activity(client_t *client)
{
    if (FD_ISSET(client->fd,&client->rfds) ||FD_ISSET(client->fd,&client->wfds))
        return (true);
    return (false);
}