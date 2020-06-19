/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** run_server2.c
*/

#include "server.h"

/*!
** @brief log client has egg
**
** @param client client triegered
** @param team team conserned
*/
void log_egg(client_t *client, char *team)
{
    int fd = client->fd;
    //struct epoll_event ev;

    client->fd = -1;
    delete_client_from_list(client);
    add_client_to_list(fd);
    //ev.data.ptr = server->tail;
    //ev.events = EPOLLIN;
    //epoll_ctl(server->ep_opt->epfd, EPOLL_CTL_MOD, server->tail->fd, &ev);
    client = server->tail;
    client->log = true;
    client->game.team = team;
    if (client->cmd_list == NULL)
        client->eat = (((float)(126)) / server->input->freq) +
            (clock() / CLOCKS_PER_SEC);
    else
        client->eat = -1;
    connect_nbr(client, team);
    dprintf(client->fd, "%d %d\n", server->input->width,
        server->input->height);
}

/*!
** @brief log client
**
** @param client client trigered
** @param cmd team name
*/
void put_name(client_t *client, char *cmd)
{
    if (team_valid(cmd)) {
        if (check_connectable(client, cmd))
            log_client(client, cmd);
        else if (egg_connecable(client, cmd))
            log_egg(client, cmd);
        else {
            free(cmd);
            dprintf(client->fd, "ko\n");
        }
        place_player_on_map(client);
    } else
        dprintf(client->fd, "ko\n");
}

void command_handler(client_t *client, char *cmd)
{
    if (client->log == false)
        put_name(client, cmd);
    else if (get_cmd_list_size(client->cmd_list) < 10)
        verif_funcs(client, cmd);
}

int run_server(void)
{
    fd_set readfds;
    fd_set writefds;

    while (true) {
        if (monitor_socket(&readfds, &writefds) == FAILURE)
            return (FAILURE);
        if (accept_client_connection(readfds, writefds) == INVALID_SOCKET)
            return (FAILURE);
        if (server->client != NULL)
            time_it(server->client);
    }
    return (0);
}