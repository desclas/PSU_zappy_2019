/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** input_parse_freq.c
*/

#include "server.h"

/*!
** @brief check input freq
**
** @param av UNUSED
** @param input struct of input
** @return int sucess 0 error 84
*/
int input_parse_freq(UNUSED char **av, input_t *input)
{
    if (check_number(optarg) == 84)
        return (84);
    input->freq = atoi(optarg);
    return (0);
}