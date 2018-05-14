/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** different destroy function for projectile
*/

#include "game_info.h"
#include <stdlib.h>
#include "game_object.h"

void destroy_projectile(projectile_t *obj)
{
	game_obj_t *sp_proj = obj->game_obj;
	obj->prev->next = obj->next;
	obj->next->prev = obj->prev;

	destroy_game_obj(sp_proj);
	if (obj->rec != NULL)
		sfRectangleShape_destroy(obj->rec);
	free(obj);
}

void destroy_projectile_charact(projectile_t *obj, float *life)
{
	*life -= obj->dammage;
	destroy_projectile(obj);
}
