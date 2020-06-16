/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** map_randomize_resource
*/

#include "server.h"

/*!
** @brief add resources randomly
**
** @param lower minimum of resoursces
** @param upper maximum of resources
** @return int number of resources
*/
int	map_randomize_resource(int lower, int upper)
{
	int	random;

	random = rand() % upper + lower;
	return (random);
}
