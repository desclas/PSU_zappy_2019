/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_destroy_resources.c
*/

#include "server.h"

/*!
** @brief destroy map
**
** @param resources resources struct
*/
void map_destroy_resources(resources_t *resources)
{
    int i = 0;

    while (i < 7) {
        free(resources[i].name);
        i++;
    }
    free(resources);
}