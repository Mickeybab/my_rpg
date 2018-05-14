/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** init objets decor
*/

#include "map.h"
#include "obj_decor.h"

game_obj_decor_t *init_house(game_obj_decor_t *obj, int id)
{
	sfIntRect rect = {0, 0, width_house(id), height_house(id)};

	obj->id = id;
	obj->rect = rect;
	obj->texture = sfTexture_createFromFile(path_house(id), &obj->rect);
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, obj->texture, 0);
	obj->shape = init_shape_obj_decor(obj->pos, (int)width_house(id),
		(int)height_house(id));
	obj->pos.x -= width_house(id) / 2;
	obj->pos.y -= height_house(id);
	sfSprite_setPosition(obj->sprite, obj->pos);
	return obj;
}

char *path_house(int id)
{
	switch (id) {
		case 5 : return PATH_HOUSE_1;
		case 6 : return PATH_HOUSE_2;
		case 7 : return PATH_HOUSE_3;
		case 8 : return PATH_HOUSE_4;
	}
}

int width_house(int id)
{
	switch (id) {
		case 5 : return WIDTH_HOUSE_1;
		case 6 : return WIDTH_HOUSE_2;
		case 7 : return WIDTH_HOUSE_3;
		case 8 : return WIDTH_HOUSE_4;
	}
}

int height_house(int id)
{
	switch (id) {
		case 5 : return HEIGHT_HOUSE_1;
		case 6 : return HEIGHT_HOUSE_2;
		case 7 : return HEIGHT_HOUSE_3;
		case 8 : return HEIGHT_HOUSE_4;
	}
}

void block_house(map_t *map, sfVector2f pos_float, int size)
{
	sfVector2i pos;
	int temp = (int)pos_float.x;

	pos.x = (int)pos_float.x;
	pos.y = (int)pos_float.y;
	for (int i = 0 ; i < size ; i++, pos.y--, pos.x = temp) {
		for (int j = 0 ; j < size ; j++, pos.x--)
			map->tile[pos.y][pos.x].dispo = false;
	}
}