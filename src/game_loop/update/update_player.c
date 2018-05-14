/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update player function
*/

#include "game_info.h"

static void update_move_player(game_t *game, sfVector2f player_pos)
{
	if (game->player->mv_list == NULL)
		return;
	if (player_pos.x >= game->player->mv_list->next->real_pos.x - 2
	&& player_pos.x <= game->player->mv_list->next->real_pos.x + 2 &&
	player_pos.y + SIZE_P >= game->player->mv_list->next->real_pos.y - 2 &&
	player_pos.y + SIZE_P <= game->player->mv_list->next->real_pos.y + 2) {
		game->player->render_character->map_pos.x = game->player->
		mv_list->next->map_pos.x;
		game->player->render_character->map_pos.y = game->player->
		mv_list->next->map_pos.y;
		destroy_node(game->player);
		game->player->render_character->mouve = mouve_to_node(
			game->player);
	}
}

void update_player(game_t *game, sfClock *cloc)
{
	sfVector2f player_pos = sfRectangleShape_getPosition(
		game->player->render_character->shape);
	static int counter = 1;

	if (!(game->player->render_character->mouve.x == 0 &&
		game->player->render_character->mouve.y == 0)) {
		sfRectangleShape_move(game->player->render_character->shape,
		game->player->render_character->mouve);
		game->player->render_character->real_pos = player_pos;
	}
	if (counter % 7 == 0) {
		game->player->info->mana < 100 ? game->player->info->mana
		+= 1 : 0;
		counter == 20 ? counter = 1 : 0;
	}
	counter++;
	update_move_player(game, player_pos);
}
