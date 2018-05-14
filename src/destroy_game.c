/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** destroy the whole game structre
*/

#include <stdlib.h>
#include "game_info.h"
#include "window.h"
#include "music.h"

static void destroy_window(window_t *window)
{
	if (window != NULL) {
		sfRenderWindow_close(window->window);
		sfRenderWindow_destroy(window->window);
		free(window);
	}
}

static void destroy_music(music_t *music)
{
	if (music != NULL) {
		sfMusic_stop(music->main_menu);
		sfMusic_stop(music->dead);
		sfMusic_stop(music->shoot);
		sfMusic_stop(music->shoot_enemy);
		sfMusic_stop(music->enemy_dead);
		sfMusic_stop(music->walking);
		sfMusic_stop(music->item);
		sfMusic_stop(music->level_up);
		sfMusic_destroy(music->main_menu);
		sfMusic_destroy(music->dead);
		sfMusic_destroy(music->shoot);
		sfMusic_destroy(music->shoot_enemy);
		sfMusic_destroy(music->enemy_dead);
		sfMusic_destroy(music->walking);
		sfMusic_destroy(music->item);
		sfMusic_destroy(music->level_up);
	}
}

void destroy_game(game_t *game)
{
	if (game != NULL) {
		destroy_window(game->window);
		destroy_music(game->music);
		free(game);
	}
}
