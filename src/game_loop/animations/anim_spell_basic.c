/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include "game_info.h"
#include "game_object.h"

sfIntRect change_direction_spell(projectile_t *it, game_obj_t *sp_proj)
{
	if (it->mouvement.x <= 5 &&
		it->mouvement.x >= -5 && it->mouvement.y < 0)
		sp_proj->rect.top = 64 * 2;
	if (it->mouvement.x <= 5 &&
		it->mouvement.x >= -5 && it->mouvement.y > 0)
		sp_proj->rect.top = 64 * 6;
	if (it->mouvement.x > 0 && it->mouvement.y <= 5 &&
		it->mouvement.y >= -5)
		sp_proj->rect.top = 64 * 4;
	if (it->mouvement.x < 0 && it->mouvement.y <= 5 &&
		it->mouvement.y >= -5)
		sp_proj->rect.top = 0;
	return (sp_proj->rect);
}

void anim_basic_spell(game_t *game)
{
	game_obj_t *sp_proj;

	for (projectile_t *it = game->projectile->next; it != game->projectile
	; it = it->next) {
		sp_proj = it->game_obj;
		sp_proj->rect = move_rect(sp_proj->rect, 64, 64 * 7);
		if (it->mouvement.x > 0 && it->mouvement.y > 0)
			sp_proj->rect.top = 64 * 5;
		if (it->mouvement.x < 0 && it->mouvement.y > 0)
			sp_proj->rect.top = 64 * 7;
		if (it->mouvement.x > 0 && it->mouvement.y < 0)
			sp_proj->rect.top = 64 * 3;
		if (it->mouvement.x < 0 && it->mouvement.y < 0)
			sp_proj->rect.top = 64;
		sp_proj->rect = change_direction_spell(it, sp_proj);
		it->game_obj = sp_proj;
	}
}
