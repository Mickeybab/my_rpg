/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include <stdbool.h>
#include "flag_program.h"
#include "mylib.h"

bool is_verbose(int argc, char **argv)
{
	char flag[2][11] = {SHORT_VERBOSE_FLAG, LONG_VERBOSE_FLAG};

	if (argc == 1)
		return (false);
	for (int i = 1; i < argc; i++) {
		if (my_strcmp(flag[0], argv[i]) || my_strcmp(flag[1], argv[i]))
			return (true);
	}
	return (false);
}
