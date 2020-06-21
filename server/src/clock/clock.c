/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** clock.c
*/

#include "server.h"

static void check_client_dead(client_t **client)
{
    client_t *tmp;

    if ((*client)->game.inv[FOOD] < 0) {
        while ((*client)->cmd_list != NULL)
            (*client)->cmd_list =
                delete_first_cmd_from_list((*client)->cmd_list);
        free((*client)->game.team);
        tmp = (*client)->next;
        dprintf((*client)->fd, "dead\n");
        delete_client_from_list(*client);
        *client = tmp;
    }
}

/*!
** @brief check if client is dead or alive
**
** @param client chained list
*/
void is_alive(client_t *client)
{
    double current = get_day_time_in_microseconds();

    for (; client->prev != NULL; client = client->prev);
    for (; client != NULL; client = client->next) {
        if (client->eat != -1 && current - client->eat >= FOOD_FREQ) {
            client->eat = current;
            client->game.inv[FOOD]--;
            check_client_dead(&client);
        }
        if (client == NULL)
            break;
    }
}

/*!
** @brief execute the command and remove it from the list of comancds
**
** @param client client triggered
** @param cmd command list of client
*/
void launch_func(client_t *client, commands_t *cmd)
{
    cmd->cmd_func(client, cmd->cmd);
    client->cmd_list = delete_first_cmd_from_list(client->cmd_list);
}

/*!
** @brief init time for commands
**
** @param cmd command list
*/
void init_time(commands_t *cmd)
{
    struct timeval tv;

    if (cmd != NULL && cmd->init == false) {
        printf("\n\nSTARTED %s\n", cmd->cmd);
        gettimeofday(&tv, NULL);
        cmd->init = true;
        cmd->started_time = (double)tv.tv_sec * 1000000 + (double)tv.tv_usec;
    }
}

/*!
** @brief launch commande if it timeout
**
** @param client client list
*/
void time_it(client_t *client)
{
    commands_t *cmd;

    for (; client->prev != NULL; client = client->prev);
    for (; client != NULL; client = client->next) {
        cmd = client->cmd_list;
        if (cmd != NULL && cmd->init && check_cmd_deadline(cmd->started_time,
                cmd->time) == 0)
            launch_func(client, cmd);
        else
            init_time(cmd);
    }
}