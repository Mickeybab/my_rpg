/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "game_info.h"
#include "game_object.h"

void init_drop(map_t *map)
{
	obj_drop_t *obj_drop = map->obj_drop;

	obj_drop = malloc(sizeof(obj_drop_t));
	obj_drop->nb_obj_drop = 0;
	obj_drop->objs_drop =
	malloc(sizeof(game_obj_t *) * MAX_OBJ_IN_MAP);
	for (int i = 0; i < MAX_OBJ_IN_MAP; i++)
		obj_drop->objs_drop[i] = NULL;
	map->obj_drop = obj_drop;
}
