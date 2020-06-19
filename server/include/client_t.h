/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** client_t.h
*/

#ifndef CLIENT_T_H_
#define CLIENT_T_H_

#include "game_t.h"

enum {
    MAX_BUFF = 1024
};

enum player_direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

enum {
    PLAYER,
    EGG
};

typedef struct client_s {
    char buffer[MAX_BUFF];
    int fd;
    int i;
    int j;
    bool log;
    bool status;
    float eat;
    game_t game;
    enum player_direction direction;
    void *cmd_list;
    struct client_s *next;
    struct client_s *prev;
} client_t;

/*
** FUNCTIONS TO ADD A NODE TO THE CLIENT LIST
*/

client_t *add_client_to_list(int fd);
client_t *add_last_client_to_list(int fd);
client_t *add_first_client_to_list(int fd);

/*
** FUNCTIONS TO DELETE A NODE FROM THE CLIENT LIST
*/

int delete_client_from_list(client_t *node);
void delete_from_list(client_t *node);
void delete_last_from_list(void);
void delete_first_from_list(void);

/*
** FUNCTIONS FOR DEBUGGING
*/

void display_clients();

#endif /* !CLIENT_T_H_ */