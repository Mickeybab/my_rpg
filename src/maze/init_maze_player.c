/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init maze player
*/

#include "game_info.h"
#include "game_object.h"
#include "resources.h"

void init_maze_player(game_t *game)
{
	sfIntRect rect = {0, 0, 56, 65};
	sfVector2f pos = { 0, 0};

	game->player->mv_list = NULL;
	game->player->render_character->map_pos = pos;
	game->player->render_character->real_pos = get_real_pos(
	game->map, pos);
	pos = game->player->render_character->real_pos;
	pos.y -= SIZE_P;
	sfRectangleShape_setPosition(
		game->player->render_character->shape, pos);
	game->player->anim = create_game_obj(
		ANIM, game->player->render_character->real_pos, rect, 0);
	game->player->render_character->mouve.x = 0;
	game->player->render_character->mouve.y = 0;
}
