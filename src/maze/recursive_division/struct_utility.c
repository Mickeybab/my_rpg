/*
** EPITECH PROJECT, 2018
** dante
** File description:
** init and destroy structure
*/

#include "recursive_division.h"

all_t *prepare_algorithm(int size_x, int size_y)
{
	all_t *new = malloc(sizeof(all_t));

	if (new != NULL) {
		new->map = create_map_maze(size_x, size_y);
		new->max.x = size_x;
		new->max.y = size_y;
	}
	return (new);
}

void destroy_all(all_t *info)
{
	if (info != NULL && info->map != NULL) {
		free(info);
	}
}
