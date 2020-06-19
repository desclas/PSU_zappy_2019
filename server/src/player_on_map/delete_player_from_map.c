/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** delete_player_from_map.c
*/

#include "server.h"

static void delete_any_player_from_map(player_on_map_t *player, map_t *map)
{
    player_on_map_t *tmp = map->players;

    for (; tmp != NULL; tmp = tmp->next)
        if (tmp->next != NULL && tmp->next == player) {
            tmp->next = tmp->next->next;
            free(player);
            break;
        }
}

static void delete_first_player_from_map(map_t *map)
{
    player_on_map_t *tmp;

    tmp = map->players->next;
    free(map->players);
    map->players = tmp;
}

int delete_player_from_map(void *client)
{
    player_on_map_t *player = NULL;
    map_t *map
        = server->map[((client_t *)client)->game.y]
        [((client_t *)client)->game.x];

    for (player = map->players;
        player != NULL
        && player->fd != ((client_t *)client)->fd;
        player = player->next);
    if (player == NULL)
        return (-1);
    if (player == map->players)
        delete_first_player_from_map(map);
    else
        delete_any_player_from_map(player, map);
    return (0);
}