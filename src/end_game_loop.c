/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include <stdlib.h>
#include "game_info.h"

void end_game_loop(game_t *game)
{
	if (game == NULL || game->window == NULL || game->window->view == NULL)
		return;
	sfView_setCenter(game->window->view, (sfVector2f){1920 / 2, 1080 / 2});
	sfRenderWindow_setView(game->window->window, game->window->view);
}
