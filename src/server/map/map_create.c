/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map_create.c
*/

#include "map.h"

/*!
** @brief create a tile in map
**
** @return map_t* map struct
*/
static map_t *map_create_tile(void)
{
    map_t *map;

    map = calloc(1, sizeof(map_t));
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
static int map_create_tiles(map_t ***map, size_t height, size_t width)
{
    for (size_t i = 0; i < height; i++) {
        map[i] = calloc(width + 1, sizeof(map_t *));
        if (map[i] == NULL)
            return (error_print_message("ERR: Malloc tiles", 84));
        for (size_t j = 0; j < width; j++) {
            map[i][j] = map_create_tile();
            if (map[i][j] == NULL)
                return (84);
        }
    }
    return (0);
}

/*!
** @brief create map
**
** @param height height
** @param width width
** @return map_t*** map struct
*/
map_t ***map_create(size_t height, size_t width)
{
    map_t ***map = calloc(height + 1, sizeof(map_t ***));

    srand(time(0));
    if (map == NULL) {
        fprintf(stderr, "Could not malloc map.\n");
        return (NULL);
    }
    if (map_create_tiles(map, height, width) == 84)
        return (NULL);
    return (map);
}