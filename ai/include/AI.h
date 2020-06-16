/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** AI: server
*/

#ifndef AI_H_
# define AI_H_

# include <sys/socket.h>
# include <sys/types.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/epoll.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdio.h>

typedef struct {
	int epfd;
	int fd;
	struct epoll_event *event;
} client_t;

bool check_acess(size_t index, client_t *client, uint32_t check);
client_t *connection_to_server(int port);
void destruct(client_t *client);
char *epoll_read(client_t *client);
int epoll_wait_it(client_t *client);
int epoll_write(client_t *client, char *str);
uint32_t get_epoll_st(bool st);

#endif /* !AI_H_ */
