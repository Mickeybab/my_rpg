/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include <stdlib.h>
#include "menu.h"
#include "skill_tree.h"

// INITIALISATION OF THE MAIN MENU'S BACKGROUND
static background_t **init_background_skill_tree(background_t **background,
	menu_t *menu)
{
	sfVector2f pos[NB_BACKGROUND] = POS_BACKGROUND;
	char path[NB_BACKGROUND][SIZE_MAX_PATH_BACKGROUND] = PATH_BACKGROUND;

	menu->number_background = NB_BACKGROUND;
	background = malloc(sizeof(background_t *) * (NB_BACKGROUND + 1));
	if (background == NULL)
		return (NULL);
	for (int i = 0; i < NB_BACKGROUND; i++) {
		background[i] = malloc(sizeof(background_t));
		if (background[i] == NULL)
			return (NULL);
		if (create_background(background[i], pos[i], path[i]) < 0)
			return (NULL);
	}
	background[NB_BACKGROUND] = NULL;
	return (background);
}

// INITIALISATION OF THE MAIN MENU'S FOREGROUND
static button_t **init_foreground_skill_tree(button_t **foreground,
	menu_t *menu)
{
	sfVector2f pos[NB_FOREGROUND] = POS_FOREGROUND;
	sfColor color[NB_FOREGROUND] = COLOR_FOREGROUND;
	sfVector2f size[NB_FOREGROUND] = SIZE_FOREGROUND;

	menu->number_foreground = NB_FOREGROUND;
	foreground = malloc(sizeof(button_t *) * (NB_FOREGROUND + 1));
	if (foreground == NULL)
		return (NULL);
	for (int i = 0; i < NB_FOREGROUND; i++) {
		foreground[i] = malloc(sizeof(button_t));
		if (foreground[i] == NULL)
			return (NULL);
		if (create_button(foreground[i], pos[i]) < 0)
			return (NULL);
		add_detail_button(foreground[i], color[i], size[i]);
	}
	foreground[NB_FOREGROUND] = NULL;
	return (foreground);
}

// INITIALISATION OF THE MAIN MENU'S BUTTONS
static button_t **init_button_skill_tree(button_t **button, menu_t *menu)
{
	sfVector2f pos[NB_BUTTON] = POS_BUTTON;
	sfColor color[NB_BUTTON] = COLOR_BUTTON;
	sfVector2f size[NB_BUTTON] = SIZE_BUTTON;

	menu->number_button = NB_BUTTON;
	button = malloc(sizeof(button_t *) * (NB_BUTTON + 1));
	if (button == NULL)
		return (NULL);
	for (int i = 0; i < NB_BUTTON; i++) {
		button[i] = malloc(sizeof(button_t));
		if (button[i] == NULL)
			return (NULL);
		if (create_button(button[i], pos[i]) < 0)
			return (NULL);
		add_detail_button(button[i], color[i], size[i]);
	}
	button[NB_BUTTON] = NULL;
	return (button);
}

// INITIALISATION OF THE MAIN MENU'S TEXTS
static text_t **init_text_skill_tree(text_t **text, menu_t *menu)
{
	sfVector2f pos[NB_TEXT] = POS_TEXT;
	sfColor color[NB_TEXT] = COLOR_TEXT;
	sfVector2f size[NB_TEXT] = SIZE_TEXT;
	char str[NB_TEXT][SIZE_TEXT_MAX] = STR_TEXT;

	menu->number_text = NB_TEXT;
	text = malloc(sizeof(text_t *) * (NB_TEXT + 1));
	if (text == NULL)
		return (NULL);
	for (int i = 0; i < NB_TEXT; i++) {
		text[i] = malloc(sizeof(text_t));
		if (text[i] == NULL)
			return (NULL);
		if (create_text(text[i], pos[i], FONT_TEXT, str[i]) < 0)
			return (NULL);
		add_detail_text(text[i], color[i], size[i]);
	}
	text[NB_TEXT] = NULL;
	return (text);
}

void detail_init_menu_skill_tree(menu_t *menu)
{
	if (NB_BACKGROUND > 0)
		menu->background = init_background_skill_tree(menu->background,
			menu);
	if (NB_FOREGROUND > 0)
		menu->foreground = init_foreground_skill_tree(menu->foreground,
			menu);
	if (NB_BUTTON > 0)
		menu->button = init_button_skill_tree(menu->button, menu);
	if (NB_TEXT > 0)
		menu->text = init_text_skill_tree(menu->text, menu);
	menu->display = display_menu;
	menu->destroy = free_menu;
	menu->looping = true;
	menu->code = OK;
}
