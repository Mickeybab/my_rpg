/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "game_info.h"
#include "game_object.h"
#include <stdlib.h>

int rand_a_b(int a, int b)
{
	return(rand() % (b-a) + a);
}

int choose_drop(void)
{
	int rare = rand_a_b(0, 11);
	int obj = rand_a_b(0, 6);
	int rare_1[6] = RARE_1;
	int rare_2[6] = RARE_2;
	int rare_3[6] = RARE_3;

	if (rare <= 5) {
		return (rare_1[obj] - 1);
	} else if (rare <= 9) {
		return (rare_2[obj] - 1);
	} else {
		return (rare_3[obj] - 1);
	}
}
