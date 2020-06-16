/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** map_add_resources
*/

#include "server.h"

/*!
** @brief add resources in tile
**
** @param pos position of tile
** @param nbr number of resources to add
** @param tile tile
*/
void	tile_add_resource(int pos, int nbr, map_t *tile)
{
	tile->resources[pos].number += nbr;
}

/*!
** @brief delete resources in tile
**
** @param pos position of tile
** @param nbr number of resources to delete
** @param tile tile
*/
void	tile_del_resource(int pos, int nbr, map_t *tile)
{
	if ((tile->resources[pos].number) - nbr >= 0)
		tile->resources[pos].number -= nbr;
}