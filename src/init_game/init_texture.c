/*
** EPITECH PROJECT, 2018
** init struct
** File description:
** init structure function
*/

#include <stdlib.h>
#include "map.h"

sfTexture **init_texture(void)
{
	sfTexture **texture = malloc(sizeof(sfTexture *) * 7);

	texture[0] = sfTexture_createFromFile("./resources/texture/grass.png",
		NULL);
	texture[3] = sfTexture_createFromFile("./resources/decor/road.jpg",
		NULL);
	texture[1] = sfTexture_createFromFile("./resources/texture/light.jpg",
		NULL);
	texture[2] = sfTexture_createFromFile("./resources/texture/dark.jpg",
		NULL);
	texture[4] = sfTexture_createFromFile("./resources/texture/sable.jpg",
		NULL);
	texture[5] = sfTexture_createFromFile("./resources/texture/beton.png",
		NULL);
	texture[6] = NULL;
	return texture;
}

tile_t *choose_texture(tile_t *new, map_t *map, int y, int x)
{
	int ang = 0;

	if (map->map3d[y + 1][x] < map->map3d[y][x + 1] - 0.1)
		ang = 1;
	else if (map->map3d[y + 1][x] > map->map3d[y][x + 1] + 0.1)
		ang = 2;
	sfConvexShape_setTexture(new->shape1, switch_texture(map->texture, ang)
		, sfTrue);
	sfConvexShape_setTexture(new->shape2, switch_texture(map->texture, ang)
		, sfTrue);
	return new;
}

sfTexture *switch_texture(sfTexture **texture, int angle)
{
	switch (angle) {
		case 0 : return texture[1];
		case 1 : return texture[0];
		case 2 : return texture[2];
	}
}

void make_road(map_t *map)
{
	make_road_village(map);
	make_road_start(map);
}

void make_sand(map_t *map)
{
	for (int y = 0 ; y < map->max.y - 1 ; y++) {
		for (int x = 0 ; x < map->max.x - 1 ; x++) {
			(map->map3d[y][x] < 0.55) ?
			(sfConvexShape_setTexture(map->tile[y][x].shape1,
			map->texture[4], sfTrue)) : (map = map);
			(map->map3d[y][x] < 0.55) ?
			(sfConvexShape_setTexture(map->tile[y][x].shape2,
			map->texture[4], sfTrue)) : (map = map);
		}
	}
	for (int y = 0 ; y < map->max.y - 1 ; y++)
		for (int x = 0 ; x < map->max.x - 1 ; x++) {
			(map->map3d[y][x] < 0.3) ?
			(map->tile[y][x].dispo = false) : (0);
		}
}
