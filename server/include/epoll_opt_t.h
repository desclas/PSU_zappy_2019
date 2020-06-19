/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** epoll_opt_t.h
*/

#ifndef EPOLL_OPT_T_H_
#define EPOLL_OPT_T_H_

#include <sys/epoll.h>

typedef struct epoll_opt_s {
    int epfd;
    struct epoll_event *events;
    struct epoll_event ev;
} epoll_opt_t;

epoll_opt_t *init_epoll_options();

#endif /* !EPOLL_OPT_T_H_ */
