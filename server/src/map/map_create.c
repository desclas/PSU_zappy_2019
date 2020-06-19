/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_create.c
*/

#include "server.h"

/*!
** @brief create a tile in map
**
** @return map_t* map struct
*/
map_t *map_create_tile(void)
{
    map_t *map;

    map = malloc(sizeof(map_t));
    if (map == NULL) {
        fprintf(stderr, "ERR: Malloc tile\n");
        return (NULL);
    }
    map->resources = map_allocate_resources();
    if (map->resources == NULL) {
        fprintf(stderr, "ERR: Malloc resources\n");
        return (NULL);
    }
    map->players = NULL;
    return (map);
}

/*!
** @brief create all tiles of map
**
** @param map map
** @param height height
** @param width width
** @return int sucess 0 error 84
*/
int map_create_tiles(map_t ***map, int height, int width)
{
    int i = 0;
    int j = 0;

    while (i < height) {
        map[i] = malloc(sizeof(map_t *) * (width + 1));
        if (map[i] == NULL)
            return (error_print_message("ERR: Malloc tiles", 84));
        j = 0;
        while (j < width) {
            map[i][j] = map_create_tile();
            if (map[i][j] == NULL)
                return (84);
            j++;
        }
        map[i][j] = NULL;
        i++;
    }
    map[i] = NULL;
    return (0);
}

/*!
** @brief create map
**
** @param height height
** @param width width
** @return map_t*** map struct
*/
map_t ***map_create(int height, int width)
{
    map_t ***map = malloc(sizeof(map_t **) * (height + 1));

    srand(time(0));
    if (map == NULL) {
        fprintf(stderr, "Could not malloc map.\n");
        return (NULL);
    }
    if (map_create_tiles(map, height, width) == 84)
        return (NULL);
    return (map);
}