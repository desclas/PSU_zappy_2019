/*
** EPITECH PROJECT, 2018
** verif_funcs_2.c
** File description:
** verif_funcs_2.c
*/

#include "server.h"

int	is_cmd_inventory(client_t *client, char *cmd)
{
	if (strcasecmp(cmd, "Inventory") == 0) {
		add_cmd_to_list(client, cmd, inventory, 1);
		return (0);
	}
	return (-1);
}