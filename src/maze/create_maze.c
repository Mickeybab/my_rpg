/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** create maze function
*/

#include "recursive_division.h"
#include "map.h"

void implement_maze(map_t *map, char *maze)
{
	vector2i_t max = {map->max.x , map->max.y};
	tile_t *new;
	sfVector2f pos_map;

	for (int j = 0; j < map->max.y - 1; j++)
		for (int i = 0; i < map->max.x - 1; i++) {
			maze[calcul_coord(max, i, j)] == 'X' ?
			map->tile[j][i].dispo = false : 0;
			new = &map->tile[j][i];
			new = choose_texture(new, map, j, i);
			pos_map.x = i;
			pos_map.y = j;
			map->tile[j][i].middle = get_real_pos(map, pos_map);
		}
}

map_t *create_maze(int x, int y)
{
	map_t *map = init_map(create_map(x, y));
	char *maze = recursive_generator(x, y);

	implement_maze(map, maze);
	free(maze);
	return (map);
}
