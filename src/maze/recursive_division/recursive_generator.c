/*
** EPITECH PROJECT, 2018
** dante
** File description:
** recursive division algorithm
*/

#include "recursive_division.h"
#include <time.h>

void check_end(all_t *info)
{
	int counter_y = 0;
	int counter_x = 0;

	if (info->map[calcul_coord(
		info->max, info->max.x - 1, info->max.y - 2)] == 'X')
		counter_y = 1;
	if (info->map[calcul_coord(
		info->max, info->max.x - 2, info->max.y - 1)] == 'X')
		counter_x = 1;
	if (counter_x == 1 && counter_y == 1)
		info->map[calcul_coord(
			info->max, info->max.x - 2, info->max.y - 1)] = '*';
	if (counter_x == 0 && counter_y == 0)
		info->map[calcul_coord(
			info->max, info->max.x - 2, info->max.y - 1)] = 'X';
	info->map[calcul_coord(
		info->max, info->max.x - 1, info->max.y - 1)] = '*';
}

char *recursive_generator(int nb_colomn, int nb_line)
{
	all_t *info = prepare_algorithm(nb_colomn, nb_line);
	vector2i_t origin = { 0, 0};
	char *map;

	if (nb_colomn <= 0 || nb_line <= 0)
		return (NULL);
	divide(info, origin, info->max);
	if (nb_colomn % 2 == 0 || nb_line % 2 == 0)
		check_end(info);
	map = info->map;
	destroy_all(info);
	return (map);
}
