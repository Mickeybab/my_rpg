/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update enemy function
*/

#include "game_info.h"
#include <stdlib.h>
#include "game_object.h"
#include "resources.h"

sfVector2f set_pos_enemy(enemy_t *it)
{
	sfVector2f pos = it->real_pos;

	if (it->type == DOG) {
		pos.y -= 60;
		pos.x -= 25;
	} else {
		pos.y -= 50;
		pos.x -= 30;
	}
	return (pos);
}

static void update_move_enemy(game_t *game, enemy_t *it)
{
	int size = (it->type == SLAYER ? SIZE_S : SIZE_D);
	sfVector2f enemy = sfRectangleShape_getPosition(it->shape);
	game_obj_t *sp_enemy = it->anim;

	sfRectangleShape_move(it->shape, it->mouve);
	sfSprite_move(sp_enemy->sprite, it->mouve);
	if (enemy.x >= it->node->real_pos.x - 8
	&& enemy.x <= it->node->real_pos.x + 8
	&& enemy.y + size >= it->node->real_pos.y - 8
	&& enemy.y + size <= it->node->real_pos.y + 8) {
		it->map_pos.x = it->node->map_pos.x;
		it->map_pos.y = it->node->map_pos.y;
		it->real_pos = it->node->real_pos;
		it->real_pos.y -= size;
		free(it->node);
		sfSprite_setPosition(sp_enemy->sprite, set_pos_enemy(it));
		sfRectangleShape_setPosition(it->shape, it->real_pos);
		it->on_activity = false;
	}
}

static void add_drop(game_t *game, enemy_t *it, obj_drop_t *obj_drop)
{
	sfIntRect rect = {0, 0, 512, 512};
	int drop = choose_drop();
	char sprites[NB_OBJ][SIZE_MAX_PATH_G_O] = SPRITES_OBJ;
	sfVector2i mouse = {(int)it->real_pos.x, (int)it->real_pos.y};
	sfVector2f p = get_tuile(game, mouse);

	if (obj_drop->nb_obj_drop < MAX_OBJ_IN_MAP) {
		obj_drop->objs_drop[obj_drop->nb_obj_drop] =
		create_game_obj(sprites[drop], it->real_pos, rect,
			drop);
		game->map->tile[(int)p.y][(int)p.x].type = DROP;
		game->map->tile[(int)p.y][(int)p.x].obj
		= obj_drop->objs_drop[obj_drop->nb_obj_drop];
		obj_drop->nb_obj_drop++;
	}
}

static void kill_enemy(game_t *game, enemy_t *it, obj_drop_t *obj_drop)
{
	if (it->life < 0) {
		game->music->play ? sfMusic_play(game->music->enemy_dead) : 0;
		game->player->info->exp += it->xp;
		add_drop(game, it, obj_drop);
		game->map->obj_drop = obj_drop;
		it = it->prev;
		destroy_enemy(it->next);
		game->nb_enemy--;
	}
}

void update_enemy(game_t *game)
{
	obj_drop_t *obj_drop = game->map->obj_drop;

	for (enemy_t *it = game->enemy->next; it != game->enemy
	; it = it->next) {
		it->type == SLAYER ? get_slayer_turn(game, it) : 0;
		it->type == DOG ? get_dog_turn(game, it) : 0;
		if (it->on_activity == true) {
			update_move_enemy(game, it);
		}
		kill_enemy(game, it, obj_drop);
	}
	for (int i = 0; i < MAX_OBJ_IN_MAP; i++)
		if (obj_drop->objs_drop[i] != NULL)
			obj_drop->objs_drop[i] = check_drop(game,
				obj_drop->objs_drop[i], obj_drop);
}
