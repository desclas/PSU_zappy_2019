/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_allocate_resources.c
*/

#include "map.h"

/*!
** @brief init map
**
** @param resources resources in map
** @return int sucess 0
*/
static int map_initialize_resources(resources_t *resources)
{
    int	i = 0;

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
    resources_t *resources = calloc(8, sizeof(resources_t));

    if (resources == NULL) {
        fprintf(stderr, "ERR: Resources creation failed");
        return (NULL);
    }
    map_initialize_resources(resources);
    return (resources);
}