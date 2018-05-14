/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include "skill_tree.h"
#include "game_object.h"

void fly_over_spell(game_t *game, game_obj_t *obj)
{
	sfVector2i mouse =
	sfMouse_getPositionRenderWindow(game->window->window);
	sfVector2f pos;

	pos.x = mouse.x + 10;
	pos.y = mouse.y + 10;
	if (mouse.x > obj->pos.x && mouse.x < obj->pos.x + obj->rect.width &&
	mouse.y > obj->pos.y && mouse.y < obj->pos.y + obj->rect.height) {
		sfRenderWindow_drawSprite(game->window->window, obj->sprite,
			NULL);
		sfText_setPosition(obj->text[0]->text, pos);
		sfRenderWindow_drawText(game->window->window,
				obj->text[0]->text, NULL);
	}
}

static void modif_text(game_t *game, menu_t *skill_tree)
{
	sfText_setString(skill_tree->text[3]->text,
		my_itoa(game->player->info->level));
	sfText_setString(skill_tree->text[4]->text,
		my_itoa(game->player->info->nb_life));
	sfText_setString(skill_tree->text[5]->text,
		my_itoa(game->player->info->defense));
	sfText_setString(skill_tree->text[6]->text,
		my_itoa(game->player->info->max_mana));
	sfText_setString(skill_tree->text[7]->text,
		my_itoa(game->player->info->attack));
	sfText_setString(skill_tree->text[8]->text,
		my_itoa(game->player->info->compet_point));
}

static void modif_scale(menu_t *skill_tree)
{
	sfVector2f scale_back = {2, 2};
	sfVector2f scale_skills = {0.5, 0.5};
	sfVector2f scale = {2.4, 2.4};

	sfSprite_setScale(skill_tree->background[1]->sprite, scale_back);
	sfSprite_setScale(skill_tree->background[2]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[3]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[4]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[5]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[6]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[7]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[8]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[9]->sprite, scale_skills);
	sfSprite_setScale(skill_tree->background[0]->sprite, scale);
	sfTexture_setSmooth(skill_tree->background[0]->texture, sfTrue);
}

void draw_spell_skill_tree(game_t *game, game_obj_t **spell,
	menu_t *skill_tree)
{
	sfVector2f scale = {0.8, 0.8};
	sfColor back_color = {139, 139, 139, 255};

	sfRenderWindow_clear(game->window->window, back_color);
	modif_text(game, skill_tree);
	modif_scale(skill_tree);
	skill_tree->display(game->window->window, skill_tree, false);
	for (int i = 0; i < NB_SPELL; i++) {
		sfSprite_setScale(spell[i]->sprite, scale);
		sfSprite_setPosition(spell[i]->sprite, spell[i]->pos);
		sfSprite_setTextureRect(spell[i]->sprite, spell[i]->rect);
		sfRenderWindow_drawSprite(game->window->window,
			spell[i]->sprite, NULL);
		fly_over_spell(game, spell[i]);
	}
	sfRenderWindow_display(game->window->window);
}
