/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** create dog enemy structure
*/

#include "enemy.h"
#include <stdlib.h>
#include "game_object.h"
#include "resources.h"

void init_dog_info(enemy_t *new)
{
	new->xp = XP_DOG;
	new->life = LIFE_DOG;
	new->type = DOG;
	new->speed = SPEED_DOG;
	new->next = NULL;
	new->prev = NULL;
}

static enemy_t *create_anim_dog(enemy_t *new)
{
	sfVector2f origin = {X_DOG / 2, Y_DOG / 2};
	sfVector2f size = {X_DOG, Y_DOG};
	sfIntRect rect = {0, 0, 556, 659};
	game_obj_t *sp_ennemy = new->anim;
	sfVector2f pos = new->real_pos;

	pos.y -= 60;
	pos.x -= 25;
	sp_ennemy = create_game_obj(ANIM_ENEMY, pos, rect, 0);
	new->anim = sp_ennemy;
	new->ck_anim = sfClock_create();
	sfSprite_setPosition(sp_ennemy->sprite, pos);
	sfRectangleShape_setSize(new->shape, size);
	sfRectangleShape_setOutlineThickness(new->shape, 2);
	sfRectangleShape_setOutlineColor(new->shape, sfRed);
	sfRectangleShape_setFillColor(new->shape, sfTransparent);
	sfRectangleShape_setOrigin(new->shape, origin);
	sfRectangleShape_setPosition(new->shape, new->real_pos);
	return (new);
}

enemy_t *create_dog(map_t *map, sfVector2f pos_map)
{
	enemy_t *new = malloc(sizeof(enemy_t));

	if (new != NULL) {
		init_dog_info(new);
		new->life = LIFE_DOG;
		new->map_pos = pos_map;
		new->on_activity = false;
		new->real_pos = get_real_pos(map, pos_map);
		new->real_pos.y -= SIZE_D;
		new->shape = sfRectangleShape_create();
		new->next = NULL;
		new->prev = NULL;
		new->type = DOG;
		new->clock = sfClock_create();
		new->node = NULL;
		new = create_anim_dog(new);
	}
	return (new);
}
