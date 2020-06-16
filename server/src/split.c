/*
** EPITECH PROJECT, 2018
** split.c
** File description:
** split.c
*/

#include "server.h"

static int	is_i_in_str(char c, char *str)
{
	int	i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == c)
			return (0);
	return (-1);
}

static int	count_words(char *str, char *sep)
{
	int	i = 0;
	int	mode = 0;

	for (int y = 0; str[y] != '\0'; y++) {
		if (is_i_in_str(str[y], sep) != 0 && mode == 0) {
			mode = 1;
			i++;
		}
		else if (is_i_in_str(str[y], sep) == 0)
			mode = 0;
	}
	return (i);
}

static char	*inc_it(char *str, char *sep, int *i, char *tab)
{
	int	y = 0;

	for (; str[(*i)] != '\0'
			&& is_i_in_str(str[(*i)], sep) == 0; (*i) += 1);
	str += (*i);
	for (; str[y] != '\0'
			&& is_i_in_str(str[y], sep) != 0; y++);
	tab = malloc(sizeof(char) * (y + 1));
	if (tab == NULL)
		return (NULL);
	for (y = 0; str[y] != '\0'
			&& is_i_in_str(str[y], sep) != 0; y++) {
		tab[y] = str[y];
	}
	tab[y] = '\0';
	(*i) += y;
	return (tab);
}

char	**split(char *str, char *sep)
{
	int	len = count_words(str, sep);
	char	**tab = malloc(sizeof(char *) * (len + 1));
	int	y = 0;
	int	i = 0;

	if (tab == NULL)
		return (NULL);
	for (; y < len; y++) {
		tab[y] = inc_it(str, sep, &i, tab[y]);
		if (tab[y] == NULL)
			return (NULL);
	}
	tab[len] = NULL;
	return (tab);
}
