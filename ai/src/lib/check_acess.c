/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** testing acess
*/

#include "AI.h"

/*!
** @brief check acess on epoll event
**
** @param index index of event
** @param client
** @param check state must be checked
** @return true
** @return false
*/
bool check_acess(size_t index, client_t *client, uint32_t check)
{
	if (index > 0)
		if (client->event[index - 1].events & check)
			return (true);
	return (false);
}