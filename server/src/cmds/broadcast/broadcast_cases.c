/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** broadcast_cases.c
*/

#include "server.h"

void sum_x_equals_zero(int sum_y, int *x1, int *y1)
{
    (void)x1;
    if (sum_y > 0)
        (*y1) = ((*y1) + 1 + server->input->height)
            % server->input->height;
    else if (sum_y < 0)
        (*y1) = ((*y1) - 1 + server->input->height)
            % server->input->height;
}

void sum_y_equals_zero(int sum_x, int *x1, int *y1)
{
    (void)y1;
    if (sum_x > 0)
        (*x1) = ((*x1) + 1 + server->input->width)
            % server->input->width;
    else if (sum_x < 0)
        (*x1) = ((*x1) - 1 + server->input->width)
            % server->input->width;
}

void sum_x_superior_to_sum_y(int sum_x, int sum_y, int *x1, int *y1)
{
    double coef_x = (sum_x > 0) ? (0.1) : (-0.1);
    double coef_y = coef_x * sum_y / sum_x;
    float cpy_x = *x1;
    float cpy_y = *y1;

    for (; (int)cpy_x == *x1 && (int)cpy_y == *y1; (void)x1) {
        cpy_x = cpy_x + coef_x;
        cpy_y = cpy_y + coef_y;
    }
    (*x1) = ((int)cpy_x + server->input->width) % server->input->width;
    (*y1) = ((int)cpy_y + server->input->height) % server->input->height;
}

void sum_y_superior_to_sum_x(int sum_x, int sum_y, int *x1, int *y1)
{
    double coef_y = (sum_y > 0) ? (0.1) : (-0.1);
    double coef_x = coef_y * sum_x / sum_y;
    float cpy_x = (float)*x1 + 0.5;
    float cpy_y = (float)*y1 + 0.5;

    for (; (int)cpy_x == *x1 && (int)cpy_y == *y1; (void)x1) {
        cpy_x = cpy_x + coef_x;
        cpy_y = cpy_y + coef_y;
    }
    (*x1) = ((int)cpy_x + server->input->width) % server->input->width;
    (*y1) = ((int)cpy_y + server->input->height) % server->input->height;
}

void sums_differ_from_zero(int sum_x, int sum_y, int *x1, int *y1)
{   
    if (abs(sum_x) > abs(sum_y))
        sum_x_superior_to_sum_y(sum_x, sum_y, x1, y1);
    else
        sum_y_superior_to_sum_x(sum_x, sum_y, x1, y1);
}