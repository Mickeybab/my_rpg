/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** mouvement player
*/

#include "game_info.h"
#include <stdlib.h>

void destroy_node(player_t *player)
{
	node_t *save = player->mv_list->next;

	save->next->prev = player->mv_list;
	player->mv_list->next = save->next;
	free(save);
}

sfVector2f mouve_to_node(player_t *player)
{
	sfVector2f mouve = {0, 0};
	sfVector2f player_pos = sfRectangleShape_getPosition(
		player->render_character->shape);

	if (player->mv_list != NULL) {
		if (player->mv_list->next != player->mv_list) {
			mouve = init_mouvement(player_pos, player->
			mv_list->next->real_pos, player->info->speed, SIZE_P);
		}
		if (player->mv_list->next == player->mv_list) {
			destroy_list(player->mv_list);
			player->mv_list = NULL;
		}
	}
	return (mouve);
}

void get_mouve(game_t *game)
{
	sfVector2i mouse = POS_CURSOR(game);
	sfVector2f dest_map = get_tuile(game, mouse);

	if ((dest_map.x == -1 && dest_map.y == -1) ||
	game->map->tile[(int)dest_map.y][(int)dest_map.x].dispo == false)
		return;
	if (game->player->render_character->map_pos.x == dest_map.x &&
		game->player->render_character->map_pos.y == dest_map.y)
		return;
	if (game->player->mv_list != NULL) {
		destroy_list(game->player->mv_list);
		game->player->mv_list = NULL;
	}
	game->player->mv_list = find_way(game->map,
		game->player->render_character->map_pos, dest_map);
	game->player->mv_list != NULL ? destroy_node(game->player) : 0;
	game->player->render_character->mouve = mouve_to_node(game->player);
}