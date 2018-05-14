/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw maze player
*/

#include "game_info.h"
#include "game_object.h"

void draw_maze_character(game_t *game)
{
	game_obj_t *sp_player = game->player->anim;
	sfVector2f scale = {1.15, 1.15};
	sfVector2f player_pos = sfRectangleShape_getPosition(
		game->player->render_character->shape);

	sp_player->pos.x = player_pos.x - (sp_player->rect.width / 2 * 1.2);
	sp_player->pos.y = player_pos.y - (sp_player->rect.height / 2 * 1.2);
	sfSprite_setScale(sp_player->sprite, scale);
	sfSprite_setPosition(sp_player->sprite, sp_player->pos);
	sfSprite_setTextureRect(sp_player->sprite, sp_player->rect);
	sfRenderWindow_drawSprite(game->window->window, sp_player->sprite,
		NULL);
}

void draw_maze_drop(game_t *game)
{
	obj_drop_t *obj_drop = game->map->obj_drop;

	for (int i = 0; i < MAX_OBJ_IN_MAP; i++) {
		for (; i < MAX_OBJ_IN_MAP && obj_drop->objs_drop[i] == NULL;
			i++);
		if (i >= MAX_OBJ_IN_MAP)
			return;
		sfSprite_setPosition(obj_drop->objs_drop[i]->sprite,
		obj_drop->objs_drop[i]->pos);
		sfSprite_setTextureRect(obj_drop->objs_drop[i]->sprite,
		obj_drop->objs_drop[i]->rect);
		sfRenderWindow_drawSprite(game->window->window,
		obj_drop->objs_drop[i]->sprite, NULL);
	}
}
