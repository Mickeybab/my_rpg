/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** Init the whole player struct.
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "game_info.h"
#include "resources.h"
#include "inventory.h"

static int load_savegame(game_t *game)
{
	int size_read = 0;
	int fd = open(PATH_SAVEGAME, O_RDWR);
	sfVector2f map_pos = { RES_X, RES_Y};

	game->player = malloc(sizeof(player_t));
	game->player->info = malloc(sizeof(player_info_t));
	game->player->render_character = init_render_character(get_real_pos(
		game->map, map_pos), map_pos);
	if (game->player == NULL || fd == -1 || game->player->info == NULL ||
	game->player->render_character == NULL)
		return (-1);
	size_read = read(fd, game->player->info, sizeof(player_info_t));
	if (size_read != (sizeof(player_info_t)))
		return (-1);
	game->player->info->new_savegame = false;
	close(fd);
	return (0);
}

static player_t *create_new_savegame(game_t *game)
{
	player_t *player = malloc(sizeof(player_t));
	int fd = open(PATH_SAVEGAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR
		| S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	sfVector2f pos_map = {POS_X, POS_Y};

	if (player == NULL || fd == -1)
		return (NULL);
	player->render_character = init_render_character(get_real_pos(
		game->map, pos_map), pos_map);
	player->info = init_player_info();
	write(fd, player->info, sizeof(player_info_t));
	close(fd);
	return (player);
}

player_t *init_player(game_t *game)
{
	sfIntRect rect = {0, 0, 56, 65};
	sfVector2f pos;

	if (load_savegame(game) == -1) {
		game->player = create_new_savegame(game);
		game->player->info->new_savegame = false;
	} else {
		game->player->info->new_savegame = true;
	}
	game->player->inventory = initialisation_stuct_inventory();
	game->player->mv_list = NULL;
	pos.x = game->player->render_character->real_pos.x;
	pos.y = game->player->render_character->real_pos.y;
	game->player->anim = create_game_obj(ANIM, pos, rect, 0);
	game->player->render_character->mouve.x = 0;
	game->player->render_character->mouve.y = 0;
	game->player->ck = sfClock_create();
	game->player->mv_list = create_list();
	return (game->player);
}
