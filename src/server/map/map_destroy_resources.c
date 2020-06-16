/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_destroy_resources.c
*/

#include "map.h"

/*!
** @brief destroy map
**
** @param resources resources struct
*/
void map_destroy_resources(resources_t *resources)
{
    for (size_t i = 0; i < MAX_RESSOURCES; i++)
        free(resources[i].name);
    free(resources);
}