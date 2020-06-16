/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** input_dump_data
*/

#include "server.h"

/*!
** @brief print input data
**
** @param input to print
*/
void	input_dump_data(input_t *input)
{
	int i = 0;

	printf("\n****\nPORT: %d\n", input->port);
	printf("WIDTH: %d, HEIGHT: %d\n", input->width, input->height);
	printf("FREQ: %d\n", input->freq);
	printf("CLIENT_NB: %d\n", input->client_nb);
	while (input->teams[i] != NULL) {
		printf("TEAM[%d] = %s\n", i, input->teams[i]);
		i++;
	}
	printf("****\n");
	return;
}