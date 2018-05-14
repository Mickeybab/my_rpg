/*
** EPITECH PROJECT, 2018
** init struct
** File description:
** init structure function
*/

#include <stdlib.h>
#include "map.h"
#include "obj_decor.h"

sfVector2f define_max(float **map_3d)
{
	sfVector2f result;
	int i = 0;
	int j = 0;

	for (; map_3d[j]; j++)
		for (i = 0; !compare_float(map_3d[j][i], REF_MAP, 0.0001);
		i++);
	result.x = i;
	result.y = j;
	return (result);
}

void full_up_map(map_t *map)
{
	tile_t *new;
	sfVector2f pos_map;

	for (int j = 0; j < map->max.y - 1; j++) {
		for (int i = 0; i < map->max.x - 1; i++) {
			new = &map->tile[j][i];
			new = choose_texture(new, map, j, i);
			pos_map.x = i;
			pos_map.y = j;
			map->tile[j][i].middle = get_real_pos(map, pos_map);
		}
	}
	make_sand(map);
	make_road(map);
}

map_t *init_map(float **map_3d)
{
	map_t *new = malloc(sizeof(map_t));

	if (new != NULL) {
		new->map3d = map_3d;
		new->max = define_max(map_3d);
		new->map2d = create_2d_map(map_3d, new->max);
		new->water = create_2d_map(create_map(new->max.y, new->max.x)
						, new->max);
		new->map = create_convex_map(new->water, new->max);
		new->tile = create_tile_map(new->map2d, new->max, map_3d);
		new->pos.x = 600;
		new->pos.y = 100;
		new->texture = init_texture();
		init_drop(new);
	}
	return (new);
}

tile_t create_tile(sfVector2f **points, int y, int x, float **map3d)
{
	tile_t new;
	sfVector2f point[4] = {points[y][x], points[y + 1][x],
				points[y + 1][x + 1], points[y][x + 1]};
	float point3d[4] = {map3d[y][x], map3d[y + 1][x],
				map3d[y + 1][x + 1], map3d[y][x + 1]};

	new.shape1 = sfConvexShape_create();
	new.shape2 = sfConvexShape_create();
	choose_triangle(point, new.shape1, new.shape2, point3d);
	new.dispo = true;
	return (new);
}
