/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** init objets decor
*/

#include "map.h"
#include "obj_decor.h"

map_t *init_obj_decor(map_t *map, int id, sfVector2f pos)
{
	game_obj_decor_t *decor;

	decor = malloc(sizeof(game_obj_decor_t));
	if (id > 3 && id < 9)
		block_house(map, pos, (id == 4) ? (9) : (4));
	else
		map->tile[(int)pos.y][(int)pos.x].dispo = false;
	decor->pos = get_real_pos(map, pos);
	decor = init_struct_obj_decor(decor, id);
	id == 10 ? pos.y -= 6 : 0;
	map->tile[(int)pos.y][(int)pos.x].obj = decor;
	map->tile[(int)pos.y][(int)pos.x].type = DECOR;
	return (map);
}

map_t *make_forest(map_t *map, sfVector2f start, sfVector2f end,
float pourcent)
{
	int nb_cube = (end.x - start.x) * (end.y - start.y);
	int nb_tree = nb_cube * (pourcent / 100);
	int def_plus = nb_cube / nb_tree + ((nb_cube / nb_tree) / 4);
	sfVector2f pos = start;
	int temp = 0;

	nb_tree == 0 ? nb_tree++ : 0;
	for (float plus ; pos.y <= end.y && pos.x <= end.x ; ) {
		for (temp = rand() ; temp > NB_TREE ; temp /= NB_TREE);
		map = init_obj_decor(map, temp, pos);
		for (plus = (float)rand() ; plus > def_plus * def_plus ;
		plus /= def_plus);
		for ( ; plus > def_plus ; plus -= def_plus);
		pos.x += plus;
		while (pos.x > end.x) {
			pos.y++;
			pos.x = start.x + (pos.x - end.x);
		}
	}
	return (map);
}

game_obj_decor_t *init_struct_obj_decor(game_obj_decor_t *obj, int id)
{
	switch (id) {
		case 1 : return init_tree_1(obj, id);
		case 2 : return init_tree_2(obj, id);
		case 3 : return init_tree_double(obj, id);
		case 4 : return init_big_house(obj, id);
		case 9 : return init_bush(obj, id);
		case 10 : return init_zap(obj, id);
		default : return init_house(obj, id);
	}
}

sfConvexShape *init_shape_obj_decor(sfVector2f pos, int width, int height)
{
	sfConvexShape *shape = sfConvexShape_create();
	sfVector2f scale = {width, height};

	sfConvexShape_setScale(shape, scale);
	return shape;
}
