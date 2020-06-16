/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** map_destroy_resources
*/

#include "server.h"

/*!
** @brief destroy map
**
** @param resources resources struct
*/
void	map_destroy_resources(resources_t *resources)
{
	int	i = 0;

	while (i < 7) {
		free(resources[i].name);
		i++;
	}
	free(resources);
}