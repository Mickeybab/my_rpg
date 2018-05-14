/*
** EPITECH PROJECT, 2018
** init struct
** File description:
** init structure function
*/

#include "map.h"

void make_road_start4(map_t *map, sfVector2i p)
{
	int save = p.x - 9;

	p.x -= 9;
	for (int i = 0 ; i < 21 ; i++, p.y++, p.x = save) {
		for (int j = 0 ; j < 21 ; j++, p.x++) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	make_road_to_village(map);
}

void make_road_to_village(map_t *map)
{
	sfVector2i p = {185, 169};
	int save = p.y;

	for (int i = 0 ; i < 60 ; i++, p.x--, p.y = save) {
		for (int j = 0 ; j < 3 ; j++, p.y--) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	for (int i = 0 ; i < 58 ; i++, p.x--, p.y += 3) {
		for (int j = 0 ; j < 4 ; j++, p.y--) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	make_road_to_village2(map, p);
}

void make_road_to_village2(map_t *map, sfVector2i p)
{
	int save = p.x;

	for (int i = 0 ; i < 21 ; i++, p.y--, p.x = save) {
		for (int j = 0 ; j < 3 ; j++, p.x--) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
}
