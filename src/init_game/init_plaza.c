/*
** EPITECH PROJECT, 2018
** init struct
** File description:
** init structure function
*/

#include "map.h"

void make_plaza(map_t *map)
{
	sfVector2i p = {125, 49};
	int temp = p.x;

	for (int i = 0 ; i < 9 ; i++, p.y++, p.x = temp) {
		for (int j = 0 ; j < 9 ; j++, p.x++) {
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape1,
				map->texture[5], sfTrue);
			sfConvexShape_setTexture(map->tile[p.y][p.x].shape2,
				map->texture[5], sfTrue);
		}
	}
	make_plaza2(map);
}

void make_plaza2(map_t *map)
{
	for (int i = 0 ; i < 7 ; i++) {
		sfConvexShape_setTexture(map->tile[48][i + 126].shape1,
			map->texture[5], sfTrue);
		sfConvexShape_setTexture(map->tile[48][i + 126].shape2,
			map->texture[5], sfTrue);
		sfConvexShape_setTexture(map->tile[58][i + 126].shape1,
			map->texture[5], sfTrue);
		sfConvexShape_setTexture(map->tile[58][i + 126].shape2,
			map->texture[5], sfTrue);
	}
	for (int i = 0 ; i < 7 ; i++) {
		sfConvexShape_setTexture(map->tile[50 + i][124].shape1,
			map->texture[5], sfTrue);
		sfConvexShape_setTexture(map->tile[50 + i][124].shape2,
			map->texture[5], sfTrue);
		sfConvexShape_setTexture(map->tile[50 + i][134].shape1,
			map->texture[5], sfTrue);
		sfConvexShape_setTexture(map->tile[50 + i][134].shape2,
			map->texture[5], sfTrue);
	}
}