/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "game_info.h"
#include "game_object.h"

void destroy_obj_drop(game_t * game)
{
	obj_drop_t *obj_drop = game->map->obj_drop;

	for (int i = 0; i < MAX_OBJ_IN_MAP; i++) {
		for (; i < MAX_OBJ_IN_MAP && obj_drop->objs_drop[i] == NULL;
			i++);
		if (i >= MAX_OBJ_IN_MAP)
			return;
		destroy_game_obj(obj_drop->objs_drop[i]);
		obj_drop->objs_drop[i] = NULL;
	}
}
