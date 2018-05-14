/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include "game_info.h"
#include "game_object.h"

static void check_activity(enemy_t *it, game_obj_t *sp_enemy)
{
	if (it->on_activity == false && sfClock_getElapsedTime(it->ck_anim).
		microseconds >= sfSeconds(2).microseconds) {
		sp_enemy->rect.width = 556;
		sp_enemy->rect.top = 0;
		sp_enemy->rect.left = 0;
		sp_enemy->rect.height = 659;
		sfClock_restart(it->ck_anim);
	} else if (sfClock_getElapsedTime(it->ck_anim).
		microseconds >= sfSeconds(0.2).microseconds) {
		sp_enemy->rect.height = 700;
		sp_enemy->rect.width = 760;
		sp_enemy->rect = move_rect(sp_enemy->rect, 760, 760 * 5);
		sfClock_restart(it->ck_anim);
	}
}

void anim_slayer(game_t *game, enemy_t *it, game_obj_t *sp_enemy)
{
	sp_enemy = it->anim;
	it->mouve.x && it->mouve.y ?
	sp_enemy->rect.top = 140 : 0;
	if (it->mouve.x && it->mouve.y < 0)
		sp_enemy->rect.top = 2500;
	if (it->mouve.x < 0 && it->mouve.y)
		sp_enemy->rect.top = 1730;
	it->mouve.x < 0 && it->mouve.y < 0 ?
		sp_enemy->rect.top = 929 : 0;
}

void update_anim_enemy(game_t *game)
{
	game_obj_t *sp_enemy;

	for (enemy_t *it = game->enemy->next; it != game->enemy;
	it = it->next) {
		if (it->type == DOG) {
			sp_enemy = it->anim;
			it->mouve.x && it->mouve.y ?
			sp_enemy->rect.top = 659 : 0;
			if (it->mouve.x && it->mouve.y < 0)
				sp_enemy->rect.top = 4400;
			if (it->mouve.x < 0 && it->mouve.y)
				sp_enemy->rect.top = 3600;
			it->mouve.x < 0 && it->mouve.y < 0 ?
				sp_enemy->rect.top = 659 * 2 + 150 : 0;
			it->mouve.x < 0 && it->mouve.y < 0 ?
			sp_enemy->rect.width = 800 : 0;
			check_activity(it, sp_enemy);
		} else
			anim_slayer(game, it, sp_enemy);
	}
}
