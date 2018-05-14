/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include "game_info.h"
#include "game_object.h"

int change_direction(game_t *game, game_obj_t *sp_player)
{
	if (game->player->render_character->mouve.x < 0 &&
		game->player->render_character->mouve.y < 0)
		sp_player->rect.top = 0;
	if (game->player->render_character->mouve.x <= 0.2 &&
		game->player->render_character->mouve.x >= -0.2 &&
		game->player->render_character->mouve.y < 0)
		sp_player->rect.top = 63;
	if (game->player->render_character->mouve.x <= 0.2 &&
		game->player->render_character->mouve.x >= -0.2 &&
		game->player->render_character->mouve.y > 0)
		sp_player->rect.top = 63 * 6 + 13;
	if (game->player->render_character->mouve.x > 0 &&
		game->player->render_character->mouve.y <= 0.2 &&
		game->player->render_character->mouve.y >= -0.2)
			sp_player->rect.top = 63 * 3 + 7;
	if (game->player->render_character->mouve.x < 0 &&
		game->player->render_character->mouve.y <= 0.2 &&
		game->player->render_character->mouve.y >= -0.2)
		sp_player->rect.top = 63 * 4 + 9;
	return (sp_player->rect.top);
}

void check_state(game_t *game, game_obj_t *sp_player)
{
	if (((int)game->player->render_character->mouve.x != 0 ||
	(int)game->player->render_character->mouve.y != 0)) {
		if (sfClock_getElapsedTime(game->player->ck).microseconds >=
		sfSeconds(0.1).microseconds) {
			sp_player->rect =
			move_rect_less(sp_player->rect, 56, 56 * 7);
			sfClock_restart(game->player->ck);
		}
	} else {
		sp_player->rect.left = 56 * 7;
	}
}

void anim_player(game_t *game)
{
	game_obj_t *sp_player = game->player->anim;

	check_state(game, sp_player);
	if (game->player->render_character->mouve.x > 0 &&
		game->player->render_character->mouve.y > 0)
		sp_player->rect.top = 63 * 7 + 15;
	if (game->player->render_character->mouve.x < 0 &&
		game->player->render_character->mouve.y > 0)
		sp_player->rect.top = 63 * 5 + 10;
	if (game->player->render_character->mouve.x > 0 &&
		game->player->render_character->mouve.y < 0)
		sp_player->rect.top = 130;
	sp_player->rect.top = change_direction(game, sp_player);
	game->player->anim = sp_player;
}
