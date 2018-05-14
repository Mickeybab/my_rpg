/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** create projectil function
*/

#include "game_info.h"
#include "game_object.h"
#include "resources.h"
#include <stdlib.h>

projectile_t *init_list_proj(void)
{
	projectile_t *new = malloc(sizeof(projectile_t));

	if (new != NULL) {
		new->next = new;
		new->prev = new;
	}
	return (new);
}

game_obj_t *init_anim_projectile(projectile_t *new, bool player)
{
	game_obj_t *sp_proj = new->game_obj;
	sfIntRect rect = {0, 0, 64, 64};
	sfVector2f pos;

	pos.x = new->pos.x - 32;
	pos.y = new->pos.y - 32;
	if (player == true)
		sp_proj = create_game_obj(ANIM_SPELL_BASIC,
			pos, rect, 5);
	else
		sp_proj = create_game_obj(FIREBALL, pos, rect, 5);
	sfSprite_setPosition(sp_proj->sprite, pos);
	return (sp_proj);
}

projectile_t *init_rectangle_proj(projectile_t *new)
{
	sfVector2f size = {20, 20};
	sfVector2f origin = {10, 10};

	sfRectangleShape_setSize(new->rec, size);
	sfRectangleShape_setOutlineThickness(new->rec, 2);
	sfRectangleShape_setOutlineColor(new->rec, sfCyan);
	sfRectangleShape_setOrigin(new->rec, origin);
	sfRectangleShape_setRotation(new->rec
		, init_rotate(new->pos, new->end));
	sfRectangleShape_setPosition(new->rec, new->pos);
	return (new);
}

projectile_t *init_projectile(game_t *game, sfVector2i pos)
{
	projectile_t *new = malloc(sizeof(projectile_t));

	if (new != NULL) {
		new->rec = sfRectangleShape_create();
		new->clock = sfClock_create();
		new->pos = sfRectangleShape_getPosition(
			game->player->render_character->shape);
		new->end.x = pos.x;
		new->end.y = pos.y;
		new->dammage = 10;
		new->game_obj = init_anim_projectile(new, true);
		new->mouvement = init_mouvement(new->pos, new->end, 10, 0);
		new = init_rectangle_proj(new);
	}
	return (new);
}

void create_projectile(void *objt, bool from_player)
{
	game_t *game = objt;
	sfVector2i pos = POS_CURSOR(game);
	projectile_t *new = init_projectile(game, pos);

	if (new == NULL)
		return;
	game->music->play && PLAYING(game->music->shoot) == 0
		? sfMusic_play(game->music->shoot) : 0;
	game->projectile->next->prev = new;
	new->next = game->projectile->next;
	new->prev = game->projectile;
	game->projectile->next = new;
	new->from_player = from_player;
}
