/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** movement_cmds.c
*/

#include "server.h"

void turn_left(client_t *client, char *cmd)
{
    if (strcasecmp(cmd, "Left") == 0) {
        client->direction = (client->direction - 1 + 4) % 4;
        dprintf(client->fd, "ok\n");
    }
}

void turn_right(client_t *client, char *cmd)
{
    if (strcasecmp(cmd, "Right") == 0) {
        client->direction = (client->direction + 1 + 4) % 4;
        dprintf(client->fd, "ok\n");
    }
}

void go_forward_y(client_t *client)
{
    int orientation = (client->direction == UP) ? (1) : (-1);

    client->game.y = (client->game.y + orientation + server->input->height)
        % server->input->height;
}

void go_forward_x(client_t *client)
{
    int orientation = (client->direction == RIGHT) ? (1) : (-1);

    client->game.x = (client->game.x + orientation + server->input->width)
        % server->input->width;
}

void go_forward(client_t *client, char *cmd)
{
    (void)cmd;
    if (client->direction % 2 == 0)
        go_forward_y(client);
    else
        go_forward_x(client);
    dprintf(client->fd, "ok\n");
}