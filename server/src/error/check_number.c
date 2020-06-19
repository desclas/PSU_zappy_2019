/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** check_number.c
*/

#include "server.h"

/*!
** @brief check if str is a number only
**
** @param str str to check
** @return int sucess 0 error 84
*/
int check_number(char *str)
{
    int it = 0;

    while (str[it] != '\0') {
        if (!(str[it] >= '0' && str[it] <= '9'))
            return (84);
        it++;
    }
    return (0);
}