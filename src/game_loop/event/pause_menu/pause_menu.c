/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "game_info.h"
#include "pause_menu.h"

menu_t *initialisation_pause_menu(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	detail_init_pause_menu(menu);
	if (menu->button == NULL || menu->text == NULL ||
	menu->foreground == NULL || menu->display == NULL ||
	menu->destroy == NULL) {
		return (NULL);
	}
	return (menu);
}

int pause_menu(game_t *game)
{
	menu_t *menu = initialisation_pause_menu(game);

	if (menu == NULL)
		return (0);
	update_pause_menu(menu, game->window->view);
	while (menu->looping == true && menu->code == OK) {
		if (get_event_pause_menu(game, menu) == FAILURE)
			return (0);
		sfRenderWindow_clear(game->window->window, sfBlack);
		display_menu(game->window->window, menu, true);
	}
	if (menu->code == QUIT_MENU || menu->code == QUIT_GAME) {
		menu->destroy(menu);
		return (1);
	} else if (menu->code == ERROR) {
		menu->destroy(menu);
		return (1);
	}
	menu->destroy(menu);
	return (0);
}
