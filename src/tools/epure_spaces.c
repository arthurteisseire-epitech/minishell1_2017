/*
** EPITECH PROJECT, 2017
** File Name : epure_spaces.c
** File description:
** by Arthur Teisseire
*/

#include "tools.h"

char *epure_spaces(char *str)
{
	char *ptr = str;

	while (*str != '\0') {
		if (*ptr == ' ') {
			skip_first_spaces(&ptr);
			*str = ' ';
			str++;
		}
		*str = *ptr;
		ptr++;
		str++;
	}
	*str = '\0';
	return (str);
}

void skip_first_spaces(char **str)
{
	while ((*str)[0] == ' ')
		(*str)++;
}
