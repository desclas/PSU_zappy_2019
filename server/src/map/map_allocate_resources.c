/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_allocate_resources.c
*/

#include "server.h"

const char *resource[7] =
{
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

/*!
** @brief init map
**
** @param resources resources in map
** @return int sucess 0
*/
int map_initialize_resources(resources_t *resources)
{
    int i = 0;

    while (i < 7) {
        resources[i].name = strdup(resource[i]);
        resources[i].number = map_randomize_resource(5, 20);
        i++;
    }
    return (0);
}

/*!
** @brief allocation of resources for map
**
** @return resources_t* resources struct
*/
resources_t *map_allocate_resources(void)
{
    resources_t *resources = malloc(sizeof(resources_t) * 8);

    if (resources == NULL) {
        fprintf(stderr, "ERR: Resources creation failed");
        return (NULL);
    }
    if (map_initialize_resources(resources) == 84)
        return (NULL);
    return (resources);
}