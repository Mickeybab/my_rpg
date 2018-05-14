/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** create slayer enemy structure
*/

#include "enemy.h"
#include <stdlib.h>
#include "game_object.h"
#include "resources.h"

void insert_enemy_list(enemy_t *list, enemy_t *enemy)
{
	enemy_t *save = list->next;

	enemy->prev = list;
	enemy->next = save;
	list->next = enemy;
	save->prev = enemy;
}

void init_slayer_info(enemy_t *new)
{
	new->xp = XP_SLAYER;
	new->life = LIFE_SLAYER;
	new->type = SLAYER;
	new->speed = SPEED_SLAYER;
	new->next = NULL;
	new->prev = NULL;
}

static enemy_t *create_anim_slayer(enemy_t *new)
{
	sfVector2f origin = {X_SLAYER / 2, Y_SLAYER / 2};
	sfVector2f size = {X_SLAYER, Y_SLAYER};
	game_obj_t *sp_ennemy = new->anim;
	sfIntRect rect = {0, 0, 700, 800};
	sfVector2f pos = new->real_pos;

	pos.y -= 50;
	pos.x -= 30;
	sp_ennemy = create_game_obj(ANIM_SLAYER, pos, rect, 0);
	sfSprite_setPosition(sp_ennemy->sprite, pos);
	new->anim = sp_ennemy;
	new->ck_anim = sfClock_create();
	sfRectangleShape_setSize(new->shape, size);
	sfRectangleShape_setOutlineThickness(new->shape, 2);
	sfRectangleShape_setOutlineColor(new->shape, sfRed);
	sfRectangleShape_setFillColor(new->shape, sfTransparent);
	sfRectangleShape_setOrigin(new->shape, origin);
	sfRectangleShape_setPosition(new->shape, new->real_pos);
	return (new);
}

enemy_t *create_slayer(map_t *map, sfVector2f pos_map)
{
	enemy_t *new = malloc(sizeof(enemy_t));

	if (new != NULL) {
		init_slayer_info(new);
		new->map_pos = pos_map;
		new->on_activity = false;
		new->real_pos = get_real_pos(map, pos_map);
		new->real_pos.y -= SIZE_S;
		new->shape = sfRectangleShape_create();
		new->clock = sfClock_create();
		new->node = NULL;
		new = create_anim_slayer(new);
	}
	return (new);
}
