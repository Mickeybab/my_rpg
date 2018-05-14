/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "inventory.h"
#include "menu.h"
#include "game_info.h"

static int player_stuffing(inventory_t *inv, game_t *game)
{
	for (int i = 0; i < NB_MAX_STUFF_INV; i++) {
		if (inv->obj_in[i] != NULL) {
			inv->obj_in[i] =
			check_click(inv->obj_in[i], inv, game, i);
		}
	}
	return (0);
}

static int quit_inventory(sfEvent *event)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape))
		return (QUIT_MENU);
}

void delete_item(inventory_t *inv, game_t *game)
{
	sfVector2i event =
	sfMouse_getPositionRenderWindow(game->window->window);

	for (int i = 0; i < NB_MAX_STUFF_INV; i++) {
		if (inv->obj_in[i] != NULL && event.x >
		inv->obj_in[i]->pos.x &&
		event.x < inv->obj_in[i]->pos.x + inv->obj_in[i]->rect.width *
		inv->obj_in[i]->scale.x && event.y > inv->obj_in[i]->pos.y &&
		event.y < inv->obj_in[i]->pos.y + inv->obj_in[i]->rect.height *
		inv->obj_in[i]->scale.y) {
			destroy_game_obj(inv->obj_in[i]);
			inv->obj_in[i] = NULL;
			inv->info->obj_in[i] = 0;
			inv->info->nb_stuff--;
		}
	}
}

int event_inventory(game_t *game_info, int choice, inventory_t *inv)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(game_info->window->window, &event)) {
		if (event.type == sfEvtClosed) {
			sfRenderWindow_close(game_info->window->window);
			return (QUIT_GAME);
		}
		if (sfKeyboard_isKeyPressed(sfKeyS) &&
		event.type == sfEvtMouseButtonPressed)
			delete_item(inv, game_info);
		choice = quit_inventory(&event);
		if (event.type == sfEvtMouseButtonPressed) {
			choice = player_stuffing(inv, game_info);
		}
	}
	return (choice);
}
