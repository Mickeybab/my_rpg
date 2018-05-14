/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** destroy enemy structure
*/

#include "enemy.h"
#include <stdlib.h>
#include "game_object.h"

void destroy_enemy(enemy_t *it)
{
	game_obj_t *sp_enemy = it->anim;

	destroy_game_obj(sp_enemy);
	sfRectangleShape_destroy(it->shape);
	sfClock_destroy(it->clock);
	it->prev->next = it->next;
	it->next->prev = it->prev;
	free(it);
}
