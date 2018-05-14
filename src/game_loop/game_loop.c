/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include <stdlib.h>
#include "game_info.h"
#include "event.h"
#include "hud.h"
#include "obj_decor.h"
#include "player.h"
#include "game_object.h"

void inside_game_loop(game_t *game, hud_t *hud, npc_t *npc, sfClock *cloc)
{
	update(game, hud, cloc);
	collision(game);
	draw_call(game, hud);
	sfRenderWindow_display(game->window->window);
	save_player(game->player);
	update_music(game->music);
}

void game_loop(game_t *game)
{
	hud_t *hud = init_hud();
	npc_t *npc = init_npc(game);
	sfClock *cloc = sfClock_create();

	if (hud == NULL)
		return;
	while (sfRenderWindow_isOpen(game->window->window) &&
	game->player->info->health > 0) {
		sfRenderWindow_clear(game->window->window, sfBlack);
		if (event(game->window->window, game, hud) == -1)
			return;
		inside_game_loop(game, hud, npc, cloc);
	}
	if (game->player->info->health <= 0)
		dead(game);
	hud->destroy(hud);
}
