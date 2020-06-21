/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** AI: server
*/

#ifndef AI_H_
#define AI_H_

#include <sys/socket.h>
#include <sys/types.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <sys/select.h>
#include <errno.h>

#define SUCCESS 0
#define FAILURE 84

typedef struct {
    int fd;
    fd_set rfds;
    fd_set wfds;
}client_t;

bool check_activity(client_t *client, fd_set *set_to_check);
client_t *connection_to_server(int port);
void destruct(client_t *client);
char *read_on_client(client_t *client);
int process_select(client_t *client);
int write_on_client(client_t *client, char *str);
uint32_t get_epoll_st(bool st);

#endif /* !AI_H_ */
