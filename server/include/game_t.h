/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** game_t.h
*/

#ifndef GAME_T_H_
#define GAME_T_H_

#include "server.h"

typedef struct {
    int inv[7];
    size_t lvl;
    size_t x;
    size_t y;
    char *team;
} game_t;

#endif /* !GAME_T_H_ */
