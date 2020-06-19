/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** host_t.h
*/

#ifndef HOST_T_H_
#define HOST_T_H_

#include <netdb.h>

typedef struct host_s {
    int fd;
    struct sockaddr_in addr;
    uint16_t port;
} host_t;

#endif /* !HOST_T_H_ */
