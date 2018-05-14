/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** game loop for maze
*/

#include <stdlib.h>
#include "game_info.h"
#include "event.h"
#include "hud.h"
#include "obj_decor.h"
#include "player.h"
#include "game_object.h"

void launch_maze(game_t *game)
{
	game->map = create_maze(70, 70);
	init_maze_player(game);
	while (game->enemy->next != game->enemy)
		destroy_enemy(game->enemy->next);
}

void inside_loop(game_t *game, hud_t *hud, sfClock *clock)
{
	sfRenderWindow_clear(game->window->window, sfBlack);
	event(game->window->window, game, hud);
	update(game, hud, clock);
	collision(game);
	draw_maze(game, hud);
	sfRenderWindow_display(game->window->window);
	save_player(game->player);
}

void close_maze(game_t *game, hud_t *hud)
{
	hud->destroy(hud);
	destroy_map(game->map);
	while (game->enemy->next != game->enemy)
		destroy_enemy(game->enemy->next);
}

void maze_game_loop(game_t *game)
{
	hud_t *hud = init_hud();
	map_t *save = game->map;
	sfClock *clock = sfClock_create();

	if (hud == NULL || clock == NULL)
		return;
	launch_maze(game);
	while (sfRenderWindow_isOpen(game->window->window) &&
	game->player->info->health > 0) {
		inside_loop(game, hud, clock);
		if (game->player->render_character->map_pos.x ==
		game->map->max.x - 2 && game->player->
		render_character->map_pos.y == game->map->max.y - 2)
			break;
	}
	if (game->player->info->health <= 0)
		dead(game);
	close_maze(game, hud);
	game->map = save;
}
