/*
** EPITECH PROJECT, 2017
** File Name : test_split.c
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

Test(split, get_next_word)
{
	char *got1 = my_strdup("lala         toto");
	char *got2 = my_strdup("     lala         toto      ");
	char *res;

	res = get_next_word(&got1, ' ');
	cr_assert_str_eq(res, "lala");
	get_next_word(&got2, ' ');
	res = get_next_word(&got2, ' ');
	cr_assert_str_eq(res, "toto");
	res = get_next_word(&got2, ' ');
	cr_assert_eq(res, NULL);
}

Test(split, skip_first_flags)
{
	char *got = my_strdup("      lala ");
	char *expected = "lala ";

	skip_first_flags(&got, ' ');
	cr_assert_str_eq(got, expected);
}

Test(split, count_words)
{
	cr_assert_eq(count_words("un deux trois", ' '), 3);
	cr_assert_eq(count_words("  un deux trois ", ' '), 3);
}

Test(split, split)
{
	char *got = "   tata    toto   ";
	char *expected[3] = {"tata", "toto", NULL};
	char **res = split(got, ' ');
	int i = 0;
	
	while (res[i] != NULL)
		cr_assert_str_eq(res[i], expected[i]);
}
