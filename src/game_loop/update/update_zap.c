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

void update_zap(game_t *game)
{
	sfVector2f pos = game->player->render_character->map_pos;

	if (pos.x < 58 && pos.x > 52 && pos.y < 78 && pos.y > 72) {
		maze_game_loop(game);
	}
}