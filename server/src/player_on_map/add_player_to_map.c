/*
** EPITECH PROJECT, 2018
** add_player_to_map_tile.c
** File description:
** add_player_to_map_tile.c
*/

#include "server.h"

static int	add_first_player_to_map(int fd, map_t *map)
{
	player_on_map_t	*p = malloc(sizeof(player_on_map_t));

	if (p == NULL)
		return (-1);
	p->fd = fd;
	p->next = NULL;
	map->players = p;
	return (0);
}

static int	add_last_player_to_map(int fd, map_t *map)
{
	player_on_map_t	*p = malloc(sizeof(player_on_map_t));
	player_on_map_t	*tmp;

	if (p == NULL)
		return (-1);
	p->fd = fd;
	p->next = NULL;
	for (tmp = map->players; tmp->next != NULL; tmp = tmp->next);
	tmp->next = p;
	return (0);
}

int	add_player_to_map(int fd, map_t *map)
{
	if (map->players == NULL) {
		if (add_first_player_to_map(fd, map) == -1)
			return (-1);
	}
	else {
		if (add_last_player_to_map(fd, map) == -1)
			return (-1);
	}
	return (0);
}