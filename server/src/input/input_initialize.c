/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** input_initialize.c
*/

#include "server.h"

const char *default_teams[4] =
{
    "Vegeta",
    "Frieza",
    "Kakarot",
    NULL
};

/*!
** @brief init team input
**
** @return char** all team name
*/
char **input_initialize_teams(void)
{
    char **teams;
    int it = 0;

    teams = malloc(sizeof(char *) * 4);
    if (teams == NULL) {
        error_print_message("Failed to malloc teams.", 84);
        return (NULL);
    }
    while (it < 3) {
        teams[it] = malloc(strlen(default_teams[it]) + 1);
        if (teams[it] == NULL) {
            error_print_message("Failed to malloc team.", 84);
            return (NULL);
        }
        strcpy(teams[it], default_teams[it]);
        it++;
    }
    teams[it] = NULL;
    return (teams);
}

/*!
** @brief init all input
**
** @return input_t* struct of input
*/
input_t *input_initialize(void)
{
    input_t  *input;

    input = malloc(sizeof(input_t));
    if (input == NULL) {
        error_print_message("Failed to malloc input.", 84);
        return (NULL);
    }
    input->port = DEFAULT_PORT;
    input->width = DEFAULT_WIDTH;
    input->height = DEFAULT_HEIGHT;
    input->teams = input_initialize_teams();
    input->client_nb = DEFAULT_CLIENT;
    input->freq = DEFAULT_FREQ;
    return (input);
}