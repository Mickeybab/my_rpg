/*
** EPITECH PROJECT, 2017
** init_window.c
** File description
** Creation of the window struct, return NULL if error. Display verbose if set.
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colors.h"
#include "window.h"
#include "mylib.h"

static window_t *verbose_creation_window(window_t *window, bool verbose)
{
	if (verbose == true) {
		my_putstr(LIGHT_BLUE);
		my_putstr("[WINDOW CREATION]\n");
		my_putstr(GREEN);
		my_putstr("\tWindow Created");
		my_putstr(WHITE);
		my_putstr("\t->\tVideo Mode = ");
		my_putnbr(window->width);
		my_putstr(" / ");
		my_putnbr(window->height);
		my_putstr("\n");
	}
	return (window);
}

static void *verbose_creation_window_fail(window_t *window, bool verbose)
{
	if (verbose == true) {
		my_putstr(LIGHT_BLUE);
		my_putstr("[WINDOW CREATION]\n");
		my_putstr(LIGHT_RED);
		my_putstr("\tFAIL");
		my_putstr(WHITE);
		my_putstr("\t->\tThe window could not be created.\n");
	}
	free(window);
	return (NULL);
}

window_t *init_window(bool verbose)
{
	window_t *window = malloc(sizeof(window_t));
	sfVideoMode video = {1920, 1080, 32};

	if (window == NULL)
		return (NULL);
	window->video_mode = video;
	window->width = video.width;
	window->height = video.height;
	window->window = sfRenderWindow_create(video, "my rpg", sfClose, NULL);
	if (window->window == NULL)
		return (verbose_creation_window_fail(window, verbose));
	sfRenderWindow_setMouseCursorVisible(window->window, CURSOR_VISIBLE);
	sfRenderWindow_setFramerateLimit(window->window, DEFAULT_FRAMERATE);
	sfRenderWindow_setTitle(window->window, TITLE_WINDOW);
	return (verbose_creation_window(window, verbose));
}