/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** run_server.c
*/

#include "server.h"

int accept_client_connection(fd_set rfd)
{
    SOCKADDR_IN c_sin = {0};
    int new_csock = -1;
    socklen_t size_sin = 0;
    if (FD_ISSET(server->host->fd, &rfd)) {
        size_sin = sizeof(SOCKADDR_IN);
        new_csock = accept(server->host->fd, (SOCKADDR *)&c_sin, &size_sin);
        if (new_csock == INVALID_SOCKET) {
            perror("accept() fail");
            return (INVALID_SOCKET);
        }
        dprintf(new_csock, "WELCOME\n");
        add_client_to_list(new_csock);
    } else {
        for (client_t *tmp = server->client; tmp; tmp = tmp->next)
            client_activity(tmp, &rfd);
    }
    return (SUCCESS);
}

/*!
** @brief checkt team name
**
** @param team name to check
** @return true
** @return false
*/
bool team_valid(char *team)
{
    for (size_t i = 0; server->input->teams[i] != NULL; i++)
        if (strcmp(team, server->input->teams[i]) == 0)
            return (true);
    return (false);
}

/*!
** @brief check if one place remaining
**
** @param client list of client
** @param team team conserned
** @return true
** @return false
*/
bool check_connectable(client_t *client, char *team)
{
    size_t count = 0;

    while (client->prev != NULL)
        client = client->prev;
    while (client != NULL) {
        if (client->log && client->status == PLAYER &&
                strcmp(client->game.team, team) == 0)
            count++;
        client = client->next;
    }
    return ((count - server->input->client_nb < 1) ? false : true);
}

/*!
** @brief check if an agg is free
**
** @param client list of clients
** @param team team conserned
** @return true
** @return false
*/
bool egg_connecable(client_t *client, char *team)
{
    size_t count = 0;

    while (client->prev != NULL)
        client = client->prev;
    while (client != NULL) {
        if (!client->log && client->status == EGG &&
                strcmp(client->game.team, team) == 0)
            count++;
        client = client->next;
    }
    return (count != 0);
}

/*!
** @brief log client in game
**
** @param client client trigered
** @param team his team
*/
void log_client(client_t *client, char *team)
{
    client->log = true;
    client->game.team = team;
    client->eat = get_day_time_in_microseconds();
    connect_nbr(client, team);
    dprintf(client->fd, "%d %d\n", server->input->width,
        server->input->height);
}