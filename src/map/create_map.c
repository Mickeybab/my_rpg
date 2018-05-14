/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "map.h"

float **create_map(int line, int colum)
{
	float **map = malloc(sizeof(float *) * (line + 1));

	if (!map)
		return NULL;
	map[line] = NULL;
	for (int i = 0 ; i < line ; i++) {
		map[i] = malloc(sizeof(float) * (colum + 1));
		if (!map[i]) {
			free_map(map);
			return NULL;
		}
		for (int j = 0 ; j < colum ; map[i][j] = 0.2, j++);
		map[i][colum] = REF_MAP;
	}
	return map;
}
