/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_destroy.c
*/

#include "map.h"

/*!
** @brief destroy map
**
** @param map map struct
*/
void map_destroy(map_t ***map)
{
    for (size_t i = 0; map[i] != NULL; i++) {
        for (size_t j = 0; map[i][j] != NULL; j++) {
            map_destroy_resources(map[i][j]->resources);
            free(map[i][j]);
        }
        free(map[i]);
    }
    free(map);
}