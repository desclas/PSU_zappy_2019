/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** read epoll
*/

#include "AI.h"

/*!
** @brief concat two str
**
** @param buff first str
** @param str second str
** @return char* strcat
*/
char *copy_it(char *buff, char *str)
{
    char *tmp;

    tmp = calloc(strlen(buff) + strlen(str) + 1, sizeof(char));
    strcat(tmp, str);
    strcat(tmp, buff);
    free(str);
    return (tmp);
}

/*!
** @brief reading server
**
** @param client just a storage
** @return char* result of read
*/
char *read_on_client(client_t *client)
{
    char *buff, *tmp;
    int res = 0;

    buff = calloc( 1024+ 1, sizeof(char));
    tmp = calloc(1, sizeof(char));
    do {
        res = read(client->fd, buff, 1024);
        if (res == 1024) {
            tmp = copy_it(buff, tmp);
            memset(buff, 0, 1024);
        }
    } while (res == 1024);
    if (res > 0)
        buff[strlen(buff) - 1] = '\0';
    tmp = copy_it(buff, tmp);
    free(buff);
    return (tmp);
}