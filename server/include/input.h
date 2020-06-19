/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** input.h
*/

#ifndef INPUT_H_
#define INPUT_H_

typedef struct input_s {
    int port;
    int width;
    int height;
    char **teams;
    int client_nb;
    int freq;
} input_t;

typedef struct input_parser_s {
    int opt;
    char full_opt[2];
    int (*input_parse)(char **, input_t *);
} input_parser_t;

input_t *input_initialize(void);
char **input_initialize_teams(void);
int input_parse(int, char **, input_t *);
int input_check_opt(int, char **, input_t *);
int input_parse_port(char **, input_t *);
int input_parse_width(char **, input_t *);
int input_parse_height(char **, input_t *);
int input_parse_teams(char **, input_t *);
int input_parse_client_nb(char **, input_t *);
int input_parse_freq(char **, input_t *);
int input_find_opt(char **, char *);
void input_destroy_teams(char **);
void input_dump_data(input_t *);
int input_is_opt(char *);

#endif /* !INPUT_H_ */
