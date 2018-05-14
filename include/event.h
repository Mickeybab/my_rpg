/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** event.h
*/

#ifndef EVENT_H_
#define EVENT_H_

#include "game_info.h"
#include "hud.h"

typedef enum mode_s {
	MOUVE,
	BASIC_SPELL,
	SPELL_ONE,
	TP
} event_t;

int inventory(game_t *game);
int skill_tree(game_t *game);
int event(sfRenderWindow *, game_t *, hud_t *);
void event_hud(game_t *game, hud_t *hud, sfEvent evt, event_t *);

#endif /* end of include guard: EVENT_H_ */
