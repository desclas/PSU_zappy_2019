/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** verif_funcs_2.c
*/

#include "server.h"

int is_cmd_inventory(client_t *client, char *cmd)
{
    if (strcmp(cmd, "Inventory") == 0) {
        add_cmd_to_list(client, cmd, inventory, 1);
        return (0);
    }
    return (-1);
}

int is_cmd_set_object(client_t *client, char *cmd)
{
    char **tab = split(cmd, " ");

    if (tab[0] != NULL && strcmp(tab[0], "Take") == 0) {
        add_cmd_to_list(client, cmd, take_object, 7);
        return (0);
    }
    return (-1);
}
