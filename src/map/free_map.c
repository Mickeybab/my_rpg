/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>

void free_map(float **map)
{
	if (!map)
		return;
	for (int i = 0; map[i] ; i++)
		free(map[i]);
	free(map);
}
