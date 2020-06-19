/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** input_destroy_teams.c
*/

#include "server.h"

/*!
** @brief destroy input team
**
** @param teams to free
*/
void input_destroy_teams(char **teams)
{
    int it = 0;

    while (teams[it] != NULL) {
        free(teams[it]);
        it++;
    }
    free(teams);
}