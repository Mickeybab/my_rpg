/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** drw call functions
*/

#include "game_info.h"
#include "hud.h"
#include "game_object.h"
#include "obj_decor.h"

void draw_character(game_t *game)
{
	game_obj_t *sp_player = game->player->anim;
	sfVector2f scale = {1.15, 1.15};
	sfVector2f player_pos = sfRectangleShape_getPosition(
		game->player->render_character->shape);

	sp_player->pos.x = player_pos.x - (sp_player->rect.width / 2 * 1.2);
	sp_player->pos.y = player_pos.y - (sp_player->rect.height / 2 * 1.2);
	sfSprite_setScale(sp_player->sprite, scale);
	sfSprite_setPosition(sp_player->sprite, sp_player->pos);
	sfSprite_setTextureRect(sp_player->sprite, sp_player->rect);
	sfRenderWindow_drawSprite(game->window->window, sp_player->sprite,
		NULL);
}

void draw_projectile(game_t *game)
{
	game_obj_t *sp_proj;

	for (projectile_t *it = game->projectile->next; it != game->projectile
		; it = it->next) {
		sp_proj = it->game_obj;
		sfSprite_setTextureRect(sp_proj->sprite, sp_proj->rect);
		sfRenderWindow_drawSprite(game->window->window,
			sp_proj->sprite, NULL);
	}
}

void draw_enemy(game_t *game)
{
	game_obj_t *sp_enemy;
	sfVector2f scale = {0.15, 0.15};
	sfVector2f pos;

	for (enemy_t *it = game->enemy->next; it != game->enemy;
		it = it->next) {
		sp_enemy = it->anim;
		pos = it->real_pos;
		if (it->type == DOG) {
			pos.x -= 60;
			pos.y -= 60;
		} else {
			pos.y -= 100;
			pos.x -= 20;
		}
		sfSprite_setScale(sp_enemy->sprite, scale);
		sfSprite_setTextureRect(sp_enemy->sprite, sp_enemy->rect);
	}
}

void draw_npc(game_t *game, game_obj_t *npc)
{
	sfRenderWindow_drawSprite(game->window->window,
		npc->sprite, NULL);
	sfRenderWindow_drawText(game->window->window,
		npc->text[0]->text, NULL);
}

int draw_call(game_t *game, void *ptr)
{
	hud_t *hud = ptr;

	init_draw(game);
	draw_tile(game, game->player->render_character->map_pos);
	draw_all_obj(game, game->player->render_character->map_pos);
	draw_projectile(game);
	display_menu(game->window->window, hud, false);
	destroy_draw(game);
}
