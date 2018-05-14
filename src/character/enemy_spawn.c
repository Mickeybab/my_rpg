/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** spawn enemy
*/

#include "game_info.h"

void spawn_enemy(game_t *game, sfClock *cloc)
{
	if (game->nb_enemy > 5)
		return;
	if (sfClock_getElapsedTime(cloc).microseconds >=
		sfSeconds(30).microseconds){
		sfClock_restart(cloc);
		insert_enemy_list(game->enemy, create_slayer(game->map,
			get_spawn_pos(game)));
		insert_enemy_list(game->enemy, create_dog(game->map,
			get_spawn_pos(game)));
		insert_enemy_list(game->enemy, create_slayer(game->map,
			get_spawn_pos(game)));
		game->nb_enemy += 3;
	}
}
