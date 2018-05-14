/*
** EPITECH PROJECT, 2018
** dante
** File description:
** _create map function
*/

#include <stdlib.h>

char *create_map_maze(int nb_colomn, int nb_line)
{
	char *map = malloc(sizeof(char) * (nb_colomn + 1) * (nb_line + 1));
	int actual_line = 1;

	if (map == NULL)
		return NULL;
	for (int i = 0; i < (nb_colomn) * nb_line + (1 * nb_line - 1); i++) {
		if (i == actual_line * nb_colomn + (1 * (actual_line - 1))) {
			actual_line++;
			map[i] = '\n';
		} else {
			map[i] = '*';
		}
	}
	map[(nb_colomn) * nb_line + (1 * nb_line - 1)] = '\0';
	return (map);
}
