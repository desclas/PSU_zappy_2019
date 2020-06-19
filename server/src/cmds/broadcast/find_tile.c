/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** find_tile.c
*/

#include "server.h"

float get_distance(float x2, float y2, float x1, float y1)
{
    float distance = 0;

    distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return (distance);
}

float determine_smallest_distance(float distances[9])
{
    float smallest = distances[0];

    for (int i = 0; i < 9; i++)
        if (smallest > distances[i])
            smallest = distances[i];
    return (smallest);
}

float *get_distance_array(float x2, float y2, float x1, float y1)
{
    float *distance_array = malloc(sizeof(float) * 9);

    distance_array[0] = get_distance(x2, y2, x1 - 6, y1 - 6);
    distance_array[1] = get_distance(x2, y2, x1, y1 - 6);
    distance_array[2] = get_distance(x2, y2, x1 + 6, y1 - 6);
    distance_array[3] = get_distance(x2, y2, x1 - 6, y1);
    distance_array[4] = get_distance(x2, y2, x1, y1);
    distance_array[5] = get_distance(x2, y2, x1 + 6, y1);
    distance_array[6] = get_distance(x2, y2, x1 - 6, y1 + 6);
    distance_array[7] = get_distance(x2, y2, x1, y1 + 6);
    distance_array[8] = get_distance(x2, y2, x1 + 6, y1 + 6);
    return (distance_array);
}

void arrange_coordinates(float x2, float y2, int *x1, int *y1)
{
    float *distance_array
                = get_distance_array
                (x2, y2, (*x1) + 0.5, (*y1) + 0.5);
    float smallest_distance
                = determine_smallest_distance(distance_array);
    distances_f *tab = get_is_smallest_distance_tab();

    for (int i = 0; i < 9; i++) {
        if (tab[i](distance_array[i], smallest_distance, x1, y1) == 0)
            break;
    }
}

int find_tile(client_t *emitter, client_t *receiver)
{
    int x2 = emitter->game.x;
    int y2 = emitter->game.y;
    int x1 = receiver->game.x;
    int y1 = receiver->game.y;
    int sum_x;
    int sum_y;

    arrange_coordinates(x2 + 0.5, y2 + 0.5, &x1, &y1);
    sum_x = x2 - y1;
    sum_y = y2 - y1;
    if (sum_x == 0 && sum_y == 0)
        (void)x1;
    if (sum_x == 0)
        sum_x_equals_zero(sum_y, &x1, &y1);
    else if (sum_y == 0)
        sum_y_equals_zero(sum_x, &x1, &y1);
    else
        sums_differ_from_zero(sum_x, sum_y, &x1, &y1);
    printf("x1 = %d\ny1 = %d\nx2 = %d\ny2 = %d\n", x1, y1, x2, y2);///TMP
    return (get_tile(receiver, x1, y1));
}