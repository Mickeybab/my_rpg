/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw map functions
*/

#include "map.h"
#include "game_info.h"
#include "hud.h"
#include "game_object.h"
#include "obj_decor.h"
#include "projectile.h"

void draw_vertex_square(sfRenderWindow *window, int i, int j, map_t *map)
{
	sfVector2f **map2d = map->map2d;
	sfVertexArray *ligne1 = create_line(map2d[j][i], map2d[j][i + 1]);
	sfVertexArray *ligne2 = create_line(map2d[j][i + 1]
		, map2d[j + 1][i + 1]);
	sfVertexArray *ligne3 = create_line(map2d[j + 1][i + 1]
		, map2d[j + 1][i]);
	sfVertexArray *ligne4 = create_line(map2d[j + 1][i], map2d[j][i]);

	sfRenderWindow_drawVertexArray(window, ligne1, NULL);
	sfRenderWindow_drawVertexArray(window, ligne2, NULL);
	sfRenderWindow_drawVertexArray(window, ligne3, NULL);
	sfRenderWindow_drawVertexArray(window, ligne4, NULL);
	sfVertexArray_destroy(ligne1);
	sfVertexArray_destroy(ligne2);
	sfVertexArray_destroy(ligne3);
	sfVertexArray_destroy(ligne4);
}

void draw_tile(game_t *game, sfVector2f map_pos)
{
	int y = (int)map_pos.y;
	int x = (int)map_pos.x;
	int value = 30;
	map_t *map = game->map;

	if (x < value)
		x = value;
	if (y < value)
		y = value;
	for (int j = y - value ; j < y + value && j < map->max.y - 1; j++)
		for (int i = x - value; i < x + value && i < map->max.x - 1;
		i++) {
			draw_vertex_square(game->window->window, i, j, map);
			sfRenderWindow_drawConvexShape(game->window->window
				, game->map->tile[j][i].shape1, NULL);
			sfRenderWindow_drawConvexShape(game->window->window
				, game->map->tile[j][i].shape2, NULL);
			sfRenderWindow_drawConvexShape(game->window->window,
				game->map->map[j][i], NULL);
		}
}

void draw_all_obj(game_t *game, sfVector2f map_pos)
{
	int y = (int)map_pos.y;
	int x = (int)map_pos.x;
	int value = 30;
	map_t *map = game->map;

	if (x < value)
		x = value;
	if (y < value)
		y = value;
	for (int j = y - value ; j < y + value && j < map->max.y - 1; j++)
		for (int i = x - value; i < x + value && i < map->max.x - 1;
		i++)
			draw_obj(game, j, i);
}

static void draw_obj_second(game_t *game, int y, int x)
{
	enemy_t *en;
	game_obj_t *obj;

	if (game->map->tile[y][x].type == ENNEMY) {
		en = game->map->tile[y][x].obj;
		obj = en->anim;
		sfRenderWindow_drawSprite(game->window->window,
		obj->sprite, NULL);
	}
	if (game->map->tile[y][x].type == DROP &&
	game->map->tile[y][x].obj != NULL) {
		obj = game->map->tile[y][x].obj;
		sfRenderWindow_drawSprite(game->window->window,
		obj->sprite, NULL);
	}
}

void draw_obj(game_t *game, int y, int x)
{
	game_obj_decor_t *decor;
	game_obj_t *obj;
	projectile_t *proj;

	if (game->map->tile[y][x].type == DECOR) {
		decor = game->map->tile[y][x].obj;
		sfRenderWindow_drawSprite(game->window->window,
		decor->sprite, NULL);
	}
	if (game->map->tile[y][x].type == PLAYER)
		draw_character(game);
	if (game->map->tile[y][x].type == NPC) {
		obj = game->map->tile[y][x].obj;
		draw_npc(game, obj);
	}
	draw_obj_second(game, y, x);
}
