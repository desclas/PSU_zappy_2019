/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** commands.h
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

typedef void (*commands_f)(client_t *client, char *cmd);
typedef int (*verif_f)(client_t *, char *);

const verif_f verif_func[9];

/*
** STRUCTURE COMMAND
*/

typedef struct commands_s {
    bool init;
    char *cmd;
    double time;
    double started_time;
    commands_f cmd_func;
    struct commands_s *next;
} commands_t;

typedef int (*distances_f)(float, float, int *, int *);

/*
** BROADCAST FUNCTIONS
*/

int get_tile_in_y(client_t *receiver, int x, int y);
int get_tile_in_x(client_t *receiver, int x, int y);
int get_tile(client_t *receiver, int x, int y);
int find_tile(client_t *emitter, client_t *receiver);
void sum_x_equals_zero(int sum_y, int *x1, int *y1);
void sum_y_equals_zero(int sum_y, int *x1, int *y1);
void sums_differ_from_zero(int sum_x, int sum_y, int *x1, int *y1);
int is_smallest_distance_1(float distance_to_compare, float distance, int *x1,
                            int *y1);
int is_smallest_distance_2(float distance_to_compare, float distance, int *x1,
                            int *y1);
int is_smallest_distance_3(float distance_to_compare, float distance, int *x1,
                            int *y1);
int is_smallest_distance_4(float distance_to_compare, float distance, int *x1,
                            int *y1);
int is_smallest_distance_5(float distance_to_compare, float distance, int *x1,
                            int *y1);
distances_f *get_is_smallest_distance_tab();

/*
** COMMANDS
*/

void turn_left(client_t *client, char *cmd);
void turn_right(client_t *client, char *cmd);
void go_forward(client_t *client, char *cmd);
void connect_nbr(client_t *client, char *cmd);
void broadcast(client_t *client, char *cmd);
void look(client_t *client, char *cmd);
void take_object(client_t *client, char *cmd);
void set_object(client_t *cli, char *cmd);
void false_cmd(client_t *client, char *cmd);
void incantation(client_t *client, char *cmd);
void inventory(client_t *client, char *cmd);

/*
** FUNCTIONS OF VERIFICATION
*/

void verif_funcs(client_t *client, char *cmd);
int is_cmd_false(client_t *client, char *cmd);
int is_cmd_left(client_t *client, char *cmd);
int is_cmd_right(client_t *client, char *cmd);
int is_cmd_broadcast(client_t *client, char *cmd);
int is_cmd_look(client_t *client, char *cmd);
int is_cmd_take_object(client_t *client, char *cmd);
int is_cmd_set_object(client_t *client, char *cmd);
int is_cmd_forward(client_t *client, char *cmd);
int is_cmd_incantation(client_t *client, char *cmd);
int is_cmd_inventory(client_t *client, char *cmd);

/*
** FUNCTIONS TO MANIPULATE THE COMMAND LIST
*/

int get_cmd_list_size(commands_t *cmd_list);
int add_cmd_to_list(client_t *client, char *cmd, commands_f func, int cmd_time);
commands_t *delete_first_cmd_from_list(commands_t *cmd_list);

#endif /* !COMMANDS_H_ */