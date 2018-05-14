/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** dead function do the whole menu loop and display and init
*/

#include <stdlib.h>
#include <stdio.h>
#include "game_info.h"
#include "obj_decor.h"
#include "window.h"
#include "menu.h"
#include "dead.h"

menu_t *initialisation_dead_menu(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	detail_init_dead_menu(menu);
	if (menu->button == NULL || menu->text == NULL ||
	menu->foreground == NULL || menu->display == NULL ||
	menu->destroy == NULL)
		return (NULL);
	return (menu);
}

static void reset_game(game_t *game)
{
	free(game->player);
	free(game->enemy);
	free(game->projectile);
	free(game->map);
	sfView_destroy(game->window->view);
	game->map = init_map(create_map_from_file(PATH_OPEN_MAP));
	game->player = init_player(game);
	game->window->view = sfView_create();
	game->enemy = init_enemy_list();
	game->projectile = init_list_proj();
	full_up_map(game->map);
	init_view(game);
	init_decor(game);
}

int dead(game_t *game)
{
	menu_t *menu = initialisation_dead_menu(game);
	int code = 0;

	if (menu == NULL)
		return (84);
	game->music->play ? sfMusic_play(game->music->dead) : 0;
	while (menu->looping == true && menu->code == OK) {
		move_dead_view(menu, game->window->view);
		if (get_event_dead(game, menu) == FAILURE)
			return (84);
		display_menu(game->window->window, menu, true);
	}
	sfMusic_stop(game->music->dead);
	remove(PATH_SAVEGAME);
	menu->destroy(menu);
	sfView_setCenter(game->window->view, (sfVector2f){1920 / 2, 1080 / 2});
	sfRenderWindow_setView(game->window->window, game->window->view);
	reset_game(game);
	return (code);
}
