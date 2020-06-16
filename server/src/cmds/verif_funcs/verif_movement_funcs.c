/*
** EPITECH PROJECT, 2018
** verif_movement_funcs.c
** File description:
** verif_movement_funcs.c
*/

#include "server.h"

/*!
** @brief check if the command is le "Left" command
**
** @param client client triggered
** @param cmd command to check
** @return int sucess 0 error -1
*/
int	is_cmd_left(client_t *client, char *cmd)
{
	if (strcasecmp(cmd, "Left") == 0) {
		add_cmd_to_list(client, cmd, turn_left, 7);
		return (0);
	}
	return (-1);
}

/*!
** @brief check if command is the "Right" command
**
** @param client client triggered
** @param cmd command to check
** @return int sucess 0 error -1
*/
int	is_cmd_right(client_t *client, char *cmd)
{
	if (strcasecmp(cmd, "Right") == 0) {
		add_cmd_to_list(client, cmd, turn_right, 7);
		return (0);
	}
	return (-1);
}

int	is_cmd_forward(client_t *client, char *cmd)
{
	if (strcasecmp(cmd, "Forward") == 0) {
		add_cmd_to_list(client, cmd, go_forward, 7);
		return (0);
	}
	return (-1);
}