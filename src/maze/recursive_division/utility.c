/*
** EPITECH PROJECT, 2018
** dante
** File description:
** utility for division recursive algorithm
*/

#include "recursive_division.h"

int calcul_coord(vector2i_t max, int i, int j)
{
	return (j * (max.x + 1) + i);
}

int pick_random_number(int minimum, int maximum)
{
	int nb = rand();

	if (minimum - maximum == 0 || nb == 0)
		return (minimum);
	return (rand() % (maximum - minimum) + minimum);
}
