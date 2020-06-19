/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** look.c
*/

#include "server.h"

void get_content_of_tile(client_t *client, map_t *map)
{
    player_on_map_t *tmp = map->players;

    for (; tmp != NULL; tmp = tmp->next) {
        dprintf(client->fd, "player");
        if (tmp->next != NULL)
            dprintf(client->fd, " ");
    }
    for (int i = 6; i > -1; i--) {
        for (int x = 0; x < map->resources[i].number; x++) {
            dprintf(client->fd, "%s", map->resources[i].name);
            (x + 1 < map->resources[i].number)
                ? (dprintf(client->fd, " ")) : (void)tmp;
        }
        if (i + 1 > -1)
            dprintf(client->fd, " ");
    }
}

void look_in_y(client_t *client)
{
    int new_y;
    int new_x;
    int orientation = (client->direction == UP) ? (1) : (-1);
    int t;

    dprintf(client->fd, "[");
    for (int i = 1; i < (int)client->game.lvl + 1; i++) {
        t = i * 2 + 1;
        for (int y = 0; y < t; y++) {
            new_y = client->game.y + (i * orientation);
            new_y = (new_y + server->input->height)
                % server->input->height;
            new_x = client->game.x - i + y;
            new_x = (new_x + server->input->width)
                % server->input->width;
            get_content_of_tile(client, server->map[new_y][new_x]);
            (y + 1 < t) ? (dprintf(client->fd, ",")) : (void)t;
        }
    }
    dprintf(client->fd, "]\n");
}

void look_in_x(client_t *client)
{
    int new_y;
    int new_x;
    int orientation = (client->direction == RIGHT) ? (1) : (-1);
    int t;

    for (int i = 1; i < (int)client->game.lvl + 1; i++) {
        t = i * 2 + 1;
        for (int y = 0; y < t; y++) {
            new_y = client->game.y - i + y;
            new_y = (new_y + server->input->height)
                % server->input->height;
            new_x = client->game.x + (i * orientation);
            new_x = (new_x + server->input->width)
                % server->input->width;
            get_content_of_tile(
                client, server->map[new_y][new_x]);
        }
    }
}

void look(client_t *client, char *cmd)
{
    (void)cmd;
    if (client->direction % 2 == 0)
        look_in_y(client);
    else
        look_in_x(client);
    dprintf(client->fd, "ok\n");
}