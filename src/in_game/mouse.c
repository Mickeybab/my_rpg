/*
** EPITECH PROJECT, 2017
** My_rpg
** File description:
** Mouse traking
*/

#include "game_info.h"

sfVector2i get_real_pos_mouse(game_t *game)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(
		game->window->window);
	sfVector2i final;

	if (game->in_game == false)
		return (mouse);
	final.x = mouse.x + game->window->posView.x - (DEFAULT_SIZE_X / 2);
	final.y = mouse.y + game->window->posView.y - (DEFAULT_SIZE_Y / 2);
	return (final);
}
