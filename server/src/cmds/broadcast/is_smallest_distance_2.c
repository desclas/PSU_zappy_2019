/*
** EPITECH PROJECT, 2018
** is_smallest_distance_2.c
** File description:
** is_smallest_distance_2.c
*/

#include "server.h"

int	is_smallest_distance_6(float distance_to_compare, float distance,
	int *x1, int *y1)
{
	(void)y1;
	if (distance_to_compare == distance) {
		(*x1) = (*x1) + 6;
		return (0);
	}
	return (-1);
}

int	is_smallest_distance_7(float distance_to_compare, float distance,
	int *x1, int *y1)
{
	if (distance_to_compare == distance) {
		(*x1) = (*x1) - 6;
		(*y1) = (*y1) + 6;
		return (0);
	}
	return (-1);
}

int	is_smallest_distance_8(float distance_to_compare, float distance,
	int *x1, int *y1)
{
	(void)x1;
	if (distance_to_compare == distance) {
		(*y1) = (*y1) + 6;
		return (0);
	}
	return (-1);
}

int	is_smallest_distance_9(float distance_to_compare, float distance,
	int *x1, int *y1)
{
	if (distance_to_compare == distance) {
		(*x1) = (*x1) + 6;
		(*y1) = (*y1) + 6;
		return (0);
	}
	return (-1);
}

distances_f	*get_is_smallest_distance_tab(void)
{
	distances_f	*tab
		= malloc(sizeof(distances_f) * 10);

	tab[0] = is_smallest_distance_1;
	tab[1] = is_smallest_distance_2;
	tab[2] = is_smallest_distance_3;
	tab[3] = is_smallest_distance_4;
	tab[4] = is_smallest_distance_5;
	tab[5] = is_smallest_distance_6;
	tab[6] = is_smallest_distance_7;
	tab[7] = is_smallest_distance_8;
	tab[8] = is_smallest_distance_9;
	tab[9] = NULL;
	return (tab);
}