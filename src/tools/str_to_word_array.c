/*
** EPITECH PROJECT, 2017
** File Name : str_to_word_array.c
** File description:
** by Arthur Teisseire
*/

#include "my.h"
#include "mysh.h"
#include "tools.h"

char *get_next_word(char **str)
{
	int len_word;
	char *word;

	skip_first_spaces(str);
	len_word = len_first_word(*str);
	word = malloc(sizeof(char) * (len_word + 1));
	if (word == NULL)
		return (NULL);
	(*str)[len_word] = '\0';
	word[len_word] = '\0';
	my_strcpy(word, *str);
	(*str)[len_word] = ' ';
	(*str)++;
	return (word);
}

int skip_first_spaces(char **str)
{
	int i = 0;

	while ((*str)[i] == ' ')
		i++;
	*str += i;
	return (i);
}

int len_first_word(char *str)
{
	int i = 0;

	while (str[i] != '\0' && str[i] != ' ')
		i++;
	return (i);
}
