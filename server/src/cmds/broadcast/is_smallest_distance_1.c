/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** is_smallest_distance_1.c
*/

#include "server.h"

int is_smallest_distance_1(float distance_to_compare, float distance,
    int *x1, int *y1)
{
    if (distance_to_compare == distance) {
        (*x1) = (*x1) - 6;
        (*y1) = (*y1) - 6;
        return (0);
    }
    return (-1);
}

int is_smallest_distance_2(float distance_to_compare, float distance,
    int *x1, int *y1)
{
    (void)x1;
    if (distance_to_compare == distance) {
        (*y1) = (*y1) - 6;
        return (0);
    }
    return (-1);
}

int is_smallest_distance_3(float distance_to_compare, float distance,
    int *x1, int *y1)
{
    if (distance_to_compare == distance) {
        (*x1) = (*x1) + 6;
        (*y1) = (*y1) - 6;
        return (0);
    }
    return (-1);
}

int is_smallest_distance_4(float distance_to_compare, float distance,
    int *x1, int *y1)
{
    (void)y1;
    if (distance_to_compare == distance) {
        (*x1) = (*x1) - 6;
        return (0);
    }
    return (-1);
}

int is_smallest_distance_5(float distance_to_compare, float distance,
    int *x1, int *y1)
{
    (void)y1;
    if (distance_to_compare == distance) {
        (void)x1;
        return (0);
    }
    return (-1);
}