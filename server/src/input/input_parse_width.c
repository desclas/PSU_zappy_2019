/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** input_parse_width
*/

#include "server.h"

/*!
** @brief check input width
**
** @param av argument
** @param input struct of input
** @return int sucess 0 error 84
*/
int	input_parse_width(char **av, input_t *input)
{
	(void)av;

	if (check_number(optarg) == 84)
		return (84);
	input->width = atoi(optarg);
	return (0);
}