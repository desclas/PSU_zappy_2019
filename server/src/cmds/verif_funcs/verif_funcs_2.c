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