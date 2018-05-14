/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** drw call functions
*/

#include "game_info.h"
#include "hud.h"
#include "game_object.h"
#include "obj_decor.h"

void init_draw(game_t *game)
{
	sfVector2f pos_player = game->player->render_character->map_pos;

	draw_enemy(game);
	draw_drop(game);
	draw_projectile(game);
	for (enemy_t *it = game->enemy->next; it != game->enemy;
	it = it->next) {
		game->map->tile[(int)it->map_pos.y][(int)it->map_pos.x].type
		= ENNEMY;
		game->map->tile[(int)it->map_pos.y][(int)it->map_pos.x].obj
		= it;
	}
	game->map->tile[(int)pos_player.y][(int)pos_player.x].type = PLAYER;
}

void destroy_draw(game_t *game)
{
	sfVector2f pos_player = game->player->render_character->map_pos;

	for (enemy_t *it = game->enemy->next; it != game->enemy;
	it = it->next) {
		game->map->tile[(int)it->map_pos.y][(int)it->map_pos.x].type
		= RIEN;
		game->map->tile[(int)it->map_pos.y][(int)it->map_pos.x].obj
		= NULL;
	}
	game->map->tile[(int)pos_player.y][(int)pos_player.x].type = RIEN;
}