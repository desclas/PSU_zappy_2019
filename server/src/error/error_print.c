/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** error_print.c
*/

#include "server.h"

/*!
** @brief use perror
**
** @param error for perror
** @param value return value
** @return int return value arg
*/
int error_print_perror(char *error, int value)
{
    perror(error);
    return (value);
}

/*!
** @brief print on stderr
**
** @param error to print
** @param value return value
** @return int return value arg
*/
int error_print_message(char *error, int value)
{
    fprintf(stderr, "%s\n", error);
    return (value);
}