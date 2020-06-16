/*
** EPITECH PROJECT, 2018
** map_t.h
** File description:
** map_t.h
*/

#ifndef MAP_T_H_
	#define MAP_T_H_

enum {
	FOOD,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME
};

typedef struct		resources_s {
	char		*name;
	int		number;
}			resources_t;

typedef struct		player_on_map_s {
	int			fd;
	struct player_on_map_s	*next;
}			player_on_map_t;

typedef struct		map_s {
	resources_t	*resources;
	player_on_map_t	*players;
}			map_t;

/*
** MAP FUNCTIONS
*/

map_t		***map_create(int, int);
int		map_create_tiles(map_t ***, int, int);
map_t		*map_create_tile(void);
void		map_destroy(map_t ***);
resources_t 	*map_allocate_resources(void);
void		map_destroy_resources(resources_t *);
void		tile_add_resource(int, int, map_t *);
void		tile_del_resource(int, int, map_t *);
int		map_randomize_resource(int, int);

/*
** MANAGE PLAYERS ON MAP
*/

int	place_player_on_map(void *client);
int	add_player_to_map(int fd, map_t *map);
int	delete_player_from_map(void *client);

#endif /* !MAP_T_H_ */