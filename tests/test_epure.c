/*
** EPITECH PROJECT, 2017
** File Name : test_epure.c
** File description:
** by Arthur Teisseire
*/

#include <criterion/criterion.h>
#include "mysh.h"
#include "tools.h"

Test(epure, basic_test)
{
	char *got = "lala         toto";

	epure_spaces(got);
	cr_assert_str_eq(got, "lala toto");
}
