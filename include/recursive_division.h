/*
** EPITECH PROJECT, 2018
** dante
** File description:
** recursive division prototype
*/

#ifndef RECURSIVE_DIVISON_H_
#define RECURSIVE_DIVISON_H_
#include <stdlib.h>
#include <stdio.h>
#include "vector.h"

typedef struct all_s {
	char *map;
	vector2i_t max;
	int *horizontal;
	int *vertical;
}all_t;

typedef struct wall_s {
	int door_y;
	int door_x1;
	int door_x2;
	vector2i_t cut;
}wall_t;

void analyse_args(int ac, char **av);
char *recursive_generator(int , int);
char *create_map_maze(int, int);
int write_maze(char *, int);
all_t *prepare_algorithm(int size_x, int size_y);
void destroy_all(all_t *info);
void divide(all_t *info, vector2i_t origin, vector2i_t size);
int pick_random_number(int minimum, int maximum);
vector2i_t create_wall(all_t *info, vector2i_t origin, vector2i_t size);
int calcul_coord(vector2i_t max, int i, int j);

#endif /* end of include guard: RECURSIVE_DIVISON_H_ */
