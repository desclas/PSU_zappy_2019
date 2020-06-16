/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI LIB: connection to server
*/

#include "AI.h"

/*!
** @brief initialization of epoll struct
**
** @param fd fd monitored
** @return client_t just a storage
*/
static client_t *epoll_init(int fd)
{
	client_t *cli = calloc(1, sizeof(*cli));
	struct epoll_event ev;

	if (cli == NULL)
		exit(84);
	cli->fd = fd;
	cli->event = calloc(5, sizeof(*cli->event));
	ev.data.ptr = cli;
	ev.events = EPOLLIN | EPOLLOUT;
	cli->epfd = epoll_create(5);
	epoll_ctl(cli->epfd, EPOLL_CTL_ADD, fd, &ev);
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
	if (connect(sock, (struct sockaddr *) &addr, slen) != 0)
		exit(84);
	return (epoll_init(sock));
}