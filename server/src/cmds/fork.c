/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** fork.c
*/

#include "server.h"

/*!
** @brief creating egg
**
** @param client client triggered
** @param cmd UNUSED
*/
void forkp(client_t *client, UNUSED char *cmd)
{
    char *team = calloc(strlen(client->game.team) + 2, sizeof(char));
    commands_t *com = calloc(1, sizeof(*com));
    char *str = calloc(50, sizeof(char));

    add_client_to_list(-1);
    server->tail->status = EGG;
    strcmp(team, client->game.team);
    server->tail->game.team = team;
    com->init = true;
    com->time = (((float)(600)) / server->input->freq) +
        (clock() / CLOCKS_PER_SEC);
    com->cmd_func = init_egg;
    server->tail->cmd_list = com;
}