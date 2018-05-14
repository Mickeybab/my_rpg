/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include "game_object.h"
#include "inventory.h"

void add_obj_in_inventory(game_obj_t *obj, inventory_t *inventory, int id)
{
	char sprites[NB_OBJ][SIZE_MAX_PATH_G_O] = SPRITES_OBJ;
	int i = 0;
	sfVector2f pos = search_pos(inventory);
	sfIntRect rect = {0, 0, 512, 512};

	for (; inventory->obj_in[i] != NULL; i++);
	inventory->info->obj_in[i] = id;
	inventory->info->nb_stuff++;
	inventory->obj_in[i] = create_game_obj(sprites[id], pos, rect, id);
}
