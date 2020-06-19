/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** run_server.c
*/

#include "server.h"

int accept_client_connection(void)
{
    int fd;
    socklen_t len = sizeof(struct sockaddr_in);
    struct epoll_event ev;
    struct sockaddr_in addr;

    fd = accept(server->host->fd, (struct sockaddr *)&addr, &len);
    ev.events = EPOLLIN;
    if (add_client_to_list(fd) == -1)
        return (-1);
    ev.data.ptr = server->tail;
    epoll_ctl(server->ep_opt->epfd, EPOLL_CTL_ADD, fd, &ev);
    return (0);
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
    client->eat = (((float)(126)) / server->input->freq) +
        (clock() / CLOCKS_PER_SEC);
    connect_nbr(client, team);
    dprintf(client->fd, "%d %d\n", server->input->width,
        server->input->height);
}