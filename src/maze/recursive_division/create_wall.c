/*
** EPITECH PROJECT, 2018
** dante
** File description:
** create walls function
*/

#include "recursive_division.h"

int get_vertical_divsion(vector2i_t origin, vector2i_t size)
{
	int result = pick_random_number(origin.x / 2, (size.x + origin.x) / 2);

	return (result * 2 + 1);
}

int get_horizontal_divsion(vector2i_t origin, vector2i_t size)
{
	int result = pick_random_number(origin.y / 2, (size.y + origin.y) / 2);

	return (result * 2 + 1);
}

wall_t init_wall(vector2i_t origin, vector2i_t size)
{
	wall_t wall;

	wall.cut.x = get_vertical_divsion(origin, size);
	wall.cut.y = get_horizontal_divsion(origin, size);
	wall.door_y = 2 * pick_random_number(
		origin.y / 2, (size.y + origin.y - 1) / 2);
	wall.door_x1 = 2 * pick_random_number(
		origin.x / 2, (wall.cut.x - 1) / 2);
	wall.door_x2 = 2 * pick_random_number(
		(wall.cut.x + 1) / 2, (size.x + origin.x - 1) / 2);
	return (wall);
}
vector2i_t create_wall(all_t *info, vector2i_t origin, vector2i_t size)
{
	wall_t wall = init_wall(origin, size);

	for (int i = origin.y; i < size.y + origin.y; i++) {
		if (i == wall.door_y) {
			continue;
		}
		info->map[calcul_coord(info->max, wall.cut.x, i)] = 'X';
	}
	for (int i = origin.x; i < size.x + origin.x; i++) {
		if (i == wall.door_x1 || i == wall.door_x2) {
			continue;
		}
		info->map[calcul_coord(info->max, i, wall.cut.y)] = 'X';
	}
	return (wall.cut);
}
