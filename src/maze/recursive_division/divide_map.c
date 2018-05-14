/*
** EPITECH PROJECT, 2018
** dante
** File description:
** divide function
*/

#include "recursive_division.h"

void divide_up_left(all_t *info, vector2i_t origin, vector2i_t wall_pos)
{
	vector2i_t new_size;

	new_size.x = wall_pos.x - origin.x;
	new_size.y = wall_pos.y - origin.y;
	divide(info, origin, new_size);
}

void divide_up_right(all_t *info, vector2i_t origin, vector2i_t size
	, vector2i_t wall_pos)
{
	vector2i_t new_size;
	vector2i_t new_origin;

	new_origin.x = wall_pos.x + 1;
	new_origin.y = origin.y;
	new_size.x = size.x - wall_pos.x + origin.x - 1;
	new_size.y = wall_pos.y - origin.y;
	divide(info, new_origin, new_size);
}

void divide_down_left(all_t *info, vector2i_t origin, vector2i_t size
	, vector2i_t wall_pos)
{
	vector2i_t new_size;
	vector2i_t new_origin;

	new_origin.x = origin.x;
	new_origin.y = wall_pos.y + 1;
	new_size.x = wall_pos.x - origin.x;
	new_size.y = size.y - wall_pos.y + origin.y - 1;
	divide(info, new_origin, new_size);
}

void divide_down_right(all_t *info, vector2i_t origin, vector2i_t size
	, vector2i_t wall_pos)
{
	vector2i_t new_size;
	vector2i_t new_origin;

	new_origin.x = wall_pos.x + 1;
	new_origin.y = wall_pos.y + 1;
	new_size.x = size.x - wall_pos.x + origin.x - 1;
	new_size.y = size.y - wall_pos.y + origin.y - 1;
	divide(info, new_origin, new_size);
}

void divide(all_t *info, vector2i_t origin, vector2i_t size)
{
	vector2i_t wall_pos;

	if (size.x < 5 || size.y < 5)
		return;
	wall_pos = create_wall(info, origin, size);
	divide_up_left(info, origin, wall_pos);
	divide_down_right(info, origin, size, wall_pos);
	divide_down_left(info, origin, size, wall_pos);
	divide_up_right(info, origin, size, wall_pos);
}
