/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** input_find_opt.c
*/

#include "server.h"

/*!
** @brief find option
**
** @param av argument to parse
** @param opt option to find
** @return int if (sucess) return (iterator) else -1
*/
int input_find_opt(char **av, char *opt)
{
    int it = 0;

    while (av[it] != NULL) {
        if (strcmp(av[it], opt) == 0)
            return (it);
        it++;
    }
    return (-1);
}