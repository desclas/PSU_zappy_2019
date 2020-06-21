/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** incantation.c
*/

#include "server.h"

const int up_cond[7][7] = { {1, 0, 0, 0, 0, 0, 1 }, { 1, 1, 1, 0, 0, 0, 2 },
        { 2, 0, 1, 0, 2, 0, 2 }, { 1, 1, 2, 0, 1, 0, 4 },
        { 1, 2, 1, 3, 0, 0, 4 }, { 1, 2, 3, 0, 1, 0, 6 },
        { 2, 2, 2, 2, 2, 1, 6 } };

/*!
** @brief upgrade player
**
** @param client client triggered
** @param cmd UNUSED
*/
void incantation(client_t *client, UNUSED char *cmd)
{
    int i = 0;

    for (client_t *tmp = server->client; tmp != NULL; tmp = tmp->next)
        if (tmp->game.x == client->game.x && tmp->game.y == client->game.y &&
                tmp->game.lvl == client->game.lvl)
            i++;
    if (i < up_cond[client->game.lvl - 1][6])
        return ((void)dprintf(client->fd, "ko\n"));
    for (i = 0; i < 6; i++)
        if (server->map[client->game.y][client->game.x]->resources[i + 1].number
                != up_cond[client->game.lvl][i])
            break;
    if (i != 6)
        return ((void)dprintf(client->fd, "ko\n"));
    i = client->game.lvl;
    for (client_t *tmp = server->client; tmp != NULL; tmp = tmp->next)
        if ((tmp->game.x == client->game.x && tmp->game.y ==
                client->game.y && tmp->game.lvl == ((size_t)i)))
            dprintf(tmp->fd, "Elevation underway\nCurrent level: %lu\n",
                tmp->game.lvl++);
}