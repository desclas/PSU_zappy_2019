/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** add_cmd_to_list.c
*/

#include "server.h"

/*!
** @brief Get the cmd list size object
**
** @param cmd_list command lsit
** @return int size of the list
*/
int get_cmd_list_size(commands_t *cmd_list)
{
    commands_t *tmp = cmd_list;
    int i = 0;

    for (; tmp != NULL; tmp = tmp->next, i++);
    return (i);
}

/*!
** @brief add command in cmd list
**
** @param client client triggered
** @param cmd command to add
** @param func function to call
** @param cmd_time time of timeout
** @return int sucess 0 error -1
*/
int add_cmd_to_list(client_t *client, char *cmd, commands_f func,
    int cmd_time)
{
    commands_t *elem = calloc(1, sizeof(commands_t));
    commands_t *tmp;

    if (elem == NULL)
        return (-1);
    elem->init = false;
    elem->cmd = strdup(cmd);
    elem->cmd_func = func;
    elem->next = NULL;
    elem->time = ((double)cmd_time / (double)server->input->freq) * 1000000;
    if (client->cmd_list == NULL) {
        elem->next = client->cmd_list;
        client->cmd_list = elem;
    }
    else {
        for (tmp = client->cmd_list;
            tmp->next != NULL; tmp = tmp->next);
        tmp->next = elem;
    }
    return (0);
}