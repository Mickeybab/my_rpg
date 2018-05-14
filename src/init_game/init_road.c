/*
** EPITECH PROJECT, 2018
** init struct
** File description:
** init structure function
*/

#include "map.h"

void make_road_village(map_t *map)
{
	sfVector2i p = {175, 170};
	int save = p.x;

	for (int i = 0 ; i < 43 ; i++, p.y++, p.x = save) {
		for (int j = 0 ; j < 23 ; j++, p.x++) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	make_plaza(map);
}

void make_road_start(map_t *map)
{
	sfVector2i p = {0, 4};

	for (int i = 0 ; i < 20 ; i++, p.x++, p.y = 4) {
		for (int j = 0 ; j < 3 ; j++, p.y++) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	for (int i = 0 ; i < 20 ; i++, p.x++, p.y -= 3) {
		for (int j = 0 ; j < 4 ; j++, p.y++) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	make_road_start2(map, p);
}

void make_road_start2(map_t *map, sfVector2i p)
{
	int save = p.y;

	for (int i = 0 ; i < 25 ; i++, p.x++, p.y = save) {
		for (int j = 0 ; j < 3 ; j++, p.y++) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	save = p.y;
	for (int i = 0 ; i < 3 ; i++, p.x++, p.y = save) {
		for (int j = 0 ; j < 11 ; j++, p.y++) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	make_road_start3(map, p);
}

void make_road_start3(map_t *map, sfVector2i p)
{
	int save = p.y + 26;

	p.y += 11;
	p.x -= 3;
	sfConvexShape_setTexture(map->tile[p.y][p.x + 1].shape1,
		map->texture[3], sfTrue);
	sfConvexShape_setTexture(map->tile[p.y][p.x + 1].shape2,
		map->texture[3], sfTrue);
	p.y += 15;
	for (int i = 0 ; i < 3 ; i++, p.x++, p.y = save) {
		for (int j = 0 ; j < 20 ; j++, p.y++) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[3], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[3], sfTrue);
		}
	}
	p.y += 20;
	p.x -= 3;
	make_road_start4(map, p);
}