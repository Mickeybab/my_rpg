/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_maze function
*/

#include "game_info.h"
#include "hud.h"
#include "game_object.h"
#include "obj_decor.h"

void draw_maze_projectile(game_t *game)
{
	game_obj_t *sp_proj;

	for (projectile_t *it = game->projectile->next; it != game->projectile
		; it = it->next) {
		sp_proj = it->game_obj;
		sfSprite_setTextureRect(sp_proj->sprite, sp_proj->rect);
		sfRenderWindow_drawSprite(game->window->window,
			sp_proj->sprite, NULL);
		if (sfClock_getElapsedTime(it->clock).microseconds >=
		sfSeconds(LIFETIME).microseconds) {
			it = it->prev;
			destroy_projectile(it->next);
		}
	}
}

void draw_maze_enemy(game_t *game)
{
	game_obj_t *sp_enemy;
	sfVector2f scale = {0.15, 0.15};
	sfVector2f pos;

	for (enemy_t *it = game->enemy->next; it != game->enemy;
		it = it->next) {
		sp_enemy = it->anim;
		pos = it->real_pos;
		pos.x -= 60;
		pos.y -= 60;
		sfSprite_setScale(sp_enemy->sprite, scale);
		sfSprite_setPosition(sp_enemy->sprite, pos);
		sfSprite_setTextureRect(sp_enemy->sprite, sp_enemy->rect);
		sfRenderWindow_drawSprite(game->window->window,
			sp_enemy->sprite, NULL);
	}
}

void is_drawable(sfRenderWindow *window, map_t *map, int i, int j)
{
	sfRenderWindow_drawConvexShape(window, map->map[j][i],
		NULL);
	if (map->tile[j][i].dispo == false)
		return;
	draw_vertex_square(window, i, j, map);
	sfRenderWindow_drawConvexShape(window
		, map->tile[j][i].shape1, NULL);
	sfRenderWindow_drawConvexShape(window
		, map->tile[j][i].shape2, NULL);
}

void draw_maze_tile(sfRenderWindow *window, map_t *map, sfVector2f map_pos)
{
	int y = (int)map_pos.y;
	int x = (int)map_pos.x;
	int value = 30;

	if (x < value)
		x = value;
	if (y < value)
		y = value;
	for (int j = y - value ; j < y + value && j < map->max.y - 1; j++)
		for (int i = x - value; i < x + value && i < map->max.x - 1;
		i++) {
			is_drawable(window, map, i, j);
		}
}

void draw_maze(game_t *game, void * ptr)
{
	hud_t *hud = ptr;

	draw_maze_tile(game->window->window, game->map
		, game->player->render_character->map_pos);
	draw_maze_character(game);
	draw_maze_projectile(game);
	draw_maze_enemy(game);
	draw_maze_drop(game);
	display_menu(game->window->window, hud, false);
}
