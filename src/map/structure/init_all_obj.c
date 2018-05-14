/*
** EPITECH PROJECT, 2017
** my rpg
** File description:
** init_objet decor
*/

#include "map.h"
#include "obj_decor.h"

game_obj_decor_t *init_big_house(game_obj_decor_t *obj, int id)
{
	sfIntRect rect = {0, 0, WIDTH_BIG_HOUSE, HEIGHT_BIG_HOUSE};

	obj->id = id;
	obj->rect = rect;
	obj->texture = sfTexture_createFromFile(PATH_BIG_HOUSE, &obj->rect);
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, obj->texture, 0);
	obj->shape = init_shape_obj_decor(obj->pos, (int)WIDTH_BIG_HOUSE,
		(int)HEIGHT_BIG_HOUSE);
	obj->pos.x -= WIDTH_BIG_HOUSE / 2;
	obj->pos.y -= HEIGHT_BIG_HOUSE;
	sfSprite_setPosition(obj->sprite, obj->pos);
	return obj;
}

game_obj_decor_t *init_tree_1(game_obj_decor_t *obj, int id)
{
	sfIntRect rect = {0, 0, WIDTH_TREE, HEIGHT_TREE};

	obj->id = 1;
	obj->rect = rect;
	obj->texture = sfTexture_createFromFile(PATH_TREE, &obj->rect);
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, obj->texture, 0);
	obj->shape = init_shape_obj_decor(obj->pos, (int)WIDTH_TREE,
		(int)HEIGHT_TREE);
	obj->pos.x -= WIDTH_TREE / 2;
	obj->pos.y -= HEIGHT_TREE;
	sfSprite_setPosition(obj->sprite, obj->pos);
	return obj;
}

game_obj_decor_t *init_tree_2(game_obj_decor_t *obj, int id)
{
	sfIntRect rect = {0, 0, WIDTH_TREE2, HEIGHT_TREE2};

	obj->id = 2;
	obj->rect = rect;
	obj->texture = sfTexture_createFromFile(PATH_TREE2, &obj->rect);
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, obj->texture, 0);
	obj->shape = init_shape_obj_decor(obj->pos, (int)WIDTH_TREE2,
		(int)HEIGHT_TREE2);
	obj->pos.x -= WIDTH_TREE2 / 2;
	obj->pos.y -= HEIGHT_TREE2;
	sfSprite_setPosition(obj->sprite, obj->pos);
	return obj;
}

game_obj_decor_t *init_tree_double(game_obj_decor_t *obj, int id)
{
	sfIntRect rect = {0, 0, WIDTH_TREE_DOUBLE, HEIGHT_TREE_DOUBLE};

	obj->id = 3;
	obj->rect = rect;
	obj->texture = sfTexture_createFromFile(PATH_TREE_DOUBLE, &obj->rect);
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, obj->texture, 0);
	obj->shape = init_shape_obj_decor(obj->pos,
		(int)WIDTH_TREE_DOUBLE, (int)HEIGHT_TREE_DOUBLE);
	obj->pos.x -= WIDTH_TREE_DOUBLE / 2;
	obj->pos.y -= HEIGHT_TREE_DOUBLE;
	sfSprite_setPosition(obj->sprite, obj->pos);
	return obj;
}

game_obj_decor_t *init_bush(game_obj_decor_t *obj, int id)
{
	sfIntRect rect = {0, 0, WIDTH_BUSH, HEIGHT_BUSH};

	obj->id = 3;
	obj->rect = rect;
	obj->texture = sfTexture_createFromFile(PATH_BUSH, &obj->rect);
	obj->sprite = sfSprite_create();
	sfSprite_setTexture(obj->sprite, obj->texture, 0);
	obj->shape = init_shape_obj_decor(obj->pos,
		(int)WIDTH_BUSH, (int)HEIGHT_BUSH);
	obj->pos.x -= WIDTH_BUSH / 2;
	obj->pos.y -= HEIGHT_BUSH;
	sfSprite_setPosition(obj->sprite, obj->pos);
	return obj;
}