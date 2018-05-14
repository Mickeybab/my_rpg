/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "inventory.h"
#include "menu.h"
#include "game_info.h"

void init_obj_in_inv(inventory_t *inv)
{
	sfVector2f pos = {410, 680};
	sfIntRect rect[NB_OBJ] = RECTS;
	int id_begin[NB_BEGIN_STUFF] = BEGIN_STUFF;
	char sprites[NB_OBJ][SIZE_MAX_PATH_G_O] = SPRITES_OBJ;

	for (int i = 0; i < NB_BEGIN_STUFF; i++) {
		inv->obj_in[i] = create_game_obj(sprites[id_begin[i] - 1],
			pos, rect[id_begin[i] - 1], id_begin[i] - 1);
		inv->info->obj_in[i] = id_begin[i] - 1;
		pos.x += 93;
		if (pos.x >= 1500) {
			pos.x = 410;
			pos.y += 93;
		}
	}
	for (int i = NB_BEGIN_STUFF; i < NB_MAX_STUFF_INV; i++) {
		inv->obj_in[i] = NULL;
		inv->info->obj_in[i] = 0;
	}
}

inventory_t *initialisation_stuct_inventory(void)
{
	inventory_t *inv = malloc(sizeof(inventory_t) * 2);

	inv->info = malloc(sizeof(info_inv_t));
	inv->info->nb_stuff = NB_BEGIN_STUFF;
	inv->obj_in = malloc(sizeof(game_obj_t *) * NB_MAX_STUFF_INV + 1);
	inv->info->obj_in = malloc(sizeof(int) * NB_MAX_STUFF_INV + 1);
	inv->info->player_stuff = malloc(sizeof(int) * 5);
	inv->player_stuff = malloc(sizeof(game_obj_t *) * 5);
	if (!inv->obj_in || !inv || !inv->info->obj_in ||
		!inv->info->player_stuff || !inv->player_stuff)
		return (NULL);
	for (int i = 0; i < 5; i++) {
		inv->player_stuff[i] = NULL;
		inv->info->player_stuff[i] = 0;
	}
	init_obj_in_inv(inv);
	return (inv);
}

void draw_object_inventory(inventory_t *inv, game_t *game)
{
	sfVector2f scale[NB_OBJ] = SCALES;

	for (int i = 0; i < NB_MAX_STUFF_INV; i++) {
		for (; inv->obj_in[i] == NULL &&
			i + 1 < NB_MAX_STUFF_INV; i++);
		if (i + 1 >= NB_MAX_STUFF_INV || inv->obj_in[i] == NULL)
			return;
		sfSprite_setPosition(inv->obj_in[i]->sprite,
			inv->obj_in[i]->pos);
		sfSprite_setTextureRect(inv->obj_in[i]->sprite,
			inv->obj_in[i]->rect);
		sfSprite_setScale(inv->obj_in[i]->sprite,
			scale[inv->obj_in[i]->id]);
		sfRenderWindow_drawSprite(game->window->window,
			inv->obj_in[i]->sprite, NULL);
		fly_over_sprite(game, inv->obj_in[i]);
	}
}

int inventory(game_t *game)
{
	menu_t *inventory = initialisation_inventory(game);
	inventory_t *inv = game->player->inventory;
	int choice = 0;
	sfVector2f posview = {960, 540};

	if (inventory == NULL || game->player->inventory == NULL)
		return (ERROR);
	sfView_setCenter(game->window->view, posview);
	sfRenderWindow_setView(game->window->window, game->window->view);
	while (choice == 0) {
		change_text(inventory, game);
		sfRenderWindow_clear(game->window->window, sfBlack);
		inventory->display(game->window->window, inventory, false);
		choice = event_inventory(game, choice, inv);
		draw_object_inventory(inv, game);
		sfRenderWindow_display(game->window->window);
	}
	inventory->destroy(inventory);
	return (choice);
}
