/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** broadcast.c
*/

#include "server.h"

void broadcast(client_t *client, char *cmd)
{
    char **args = split(cmd, " ");
    client_t *tmp = server->client;
    int tile = 0;

    printf("IN BROADCAST\n");///TMP
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp != client) {
            tile = find_tile(client, tmp);
            printf("TILE = %d\n", tile);///TMP
            dprintf(tmp->fd, "message %d, %s\n", tile, args[1]);
            ///print tile nb & msg to all the clients
            ///but not the one executing the command
        }
    }
    (void)tile;
    (void)args;
    dprintf(client->fd, "ok\n");
}