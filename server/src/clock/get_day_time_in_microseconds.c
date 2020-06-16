/*
** EPITECH PROJECT, 2018
** get_day_time_in_microseconds.c
** File description:
** get_day_time_in_microseconds.c
*/

#include "server.h"

/*!
** @brief Get the day time in microseconds object
**
** @return double time in µs
*/
double get_day_time_in_microseconds(void)
{
	struct timeval	daytime;
	double		time_in_micros = 0;

	gettimeofday(&daytime, NULL);
	time_in_micros = (double)daytime.tv_sec * 1000000
		+ (double)daytime.tv_usec;
	return (time_in_micros);
}