/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** delete_cmd_from_list.c
*/

#include "server.h"

/*!
** @brief delete first element of cmd list
**
** @param cmd_list list triggered
** @return commands_t* head of the list
*/
commands_t *delete_first_cmd_from_list(commands_t *cmd_list)
{
    commands_t *tmp = cmd_list;

    if (cmd_list == NULL)
        return (NULL);
    cmd_list = cmd_list->next;
    free(tmp->cmd);
    free(tmp);
    return (cmd_list);
}