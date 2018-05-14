/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <stdbool.h>
#include <stdlib.h>
#include "mylib.h"

static bool check_display_variable(char *env)
{
	int i = 0;
	char display[] = "DISPLAY";

	while (env[i] == display[i] && display[i])
		i++;
	if (display[i] != '\0')
		return (false);
	return (true);
}

bool is_env_correct(char **env)
{
	int i = 0;
	bool display = false;

	while (env[i] != NULL && display == false) {
		display = check_display_variable(env[i]);
		i++;
	}
	if ((env[i] == NULL && display == false)) {
		my_putstr("Make sure the display variable is set\n");
		return (true);
	}
	return (false);
}
