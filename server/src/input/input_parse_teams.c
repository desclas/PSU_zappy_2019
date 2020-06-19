/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** input_parse_teams.c
*/

#include "server.h"

/*!
** @brief get size of the team
**
** @param av argument
** @return int size of team
*/
int input_get_team_size(char **av)
{
    int count = 0;
    int pos = input_find_opt(av, "-n") + 1;

    while (av[pos] != NULL) {
        if (input_is_opt(av[pos]) == 0)
            break;
        pos++;
        count++;
    }
    return (count);
}

/*!
** @brief check if no option is in multiple time
**
** @param av arguments
** @return int sucess 0 error 84
*/
int input_check_duplicates(char **av)
{
    int i = 1;
    int j = input_find_opt(av, "-n") + 1;
    int size = input_get_team_size(av);
    char *previous;

    previous = av[j];
    while (i < size) {
        if (strcmp(previous, av[i + j]) == 0)
            return (84);
        previous = av[i + j];
        i++;
    }
    return (0);
}

/*!
** @brief crate teams
**
** @param av arguments
** @return char** team name
*/
char **input_create_teams(char **av)
{
    char **teams;
    int i = 0;
    int j = input_find_opt(av, "-n") + 1;
    int size = input_get_team_size(av);

    teams = malloc(sizeof(char *) * (size + 1));
    if (teams == NULL || size == 0)
        return (NULL);
    while (i < size) {
        teams[i] = malloc(strlen(av[i + j]) + 1);
        if (teams[i] == NULL)
            return (NULL);
        i++;
    }
    teams[i] = NULL;
    return (teams);
}

/*!
** @brief copy team
**
** @param av arguments
** @param teams teams name
*/
void input_copy_teams(char **av, char **teams)
{
    int i = 0;
    int p = input_find_opt(av, "-n") + 1;

    while (teams[i] != NULL) {
        strcpy(teams[i], av[i + p]);
        i++;
    }
    return;
}

/*!
** @brief parse team args
**
** @param av arguments
** @param input strut of input
** @return int sucess 0 error 84
*/
int input_parse_teams(char **av, input_t *input)
{
    char **teams;

    if (input_check_duplicates(av) == 84)
        return (error_print_message("Teams needs to be unique.", 84));
    teams = input_create_teams(av);
    if (teams == NULL)
        return (error_print_message("Error creating teams.", 84));
    input_destroy_teams(input->teams);
    input_copy_teams(av, teams);
    input->teams = teams;
    return (0);
}