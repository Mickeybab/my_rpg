/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** Do the differents button's actions
*/

#include "game_info.h"
#include "menu.h"
#include "play_menu.h"

int play_choice_play_menu(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased) {
		menu->code = OK;
		menu->looping = false;
	}
	return (0);
}

int back_choice_play_menu(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased) {
		menu->code = QUIT_MENU;
		menu->looping = false;
	}
	return (0);
}

int quit_choice_play_menu(game_t *game, menu_t *menu, int i, sfEvent event)
{
	sfColor def_color = COLOR_BUTTON_1;

	if (event.type == sfEvtMouseButtonPressed)
		set_button_clicked(menu->button[i], def_color);
	if (event.type == sfEvtMouseButtonReleased) {
		menu->code = QUIT_GAME;
		menu->looping = false;
	}
	return (0);
}