/*
** EPITECH PROJECT, 2017
** File Name : test_get_word.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include "mysh.h"
#include "tools.h"
#include "my.h"

char *my_strdup(char *str)
{
	char *res = malloc(sizeof(char) * (my_strlen(str) + 1));

	my_strcpy(res, str);
	return (res);
}

Test(get_next_word, basic_test)
{
	char *got1 = my_strdup("lala         toto");
	char *got2 = my_strdup("     lala         toto      ");
	char *res;

	res = get_next_word(&got1);
	cr_assert_str_eq(res, "lala");
	free(res);
	res = get_next_word(&got2);
	cr_assert_str_eq(res, "lala");
	free(res);
}
