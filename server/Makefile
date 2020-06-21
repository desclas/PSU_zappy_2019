##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	main.c										\
		src/clock/clock.c							\
		src/clock/get_day_time_in_microseconds.c	\
		src/clock/check_cmd_deadline.c				\
		src/circular_buffer.c						\
		src/split.c									\
		src/input/input_initialize.c				\
		src/input/input_parse.c						\
		src/input/input_parse_client_nb.c			\
		src/input/input_parse_freq.c				\
		src/input/input_parse_height.c				\
		src/input/input_parse_port.c				\
		src/input/input_parse_teams.c				\
		src/input/input_parse_width.c				\
		src/input/input_find_opt.c					\
		src/input/input_destroy_teams.c				\
		src/input/input_dump_data.c					\
		src/error/check_number.c					\
		src/error/error_print.c						\
		src/server_init/init_server.c				\
		src/server_init/handle_select.c 			\
		src/server_init/run_server.c				\
		src/client_list/add_client_to_list.c		\
		src/client_list/delete_client_from_list.c	\
		src/cmds/verif_funcs/verif_movement_funcs.c	\
		src/cmds/verif_funcs/verif_funcs.c			\
		src/cmds/verif_funcs/verif_funcs_2.c		\
		src/cmds/inventory.c						\
		src/cmds/take_object.c						\
		src/cmds/set_object.c						\
		src/cmds/movement_cmds.c					\
		src/cmds/false_cmd.c						\
		src/cmds/connect_nbr.c						\
		src/cmds/incantation.c						\
		src/cmds/cmd_list/add_cmd_to_list.c			\
		src/cmds/cmd_list/delete_cmd_from_list.c	\
		src/cmds/broadcast/broadcast.c				\
		src/cmds/broadcast/broadcast_cases.c		\
		src/cmds/broadcast/find_tile.c				\
		src/cmds/broadcast/is_smallest_distance_1.c	\
		src/cmds/broadcast/is_smallest_distance_2.c	\
		src/cmds/broadcast/get_tile.c				\
		src/cmds/broadcast/get_tile_in_x.c			\
		src/cmds/broadcast/get_tile_in_y.c			\
		src/cmds/look/look.c						\
		src/map/map_allocate_resources.c			\
		src/map/map_create.c						\
		src/map/map_destroy_resources.c				\
		src/map/map_destroy.c						\
		src/map/map_increase_resources.c			\
		src/map/map_randomize_resource.c			\
		src/player_on_map/place_player_on_map.c		\
		src/player_on_map/add_player_to_map.c		\
		src/player_on_map/delete_player_from_map.c	\
		src/server_init/run_server2.c

OBJ	=	$(SRC:.c=.o)

NAME	=	../zappy_server

DEBUG =

ifeq ($(DEBUG), yes)
	CFLAGS	+=	-W -Wall -Werror -Wextra -Iinclude -g -g3 -lm
else
	CFLAGS	+=	-W -Wall -Werror -Wextra -Iinclude -lm
endif

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	@find -name "*~" -delete
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
