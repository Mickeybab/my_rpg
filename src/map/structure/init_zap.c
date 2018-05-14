/*
** EPITECH PROJECT, 2017
** my rpg
** File description:
** init_objet decor
*/

#include "obj_decor.h"

game_obj_decor_t *init_zap(game_obj_decor_t *obj, int id)
{
	sfIntRect rect = {0, 0, WIDTH_ZAP, HEIGHT_ZAP};
	sfVector2f move = {0, 100};

	obj->id = id;
	obj->rect = rect;
	obj->texture = sfTexture_createFromFile(PATH_ZAP, &obj->rect);
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, obj->texture, 0);
	obj->shape = init_shape_obj_decor(obj->pos, (int)WIDTH_ZAP,
		(int)HEIGHT_ZAP);
	obj->pos.x -= WIDTH_ZAP / 2;
	obj->pos.y -= HEIGHT_ZAP;
	sfSprite_setPosition(obj->sprite, obj->pos);
	return obj;
}