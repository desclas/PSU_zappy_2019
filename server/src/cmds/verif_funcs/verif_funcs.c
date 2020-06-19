/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** verif_funcs.c
*/

#include "server.h"

/*!
** @brief add UNKNOWN command into the list
**
** @param client client triggered
** @param cmd command to add
** @return int sucess 0
*/
int is_cmd_false(client_t *client, char *cmd)
{
    add_cmd_to_list(client, cmd, false_cmd, 0);
    return (0);
}

int is_cmd_broadcast(client_t *client, char *cmd)
{
    char **tab = split(cmd, " ");

    if (tab[0] != NULL && strcasecmp(tab[0], "Broadcast") == 0) {
        add_cmd_to_list(client, cmd, broadcast, 7);
        return (0);
    }
    return (-1);
}

int is_cmd_take_object(client_t *client, char *cmd)
{
    char **tab = split(cmd, " ");

    if (tab[0] != NULL && strcasecmp(tab[0], "Take") == 0) {
        add_cmd_to_list(client, cmd, take_object, 7);
        return (0);
    }
    return (-1);
}

int is_cmd_look(client_t *client, char *cmd)
{
    if (strcasecmp(cmd, "Look") == 0) {
        add_cmd_to_list(client, cmd, look, 7);
        return (0);
    }
    return (-1);
}

/*!
** @brief check existence of the requested command
**
** @param client client triggered
** @param cmd command requested
*/
void verif_funcs(client_t *client, char *cmd)
{
    int i = 0;
    int res = -1;

    for (; i < 6; i++) {
        res = verif_func[i](client, cmd);
        if (res == 0)
            break;
    }
}