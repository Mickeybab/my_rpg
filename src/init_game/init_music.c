/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Init all the music in the game.
*/

#include <stdlib.h>
#include "resources.h"
#include "game_info.h"
#include "music.h"

music_t *init_music(void)
{
	music_t *music = malloc(sizeof(music_t));

	if (music == NULL)
		return (NULL);
	music->play = true;
	music->main_menu = sfMusic_createFromFile(MAIN_MENU_MUSIC);
	music->dead = sfMusic_createFromFile(DEAD_MUSIC);
	music->shoot = sfMusic_createFromFile(SPELL_SOUND);
	music->shoot_enemy = sfMusic_createFromFile(SPELL_SOUND);
	music->enemy_dead = sfMusic_createFromFile(SPELL_SOUND);
	music->walking = sfMusic_createFromFile(WALK_IN_PEACE);
	music->item = sfMusic_createFromFile(ITEM_SOUND);
	music->level_up = sfMusic_createFromFile(LEVEL_UP_SOUND);
	if (!music->main_menu && !music->dead && !music->enemy_dead &&
	!music->shoot && !music->shoot_enemy && !music->enemy_dead &&
	!music->walking && !music->item && !music->level_up)
		return (NULL);
	sfMusic_setLoop(music->main_menu, sfTrue);
	sfMusic_setLoop(music->walking, sfTrue);
	return (music);
}
