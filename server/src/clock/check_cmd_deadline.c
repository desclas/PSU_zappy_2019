/*
** EPITECH PROJECT, 2018
** check_cmd_deadline.c
** File description:
** check_cmd_deadline.c
*/

#include "server.h"

int	check_cmd_deadline(double started_time, double cmd_time)
{
	double	current_time = get_day_time_in_microseconds();

	if (current_time - started_time >= cmd_time) {
		return (0);
	}
	return (-1);
}