/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Updates the pause_menu pos and its component
*/

#include "window.h"
#include "menu.h"
#include "pause_menu.h"

static void change_pos_button(menu_t *menu, button_t **button, sfVector2f pos)
{
	sfVector2f ref[NB_BUTTON] = POS_BUTTON;

	for (unsigned int i = 0; i < menu->number_button; i++) {
		button[i]->position.x = (pos.x - (1920 / 2)) +
			ref[i].x;
		button[i]->position.y = (pos.y - (1920 / 2)) +
			ref[i].y + 400;
		sfRectangleShape_setPosition(button[i]->shape,
			button[i]->position);
	}
}

static void change_pos_foreground(menu_t *menu, button_t **fore, sfVector2f
	pos)
{
	sfVector2f ref[NB_FOREGROUND] = POS_FOREGROUND;

	for (unsigned int i = 0; i < menu->number_foreground; i++) {
		fore[i]->position.x = (pos.x - (1920 / 2)) +
			ref[i].x;
		fore[i]->position.y = (pos.y - (1920 / 2)) +
			ref[i].y + 400;
		sfRectangleShape_setPosition(fore[i]->shape,
			fore[i]->position);
	}
}

static void change_pos_text(menu_t *menu, text_t **text, sfVector2f pos)
{
	sfVector2f ref[NB_TEXT] = POS_TEXT;

	for (unsigned int i = 0; i < menu->number_text; i++) {
		text[i]->position.x = (pos.x - (1920 / 2)) +
			ref[i].x;
		text[i]->position.y = (pos.y - (1920 / 2)) +
			ref[i].y + 400;
		sfText_setPosition(text[i]->text,
			text[i]->position);
	}
}

void update_pause_menu(menu_t *menu, sfView *view)
{
	sfVector2f pos = sfView_getCenter(view);

	change_pos_button(menu, menu->button, pos);
	change_pos_text(menu, menu->text, pos);
	change_pos_foreground(menu, menu->foreground, pos);
}
