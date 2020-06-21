/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** check_cmd_deadline.c
*/

#include "server.h"

int check_cmd_deadline(double started_time, double cmd_time)
{
    double current_time = get_day_time_in_microseconds();

    if (current_time - started_time >= cmd_time) {
        return (0);
    }
    return (-1);
}

void get_timeout(void)
{
    double time = __INT32_MAX__;
    double current_time = get_day_time_in_microseconds();
    commands_t *ctmp;

    for (client_t *tmp = server->client; tmp != NULL; tmp = tmp->next) {
        ctmp = tmp->cmd_list;
        if (ctmp != NULL && ctmp->init && (ctmp->time -
                (current_time - ctmp->started_time)) > 0 && (ctmp->time -
                (current_time - ctmp->started_time)) < time)
            time = ctmp->time - (current_time - ctmp->started_time);
        if (tmp->eat != -1 && (FOOD_FREQ - (current_time - tmp->eat)) > 0 &&
                (FOOD_FREQ - (current_time - tmp->eat)) < time)
            time = FOOD_FREQ - (current_time - tmp->eat);
    }
    server->timeout.tv_sec = ((time == __INT32_MAX__) ? 0 : (time / 1000000));
    server->timeout.tv_usec = ((time == __INT32_MAX__) ? 0 :
        (time - (((int)time / 1000000) * 1000000)));
}