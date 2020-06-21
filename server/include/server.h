/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** server.h
*/

#ifndef SERVER_H_
#define SERVER_H_

#define _GNU_SOURCE
#define UNUSED __attribute__((unused))
#define NORET __attribute__((noreturn))

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <poll.h>
#include <string.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include "map_t.h"
#include "input.h"
#include "client_t.h"
#include "host_t.h"
#include "epoll_opt_t.h"
#include "commands.h"

#define SUCCESS 0
#define FAILURE 84
#define MAX_CLIENTS 10
#define INVALID_SOCKET -1

typedef struct sockaddr_in SOCKADDR_IN;
typedef struct sockaddr SOCKADDR;
typedef struct in_addr IN_ADDR;
typedef int SOCKET;

const char g_items[7][10];

enum {
    DEFAULT_PORT = 4242,
    DEFAULT_WIDTH = 20,
    DEFAULT_CLIENT = 10,
    DEFAULT_HEIGHT = 20,
    DEFAULT_FREQ = 10,
    MAX_EVENTS = 10
};

typedef struct server_s {
    input_t *input;
    client_t *client;
    client_t *tail;
    map_t ***map;
    host_t *host;
    int clients[MAX_CLIENTS];
	int sd;
	int pos_sock;
    fd_set readfds;
	fd_set writefds;
} server_t;

extern server_t *server;

/*
** ERROR
*/

void add_socket_to_client_list(SOCKET new_csock);
int error_print_message(char *, int);
int check_number(char *);
int error_print_error(char *, int);

/*
** SERVER
*/

int init_server(int ac, char **av);
int client_activity(server_t *s, client_t *c, fd_set *readfds, int idx);
int manage_client_socket_list(fd_set *rfds, fd_set *wfds, int max_sd, int sd);
int  monitor_socket(fd_set *readfds, fd_set *writefds);
void add_socket_to_client_list(SOCKET new_csock);
int run_server(void);
void log_egg(client_t *, char *);
void put_name(client_t *, char *);
void command_handler(client_t *, char *);
int handle_events(struct epoll_event *);
int accept_client_connection(fd_set readfds, fd_set writefds);
bool team_valid(char *);
bool check_connectable(client_t *, char *);
bool egg_connecable(client_t *, char *);
void log_client(client_t *, char *);
client_t *find_good_client(client_t *c, const int client_fd);

/*
** CIRCULAR BUFFER FUNCTIONS
*/

client_t  *client_to_buffer(client_t *client);
char *extract_cmd(client_t *client);

/*
** CLOCK
*/

void time_it(client_t *client);
double get_day_time_in_microseconds(void);
int check_cmd_deadline(double started_time, double time);

/*
** UTILS
*/

char **split(char *str, char *sep);

#endif /* !SERVER_H_ */