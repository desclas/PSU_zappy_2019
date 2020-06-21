/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_randomize_resource.c
*/

#include "server.h"

/*!
** @brief add resources randomly
**
** @param lower minimum of resoursces
** @param upper maximum of resources
** @return int number of resources
*/
int map_randomize_resource(int lower, int upper)
{
    int random;

    random = rand() % (upper + 1);
    return (((random < lower) ? lower : random));
}

void map_randomize_map(map_t ***map)
{
    for (int ex = rand() % ((rand() % 7) + 2), _ = 0; _ < ex; _++)
        tile_add_resource(rand() % 7, rand() % 2, map[rand() %
            server->input->height][rand() % server->input->width]);
}