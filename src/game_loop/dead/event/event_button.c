/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** check the event of each button of the how menu
*/

#include "game_info.h"
#include "menu.h"
#include "dead.h"

static int what_button_clicked(game_t *game, menu_t *menu, sfEvent event)
{
	sfVector2i mouse = POS_CURSOR(game);

	for (unsigned int i = 0; i < menu->number_button; i++) {
		if ((event.type == sfEvtMouseButtonReleased ||
		event.type == sfEvtMouseButtonPressed) && event.key.code ==
		sfMouseLeft && mouse.x > menu->button[i]->position.x &&
		mouse.x < menu->button[i]->position.x + menu->button[i]->size.x
		&& mouse.y > menu->button[i]->position.y && mouse.y <
		menu->button[i]->position.y + menu->button[i]->size.y) {
			return (i);
		}
	}
	return (-1);
}

int event_button_dead(game_t *game, menu_t *menu, sfEvent event)
{
	int click = what_button_clicked(game, menu, event);
	redirect_t redir[NB_BUTTON] = {{0, back_choice_dead},
		{1, quit_choice_dead}};

	for (int i = 0; i < NB_BUTTON; i++) {
		if (click == redir[i].nb)
			return (redir[i].menu(game, menu, i, event));
	}
	return (0);
}
