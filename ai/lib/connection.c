/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** AI LIB: connection to server
*/

#include "AI.h"

/*!
** @brief initialization of fdsets
**
** @param fd fd monitored
** @return client_t just a storage
*/
static client_t *init_client_sets(int fd)
{
    client_t *cli = calloc(1, sizeof(*cli));
    fd_set readfds;
    fd_set writefds;

    if (cli == NULL)
        exit(FAILURE);
    cli->fd = fd;
    cli->rfds = readfds;
    cli->wfds = writefds;
    FD_ZERO(&cli->rfds);
    FD_ZERO(&cli->wfds);
    FD_SET(cli->fd, &cli->rfds);
    FD_SET(cli->fd, &cli->wfds);
    return (cli);
}

/*!
** @brief connection to server
**
** @param port port listened by server
** @return client_t just a storage
*/
client_t *connection_to_server(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    socklen_t slen = sizeof(struct sockaddr_in);
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *)&addr, slen) != 0)
        exit(FAILURE);
    return (init_client_sets(sock));
}