/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "inventory.h"
#include "menu.h"
#include "game_info.h"
#include "mylib.h"

void change_text(menu_t *inv, game_t *game)
{
	sfText_setString(inv->text[1]->text,
		my_itoa(game->player->info->nb_life));
	sfText_setString(inv->text[2]->text,
		my_itoa(game->player->info->defense));
	sfText_setString(inv->text[3]->text,
		my_itoa(game->player->info->max_mana));
	sfText_setString(inv->text[4]->text,
		my_itoa(game->player->info->attack));
}
