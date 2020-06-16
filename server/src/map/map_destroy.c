/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** map_destroy
*/

#include "server.h"

/*!
** @brief destroy map
**
** @param map map struct
*/
void	map_destroy(map_t ***map)
{
	int	i = 0;
	int 	j = 0;

	while (map[i] != NULL) {
		j = 0;
		while (map[i][j] != NULL) {
			map_destroy_resources(map[i][j]->resources);
			free(map[i][j]);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}