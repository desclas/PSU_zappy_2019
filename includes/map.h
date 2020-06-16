/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** map.h
*/

#ifndef MAP_H_
#define MAP_H_

#include <stdlib.h>
#include <stdio.h>

#define MAX_RESSOURCES 7

enum {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

const char *resource[MAX_RESSOURCES] =
{
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

typedef struct resources_s {
    char *name;
    int number;
} resources_t;

typedef struct map_s {
    resources_t *resources;
    size_t *players;
} map_t;

/*
** MAP FUNCTIONS
*/

map_t ***map_create(size_t height, size_t width);
void map_destroy(map_t *** map);
resources_t *map_allocate_resources(void);
void map_destroy_resources(resources_t *);
void tile_add_resource(int pos, int nb, map_t * map);
void tile_del_resource(int pos, int nb, map_t * map);
int map_randomize_resource(int lower, int upper);

#endif // !MAP_H_