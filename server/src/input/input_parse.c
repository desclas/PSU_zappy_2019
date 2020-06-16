/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** input_parse
*/

#include "server.h"

const input_parser_t parser[7] =
{
	{ 'p', "-p", input_parse_port  },
	{ 'x', "-x", input_parse_width },
	{ 'y', "-y", input_parse_height },
	{ 'n', "-n", input_parse_teams },
	{ 'c', "-c", input_parse_client_nb },
	{ 'f', "-f", input_parse_freq }
};

/*!
** @brief check if it's an option
**
** @param str to check
** @return int sucess 0 error 1
*/
int	input_is_opt(char *str)
{
	int it = 0;

	while (it < 6) {
		if (strcmp(parser[it].full_opt, str) == 0)
			return (0);
		it++;
	}
	return (1);
}

/*!
** @brief check option
**
** @param opt option
** @param av argument
** @param input struct of input
** @return int sucess 0 error 84
*/
int	input_check_opt(int opt, char **av, input_t *input)
{
	int	it = 0;

	printf("OPT: %c\n", (char)opt);
	while	(it < 6) {
		if (opt == parser[it].opt)
			return (parser[it].input_parse(av, input));
		it++;
	}
	return (error_print_message("Opt error occurred. Leaving.\n", 84));
}

/*!
** @brief parse input
**
** @param ac size of arguments list
** @param av argument list
** @param input struct of input
** @return int sucess 0 error 84
*/
int	input_parse(int ac, char **av, input_t *input)
{
	int	opt;

	while ((opt = getopt(ac, av, "p:x:y:n:c:f:")) != -1) {
		if (input_check_opt(opt, av, input) == 84) {
			return (error_print_message("Invalid arguments.", 84));
		}
	}
	return (0);
}
