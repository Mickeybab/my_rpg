/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include <stdlib.h>
#include "menu.h"
#include "skill_tree.h"

menu_t *initialisation_skill_tree(game_t *game)
{
	menu_t *menu = malloc(sizeof(menu_t));

	if (menu == NULL)
		return (NULL);
	detail_init_menu_skill_tree(menu);
	if (menu->button == NULL || menu->text == NULL ||
	menu->display == NULL || menu->destroy == NULL) {
		verbose_skill_tree_init_fail(game);
		return (NULL);
	}
	verbose_skill_tree_init_ok(game);
	return (menu);
}

game_obj_t **init_spell_skill_tree(void)
{
	game_obj_t **spell = malloc(sizeof(game_obj_t *) * NB_SPELL);
	sfIntRect rect_1 = {266, 133, 135, 133};
	sfIntRect rect_2 = {0, 0, 133, 133};
	sfIntRect rect_3 = {0, 133, 133, 133};
	sfVector2f pos1 = {895, 300};
	sfVector2f pos2 = {895, 433};
	sfVector2f pos3 = {895, 566};

	if (spell == NULL)
		return (NULL);
	for (int i = 0; i < NB_SPELL; i++)
		spell[i] = malloc(sizeof(game_obj_t));
	spell[0] = create_game_obj(SPELL_SPRITE, pos1, rect_1, 2);
	spell[1] = create_game_obj(SPELL_SPRITE, pos2, rect_2, 3);
	spell[2] = create_game_obj(SPELL_SPRITE, pos3, rect_3, 4);
	if (!spell[0] || !spell[1] || !spell[2])
		return (NULL);
	return (spell);
}

int skill_tree(game_t *game)
{
	menu_t *skill_tree = initialisation_skill_tree(game);
	game_obj_t **spell = init_spell_skill_tree();
	int choice = 0;
	sfVector2f posview = {960, 540};

	if (skill_tree == NULL || spell == NULL)
		return (ERROR);
	sfView_setCenter(game->window->view, posview);
	sfRenderWindow_setView(game->window->window, game->window->view);
	while (choice == 0) {
		draw_spell_skill_tree(game, spell, skill_tree);
		choice = event_skill_tree(skill_tree, game, choice);
	}
	skill_tree->destroy(skill_tree);
	return (choice);
}
