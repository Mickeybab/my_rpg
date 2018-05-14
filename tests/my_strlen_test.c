/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "mylib.h"

Test(my_strlen_1, null_string)
{
	int i = my_strlen(NULL);

	cr_assert_eq(i, 0);
}

Test(my_strlen_1, simple_string)
{
	int i = my_strlen("hey guys\n");

	cr_assert_eq(i, 9);
}
