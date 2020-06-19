/*
** EPITECH PROJECT, 2019
** handle_select
** File description:
** handle_select
*/

#include "server.h"

int client_activity(server_t *s, client_t *c, fd_set *readfds, int idx)
{
    char *buff = NULL;

    s->sd = s->clients[idx];
    if ((FD_ISSET(s->sd , readfds)) && (c->fd = s->sd)) {
        s->pos_sock = idx;
        client_to_buffer(c);
        buff = extract_cmd(c);
        if (buff[0] == 0) {
            delete_player_from_map(c);
            delete_client_from_list((c));
            printf("client left :(\n");
        } else
            command_handler(c, buff);
    }
    return (SUCCESS);
}

int manage_client_socket_list(fd_set *rfds, fd_set *wfds, int max_sd, int sd)
{
	wfds += 0;
    FD_ZERO(rfds);
    FD_SET(server->host->fd, (rfds));
    max_sd = server->host->fd;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        sd = server->clients[i];
        server->sd = sd;
        if (sd > 0)
            FD_SET(sd, rfds);
        if (sd > max_sd)
            max_sd = sd;
    }
    return (max_sd);
}

int  monitor_socket(fd_set *readfds, fd_set *writefds)
{
    int activity = 0;
    int sd = 0;
    int max_sd = 0;

    max_sd = manage_client_socket_list(readfds, writefds, max_sd, sd);
    activity = select(max_sd + 1 , readfds , writefds , NULL , NULL);
    if ((activity < 0) && (errno != EINTR)) {
        perror("select() fail");
        return (FAILURE);
    }
    return (SUCCESS);
}

void add_socket_to_client_list(SOCKET new_csock)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (server->clients[i] == 0) {
            server->clients[i] = new_csock;
            break;
        }
    }
    return;
}