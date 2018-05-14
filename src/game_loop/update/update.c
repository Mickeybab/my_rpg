/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update functions
*/

#include <stdlib.h>
#include "game_info.h"
#include "game_object.h"
#include "hud.h"
#include "music.h"

static void update_view(game_t *game)
{
	sfVector2f player_pos = sfRectangleShape_getPosition(
		game->player->render_character->shape);
	game->window->posView.x = player_pos.x;
	game->window->posView.y = player_pos.y;
	sfView_setCenter(game->window->view, game->window->posView);
	sfRenderWindow_setView(game->window->window, game->window->view);
}

static void update_player_info(game_t *game)
{
	if (game->player->info->exp >= 10 * game->player->info->level) {
		sfMusic_play(game->music->level_up);
		game->player->info->level++;
		game->player->info->compet_point +=
		1 * game->player->info->level;
		game->player->info->exp = 0;
	}
}

static void update_projectile(game_t *game)
{
	game_obj_t *sp;

	for (projectile_t *it = game->projectile->next; it != game->projectile
		; it = it->next) {
		sp = it->game_obj;
		sfRectangleShape_move(it->rec, it->mouvement);
		sfSprite_move(sp->sprite, it->mouvement);
		if (sfClock_getElapsedTime(it->clock).microseconds >=
		sfSeconds(LIFETIME).microseconds) {
			it = it->prev;
			destroy_projectile(it->next);
		}
	}
}

void update_music(music_t *music)
{
	sfMusic_stop(music->shoot);
	sfMusic_stop(music->shoot_enemy);
}

int update(game_t *game, void *hud_ptr, sfClock *cloc)
{
	hud_t *hud = hud_ptr;

	update_zap(game);
	spawn_enemy(game, cloc);
	anim_player(game);
	update_view(game);
	update_hud(hud, game->window, game->player);
	update_projectile(game);
	anim_basic_spell(game);
	update_player(game, cloc);
	update_player_info(game);
	update_enemy(game);
	update_anim_enemy(game);
	return (0);
}
