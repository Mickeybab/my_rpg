/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "game_info.h"
#include "game_object.h"
#include "inventory.h"

game_obj_t *check_drop(game_t *game, game_obj_t *obj, obj_drop_t *obj_drop)
{
	sfVector2i mouse = {(int)obj->pos.x, (int)obj->pos.y};
	sfVector2f p = get_tuile(game, mouse);

	if (game->player->render_character->real_pos.x > obj->pos.x &&
	game->player->render_character->real_pos.x < obj->pos.x +
	obj->rect.width * obj->scale.x &&
	game->player->render_character->real_pos.y
	> obj->pos.y && game->player->render_character->real_pos.y <
	obj->pos.y + obj->rect.height * obj->scale.y) {
		sfMusic_play(game->music->item);
		game->map->tile[(int)p.y][(int)p.x].type = RIEN;
		add_obj_in_inventory(obj, game->player->inventory, obj->id);
		game->map->tile[(int)p.y][(int)p.x].obj = NULL;
		destroy_game_obj(obj);
		obj_drop->nb_obj_drop--;
		return (NULL);
		game->map->obj_drop = obj_drop;
	}
	return (obj);
}
