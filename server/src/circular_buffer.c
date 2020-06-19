/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** circular_buffer.c
*/

#include "server.h"

/*!
** @brief return command
**
** @param client client triggered
** @return char* content of circular buffer
*/
char *extract_cmd(client_t *client)
{
    char *command;
    int len = 0;

    while (client->buffer[(client->j + len) % MAX_BUFF] != '\n'
    && client->buffer[0] != 0)
        len += 1;
    command = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        command[i] = client->buffer[client->j];
        client->j += 1;
        if (client->j >= MAX_BUFF)
            client->j = 0;
    }
    command[len] = '\0';
    client->j += 1;
    return (command);
}

/*!
** @brief read and put in circular buffer
**
** @param client client triggered
** @return client_t* client triggered
*/
client_t *client_to_buffer(client_t *client)
{
    char c;
    int stop = 0;

    while (stop != 1) {
        if (read(client->fd, &c, 1) == 0) {
            memset(client->buffer, 0, MAX_BUFF);
            break;
        }
        client->buffer[client->i] = c;
        if (c == '\n')
            stop++;
        client->i++;
        if (client->i >= MAX_BUFF)
            client->i = 0;
    }
    return (client);
}