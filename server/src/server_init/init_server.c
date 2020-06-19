/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** init_server.c
*/

#include "server.h"

/*!
** @brief init addr option
**
** @param addr sockaddr_in struct
** @return int sucess 0
*/
int init_addr_options(struct sockaddr_in *addr)
{
    addr->sin_family = AF_INET;
    addr->sin_addr.s_addr = INADDR_ANY;
    addr->sin_port = htons(server->input->port);
    return (0);
}

/*!
** @brief init host option
**
** @param host host struct
** @return int sucess 0 error -1
*/
int init_host_options(host_t **host)
{
    *host = malloc(sizeof(host_t));
    (*host)->fd = socket(AF_INET, SOCK_STREAM, 0);
    if ((*host)->fd == -1) {
        perror("socket failed : ");
        return (-1);
    }
    init_addr_options(&(*host)->addr);
    return (0);
}

/*!
** @brief init epoll struct
**
** @return epoll_opt_t* epoll struct
*/
epoll_opt_t *init_epoll_options(void)
{
    epoll_opt_t *ep_opt = calloc(1, sizeof(epoll_opt_t));

    if (ep_opt == NULL)
        return (NULL);
    ep_opt->events = calloc(MAX_EVENTS, sizeof(struct epoll_event));
    if (ep_opt->events == NULL)
        return (NULL);
    ep_opt->ev.events = EPOLLIN | EPOLLOUT;
    ep_opt->ev.data.ptr = server;
    ep_opt->epfd = epoll_create1(0);
    epoll_ctl(ep_opt->epfd, EPOLL_CTL_ADD, server->host->fd,
        &ep_opt->ev);
    return (ep_opt);
}

/*!
** @brief init server
**
** @param ac size of arguments
** @param av arguments
** @return int sucess 0 error -1
*/
int init_server(int ac, char **av)
{
    server = calloc(sizeof(server_t), 1);
    server->input = input_initialize();
    if (server->input == NULL)
        return (-1);
    if (input_parse(ac, av, server->input) == -1)
        return (-1);
    if (init_host_options(&server->host) == -1)
        return (-1);
    server->ep_opt = init_epoll_options();
    if (server->ep_opt == NULL)
        return (-1);
    bind(server->host->fd, (struct sockaddr *) &server->host->addr,
        sizeof(struct sockaddr_in));
    listen(server->host->fd, 100);
    server->client = NULL;
    server->tail = NULL;
    return (0);
}