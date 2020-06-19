/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** get_tile_in_y.c
*/

#include "server.h"

int get_tile_in_y_1(client_t *receiver, int x, int y)
{
    int direction = (receiver->direction == UP) ? (1) : (-1);
    int c_x = receiver->game.x;
    int c_y = receiver->game.y;
    int height = server->input->height;
    int width = server->input->width;

    if (x == c_x && y == (c_y + direction + height) % height)
        return (1);
    if (x == (c_x - 1 + width) % width
        && y == (c_y + direction + height) % height)
        return (2);
    if (x == (c_x - 1 + width) % width && y == c_y)
        return (3);
    if (x == (c_x - 1 + width) % width
        && y == (c_y - direction + height) % height)
        return (4);
    return (0);
}

int get_tile_in_y_2(client_t *receiver, int x, int y)
{
    int direction = (receiver->direction == UP) ? (1) : (-1);
    int c_x = receiver->game.x;
    int c_y = receiver->game.y;
    int height = server->input->height;
    int width = server->input->width;

    if (x == c_x && y == (c_y - direction + height) % height)
        return (5);
    if (x == (c_x + 1 + width) % width
        && y == (c_y - direction + height) % height)
        return (6);
    if (x == (c_x + 1 + width) % width && y == c_y)
        return (7);
    if (x == (c_x + 1 + width) % width
        && y == (c_y + direction + height) % height)
        return (8);
    return (0);
}

int get_tile_in_y(client_t *receiver, int x, int y)
{
    int a = get_tile_in_y_1(receiver, x, y);
    int b = get_tile_in_y_2(receiver, x, y);

    if (a != 0)
        return (a);
    if (b != 0)
        return (b);
    return (1);
}