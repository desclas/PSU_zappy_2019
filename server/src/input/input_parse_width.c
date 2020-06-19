/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** input_parse_width.c
*/

#include "server.h"

/*!
** @brief check input width
**
** @param av argument
** @param input struct of input
** @return int sucess 0 error 84
*/
int input_parse_width(UNUSED char **av, input_t *input)
{
    if (check_number(optarg) == 84)
        return (84);
    input->width = atoi(optarg);
    return (0);
}