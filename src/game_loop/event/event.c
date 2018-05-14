/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** event functions
*/

#include "game_info.h"
#include "event.h"
#include "hud.h"

event_t get_mode(sfEvent *event, event_t mode)
{
	if (sfKeyboard_isKeyPressed(sfKeyZ))
		return (mode != TP ? TP : MOUVE);
	if (sfKeyboard_isKeyPressed(sfKeyLShift))
		return (BASIC_SPELL);
	if (sfKeyboard_isKeyPressed(sfKeyE))
		return (mode != SPELL_ONE ? SPELL_ONE : MOUVE);
	if (mode == BASIC_SPELL && !sfKeyboard_isKeyPressed(sfKeyLShift))
		return (MOUVE);
	return (mode);
}

void event_loop(game_t *game)
{
	if (sfKeyboard_isKeyPressed(sfKeyI))
		inventory(game);
	if (sfKeyboard_isKeyPressed(sfKeyS))
		skill_tree(game);
}

void spell_event(game_t *game, event_t *mode)
{
	int mana = game->player->info->mana;

	if (*mode == MOUVE && sfMouse_isButtonPressed(sfMouseLeft))
		get_mouve(game);
	if (mana < 5)
		return;
	if (*mode == BASIC_SPELL && sfMouse_isButtonPressed(sfMouseLeft)) {
		game->player->info->mana -= 2;
		create_projectile(game, true);
	}
	if (*mode == TP && sfMouse_isButtonPressed(sfMouseLeft)) {
		teleport(game);
	}
	if (*mode == SPELL_ONE && sfMouse_isButtonPressed(sfMouseLeft)) {
		game->player->info->mana -= 10;
		game->player->info->health += 15;
	}
	*mode = MOUVE;
}

int event(sfRenderWindow *window, game_t *game, hud_t *hud)
{
	sfEvent event;
	static event_t mode = MOUVE;

	while (sfRenderWindow_pollEvent(window, &event)) {
		mode = get_mode(&event, mode);
		if (sfKeyboard_isKeyPressed(sfKeyEscape) && pause_menu(game))
			return (-1);
		if (event.type == sfEvtClosed)
			sfRenderWindow_close(window);
		event_loop(game);
		spell_event(game, &mode);
	}
	return (0);
}
