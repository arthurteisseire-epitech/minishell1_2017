/*
** EPITECH PROJECT, 2017
** File Name : epure_spaces.c
** File description:
** by Arthur Teisseire
*/

#include "tools.h"

static void move(char **str, char **ptr)
{
	if (**ptr == ' ') {
		skip_first_spaces(ptr);
		if (**ptr != '\0') {
			**str = ' ';
			(*str)++;
		}
	} else {
		**str = **ptr;
		(*ptr)++;
		(*str)++;
	}
}

void epure_spaces(char *str)
{
	char *ptr = str;

	skip_first_spaces(&ptr);
	while (*ptr != '\0')
		move(&str, &ptr);
	*str = '\0';
}

void skip_first_spaces(char **str)
{
	while ((*str)[0] == ' ')
		(*str)++;
}
