/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "inventory.h"
#include "menu.h"
#include "game_info.h"
#include "mylib.h"

game_obj_t *if_stuff_empty(game_obj_t *obj, inventory_t *inv,
	game_t *game, int i)
{
	int x_pos_stuff[4] = X_POS_STUFF;
	int y_pos_stuff[4] = Y_POS_STUFF;
	int type[NB_OBJ] = TYPES;
	int life = my_atoi(obj->text[1]->str);
	int defense = my_atoi(obj->text[2]->str);
	int mana = my_atoi(obj->text[3]->str);
	int attack = my_atoi(obj->text[4]->str);

	obj->pos.x = x_pos_stuff[type[obj->id] - 1];
	obj->pos.y = y_pos_stuff[type[obj->id] - 1];
	inv->player_stuff[type[obj->id] - 1] = obj;
	game->player->info->nb_life += life;
	game->player->info->defense += defense;
	game->player->info->max_mana += mana;
	game->player->info->attack += attack;
	inv->info->player_stuff[type[obj->id] - 1] = obj->id;
	inv->info->obj_in[i] = 0;
	return (obj);
}

game_obj_t *if_inv_empty(game_obj_t *obj, inventory_t *inv, sfVector2f pos,
	game_t *game, int i)
{
	char type[NB_OBJ] = TYPES;
	int life = my_atoi(obj->text[1]->str);
	int defense = my_atoi(obj->text[2]->str);
	int mana = my_atoi(obj->text[3]->str);
	int attack = my_atoi(obj->text[4]->str);

	obj->pos.x = pos.x;
	obj->pos.y = pos.y;
	obj = inv->player_stuff[type[obj->id] - 1];
	inv->player_stuff[type[obj->id] - 1] = NULL;
	game->player->info->nb_life -= life;
	game->player->info->defense -= defense;
	game->player->info->max_mana -= mana;
	game->player->info->attack -= attack;
	inv->info->player_stuff[type[obj->id] - 1] = 0;
	inv->info->obj_in[i] = obj->id;
	return (obj);
}

game_obj_t *apply_bonus(game_t *game, game_obj_t *obj, inventory_t *inv)
{
	int health = my_atoi(obj->text[1]->str);
	int mana = my_atoi(obj->text[3]->str);

	if (health > 0 && health < game->player->info->nb_life)
		game->player->info->health += health;
	if (mana > 0 && mana < game->player->info->max_mana)
		game->player->info->mana += mana;
	obj = NULL;
	return (obj);
}

game_obj_t *check_click(game_obj_t *obj, inventory_t *inv,
	game_t *game, int i)
{
	char type[NB_OBJ] = TYPES;
	int x_pos_stuff[5] = X_POS_STUFF;
	int y_pos_stuff[5] = Y_POS_STUFF;
	sfVector2i event =
	sfMouse_getPositionRenderWindow(game->window->window);

	if (event.x > obj->pos.x && event.x < obj->pos.x + obj->rect.width *
		obj->scale.x && event.y > obj->pos.y && event.y < obj->pos.y +
		obj->rect.height * obj->scale.y) {
		if (type[obj->id] <= 0) {
			obj = apply_bonus(game, obj, inv);
			return (NULL);
		}
		if (inv->player_stuff[type[obj->id] - 1] == NULL) {
			obj = if_stuff_empty(obj, inv, game, i);
		} else if (obj->pos.x == x_pos_stuff[type[obj->id] - 1] &&
			obj->pos.y == y_pos_stuff[type[obj->id] - 1])
			obj = if_inv_empty(obj, inv, search_pos(inv), game, i);
	}
	return (obj);
}
