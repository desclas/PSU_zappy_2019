/*
** EPITECH PROJECT, 2019
** PSU_zappy_2019
** File description:
** main.c
*/

#include "server.h"

server_t *server = NULL;
const verif_f verif_func[9] = {is_cmd_left,
                    is_cmd_right,
                    is_cmd_broadcast,
                    is_cmd_look,
                    is_cmd_take_object,
                    is_cmd_set_object,
                    is_cmd_forward,
                    is_cmd_inventory,
                    is_cmd_false};

const char g_items[7][10] = { "food",
            "linemate",
            "deraumere",
            "sibur",
            "mendiane",
            "phiras",
            "thystame" };

static void server_end(server_t *srv)
{
    client_t *tmp = srv->tail;

    for (size_t i = 0; srv->input->teams[i] != NULL; i++)
        free(srv->input->teams[i]);
    free(srv->input->teams);
    free(srv->input);
    close(srv->host->fd);
    free(srv->host);
    while (tmp != NULL) {
        close(tmp->fd);
        tmp = tmp->prev;
        if (tmp != NULL)
            free(tmp->next);
    }
    free(srv->client);
    free(srv);
}

static void signal_handler(UNUSED int sig)
{
    if (server == NULL)
        return;
    server_end(server);
    exit(0);
}

static void setup_signals(void)
{
    if (signal(SIGINT, &signal_handler) == SIG_ERR)
        perror("SIGINT Setup");
    if (signal(SIGTERM, &signal_handler) == SIG_ERR)
        perror("SIGINT Setup");
    if (signal(SIGQUIT, &signal_handler) == SIG_ERR)
        perror("SIGINT Setup");
}

int main(int ac, char **av)
{
    setup_signals();
    init_server(ac, av);
    input_dump_data(server->input);
    server->map = map_create(server->input->height, server->input->width);
    printf("Port : %d\n", server->input->port);
    run_server();
    map_destroy(server->map);
    return (0);
}