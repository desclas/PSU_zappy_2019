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
    struct epoll_event ev;

    client->fd = -1;
    delete_client_from_list(client);
    add_client_to_list(fd);
    ev.data.ptr = server->tail;
    ev.events = EPOLLIN;
    epoll_ctl(server->ep_opt->epfd, EPOLL_CTL_MOD, server->tail->fd, &ev);
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

int handle_events(struct epoll_event *ev)
{
    char *buff;

    if (ev->data.ptr == server) {
        printf("client connection\n");
        accept_client_connection();
        printf("client connected\n");
    } else {
        client_to_buffer(ev->data.ptr);
        buff = extract_cmd(ev->data.ptr);
        if (buff[0] == 0) {
            epoll_ctl(server->ep_opt->epfd, EPOLL_CTL_DEL,
            ((client_t *)(ev->data.ptr))->fd, NULL);
            delete_player_from_map((client_t *)ev->data.ptr);
            delete_client_from_list((client_t *)ev->data.ptr);
            printf("client left :(\n");
        }
        else
            command_handler(ev->data.ptr, buff);
    }
    return (0);
}

int run_server(void)
{
    int i = 0;
    int nfds = 0;
    struct epoll_event events[10];

    while (true) {
        nfds = epoll_wait(server->ep_opt->epfd, events,
            MAX_EVENTS, 50);
        for (i = 0; i < nfds; i++)
            handle_events(&events[i]);
        if (server->client != NULL)
            time_it(server->client);
    }
    return (0);
}