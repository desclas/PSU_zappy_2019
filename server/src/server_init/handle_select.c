/*
** EPITECH PROJECT, 2019
** handle_select
** File description:
** handle_select
*/

#include "server.h"

int client_activity(client_t *c, fd_set *readfds)
{
    char *buff = NULL;

    if ((FD_ISSET(c->fd , readfds))) {
        client_to_buffer(c);
        buff = extract_cmd(c);
        if (buff[0] == 0) {
            delete_player_from_map(c);
            delete_client_from_list((c));
            printf("client left :(\n");
            return (SUCCESS);
        } else {
            command_handler(c, buff);
            return (SUCCESS);
        }
    }
    return (FAILURE);
}

int manage_client_socket_list(fd_set *rfds, int max_sd, int sd)
{
    FD_ZERO(rfds);
    FD_SET(server->host->fd, (rfds));
    max_sd = server->host->fd;
    for (client_t *tmp = server->client; tmp; tmp = tmp->next) {
        sd = tmp->fd;
        server->sd = sd;
        if (sd > 0)
            FD_SET(sd, rfds);
        if (sd > max_sd)
            max_sd = sd;
    }
    return (max_sd);
}

int  monitor_socket(fd_set *readfds)
{
    int activity = 0;
    int sd = 0;
    int max_sd = 0;

    max_sd = manage_client_socket_list(readfds, max_sd, sd);
    activity = select(max_sd + 1, readfds, NULL, NULL,
        ((server->timeout.tv_sec == 0 && server->timeout.tv_usec == 0) ?
        NULL : &server->timeout));
    if ((activity < 0) && (errno != EINTR)) {
        perror("select() fail");
        return (FAILURE);
    }
    return (SUCCESS);
}