/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Include file of the music structure and functions
*/

#ifndef MUSIC_H
#define MUSIC_H

#include <SFML/Audio.h>
#include <stdbool.h>

#define PLAYING(s) (sfMusic_getStatus(s) == sfPlaying)

typedef struct music_info_s {
	bool play;
	sfMusic *main_menu;
	sfMusic *dead;
	sfMusic *shoot;
	sfMusic *shoot_enemy;
	sfMusic *enemy_dead;
	sfMusic *walking;
	sfMusic *item;
	sfMusic *level_up;
} music_t;

#endif /* end of include guard: MUSIC_H */
