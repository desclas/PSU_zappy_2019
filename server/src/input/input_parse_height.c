/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** input_parse_height.c
*/

#include "server.h"

/*!
** @brief check input height
**
** @param av UNUSED
** @param input struct of input
** @return int sucess 0 error 84
*/
int input_parse_height(UNUSED char **av, input_t *input)
{
    if (check_number(optarg) == 84)
        return (84);
    input->height = atoi(optarg);
    return (0);
}