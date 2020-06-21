/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** set_object.c
*/

#include "server.h"

/*!
** @brief client set one of his object
**
** @param cli client triggered
** @param cmd need for object
*/
void set_object(client_t *cli, char *cmd)
{
    size_t i;

    for (i = 0; i != 7; i++)
        if (strncmp(g_items[i], cmd + 4, strlen(g_items[i])) == 0)
            break;
    if (i != 7) {
        if (cli->game.inv[i] > 0) {
            tile_add_resource(i, 1,
                server->map[cli->game.x][cli->game.y]);
            cli->game.inv[i]--;
            dprintf(cli->fd, "ok\n");
        } else
            dprintf(cli->fd, "ko\n");
    } else
        dprintf(cli->fd, "ko\n");
}