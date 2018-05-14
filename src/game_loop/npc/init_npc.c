/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "game_info.h"
#include "game_object.h"
#include "resources.h"
#include "map.h"

static void add_npc_text(game_obj_t *npc, char *str, sfVector2f pos)
{
	pos.x = npc->pos.x - pos.x;
	pos.y = npc->pos.y - pos.y;
	npc->text = malloc(sizeof(text_t *));
	if (npc->text == NULL)
		return;
	npc->text[0] = malloc(sizeof(text_t));
	if (npc->text[0] == NULL)
		return;
	create_text(npc->text[0], pos, FONT_BOLD, str);
}

static game_obj_t *create_npc(sfIntRect rect, sfVector2f pos, char *str,
	sfVector2f pos_str)
{
	game_obj_t *npc = malloc(sizeof(game_obj_t));

	if (npc == NULL)
		return (NULL);
	npc->sprite = sfSprite_create();
	npc->texture = sfTexture_createFromFile(PATH_NPC, &rect);
	sfTexture_setSmooth(npc->texture, sfTrue);
	sfSprite_setTexture(npc->sprite, npc->texture, sfTrue);
	npc->pos.x = pos.x - 50;
	npc->pos.y = pos.y - 150;
	npc->rect.top = rect.top;
	npc->rect.left = rect.left;
	npc->rect.width = rect.width;
	npc->rect.height = rect.height;
	sfSprite_setPosition(npc->sprite, npc->pos);
	add_npc_text(npc, str, pos_str);
	return (npc);
}

static void init_all_npc(game_t *game, npc_t *npc)
{
	sfIntRect rect[NB_NPC] = RECT_NPC;
	sfVector2f pos[NB_NPC] = POS_NPC;
	sfVector2f pos_str[NB_NPC] = POS_STR_NPC;
	sfVector2f real = {0, 0};
	char str[NB_NPC][200] = STR_NPC;

	npc->npc = malloc(sizeof(game_obj_t *) * (npc->nb_npc + 1));
	if (npc->npc == NULL)
		return;
	for (int i = 0; i < npc->nb_npc; npc->npc[i + 1] = NULL, i++) {
		real = get_real_pos(game->map, pos[i]);
		npc->npc[i] = create_npc(rect[i], real, str[i], pos_str[i]);
		game->map->tile[(int)pos[i].y][(int)pos[i].x].dispo = false;
		game->map->tile[(int)pos[i].y][(int)pos[i].x].type = NPC;
		game->map->tile[(int)pos[i].y][(int)pos[i].x].obj =
			npc->npc[i];
		if (npc->npc[i] == NULL)
			return;
	}
}

npc_t *init_npc(game_t *game)
{
	npc_t *npc = malloc(sizeof(npc_t));

	if (npc == NULL)
		return (NULL);
	npc->nb_npc = NB_NPC;
	init_all_npc(game, npc);
	return (npc);
}
