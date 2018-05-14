/*
** EPITECH PROJECT, 2017
** RPG
** File description:
** init objets decor
*/

#include "obj_decor.h"

void init_decor(game_t *game)
{
	sfVector2f start = {0, 55};
	sfVector2f end = {90, 89};
	sfVector2f start2 = {0, 35};
	sfVector2f end2 = {10, 54};
	sfVector2f start3 = {10, 90};
	sfVector2f end3 = {120, 200};
	sfVector2f start4 = {91, 63};
	sfVector2f end4 = {98, 89};
	sfVector2f big_house = {132, 48};
	sfVector2f house_2 = {65, 17};

	game->map = make_forest(game->map, start, end, 2);
	game->map = make_forest(game->map, start2, end2, 2);
	game->map = make_forest(game->map, start3, end3, 2);
	game->map = make_forest(game->map, start4, end4, 2);
	game->map = init_obj_decor(game->map, 4, big_house);
	game->map = init_obj_decor(game->map, 8, house_2);
	make_vilage(game);
	make_forest_first_road(game);
	make_forest2(game);
}

void make_forest2(game_t *game)
{
	sfVector2f start = {68, 0};
	sfVector2f end = {87, 18};
	sfVector2f start2 = {0, 0};
	sfVector2f end2 = {26, 1};
	sfVector2f start3 = {40, 17};
	sfVector2f end3 = {60, 23};
	sfVector2f start4 = {60, 17};
	sfVector2f end4 = {82, 30};
	sfVector2f start5 = {172, 0};
	sfVector2f end5 = {245, 166};
	sfVector2f zap = {58, 80};

	game->map = make_forest(game->map, start, end, 5);
	game->map = make_forest(game->map, start2, end2, 5);
	game->map = make_forest(game->map, start3, end3, 5);
	game->map = make_forest(game->map, start4, end4, 5);
	game->map = make_forest(game->map, start5, end5, 7);
	game->map = init_obj_decor(game->map, 10, zap);
}

void make_forest_first_road(game_t *game)
{
	sfVector2f pos = {0, 3};
	sfVector2f pos2 = {0, 8};

	for (int i = 0 ; i < 20 ; i++, pos.x++, pos2.x++) {
		game->map = init_obj_decor(game->map, 9, pos);
		game->map = init_obj_decor(game->map, 9, pos2);
	}
	for (int i = 0 ; i < 20 ; i++, pos.x++, pos2.x++, pos.y++, pos2.y++) {
		game->map = init_obj_decor(game->map, 9, pos);
		game->map = init_obj_decor(game->map, 9, pos2);
	}
	for (int i = 0 ; i < 3 ; i++, pos.x++, pos2.x++) {
		game->map = init_obj_decor(game->map, 9, pos);
		game->map = init_obj_decor(game->map, 9, pos2);
	}
}

void make_vilage(game_t *game)
{
	sfVector2f road = {180, 175};
	sfVector2f road2 = {190, 175};
	int temp;

	for (int i = 0 ; i < 8 ; i++) {
		for (temp = rand() ; temp > 8 ; temp /= 8);
		for ( ; temp < 5 ; temp += 2);
		game->map = init_obj_decor(game->map, temp, road);
		road.y += 5;
	}
	for (int y = 0 ; y < 4 ; y++) {
		for (int x = 0 ; x < 2 ; x++) {
			game->map = init_obj_decor(game->map, 8, road2);
			road2.x += 5;
		}
		road2.x = 190;
		road2.y += 10;
	}
}