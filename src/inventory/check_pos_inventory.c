/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "inventory.h"
#include "menu.h"
#include "game_info.h"

int check_pos_inventory(inventory_t *inv, sfVector2f pos)
{
	int j = 0;

	for (; j < NB_MAX_STUFF_INV; j++) {
		for (;inv->obj_in[j] == NULL &&
			j < NB_MAX_STUFF_INV; j++);
		if (j + 1 >= NB_MAX_STUFF_INV)
			break;
		if (inv->obj_in[j]->pos.x == pos.x &&
			inv->obj_in[j]->pos.y == pos.y)
			break;
		}
	return (j);
}

sfVector2f search_pos(inventory_t *inv)
{
	sfVector2f pos = {410, 680};
	int j = 0;

	for (int i = 0; i < NB_MAX_STUFF_INV; i++) {
		j = check_pos_inventory(inv, pos);
		if (j + 1 >= NB_MAX_STUFF_INV)
			break;
		pos.x += 93;
		if (pos.x >= 1500) {
			pos.x = 410;
			pos.y += 93;
		}
	}
	return (pos);
}
