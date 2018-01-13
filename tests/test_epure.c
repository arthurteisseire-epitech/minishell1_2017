/*
** EPITECH PROJECT, 2017
** File Name : test_epure.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include "mysh.h"
#include "tools.h"
#include "my.h"

Test(epure, basic_test)
{
	char got1[] = "lala         toto";
	char got2[] = "       lala         toto       ";

	epure_spaces(got1);
	epure_spaces(got2);
	cr_assert_str_eq(got1, "lala toto");
	cr_assert_str_eq(got2, "lala toto");
}
