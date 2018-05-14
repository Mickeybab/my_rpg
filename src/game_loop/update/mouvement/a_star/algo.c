/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include "a_star.h"
#include "map.h"

static void full_up_final_list(astar_t *all, node_t *final_list)
{
	for (int j = all->max.y; j >= 0; j--)
		for (int i = all->max.x; i >= 0; i--)
			insert_node(final_list, copy_node(
				all->nodes_map[j][i]));
}

node_t *get_straight_path(astar_t *all, node_t *final_list)
{
	bool is_dispo = true;

	for (int j = 0; j <= all->max.y; j++)
		for (int i = 0; i <= all->max.x; i++)
			all->nodes_map[j][i].dispo != true ?
			is_dispo = false : 0;
	if (is_dispo == true) {
		full_up_final_list(all, final_list);
		destroy_astar(all);
		return (final_list);
	}
	else
		return (NULL);
}

void insert_node(node_t *list, node_t *node)
{
	node_t *save = list->next;

	list->next = node;
	node->prev = list;
	node->next = save;
	save->prev = node;
}

int compare_nodes(node_t node1, node_t node2)
{
	if (node1.heuristique < node2.heuristique)
		return (1);
	else if (node1.heuristique == node2.heuristique)
		return (0);
	else
		return (-1);
}

node_t *find_way(map_t *map, sfVector2f start, sfVector2f end)
{
	astar_t *all = init_astar(map, start, end);
	node_t *final_list = create_list();

	if (start.x - end.x == 0 || start.y - end.y == 0)
		return (get_straight_path(all, final_list));
	add_closedlist(all);
	find_successor(all);
	while (all->openlist->next != all->openlist) {
		find_best_node(all);
		add_closedlist(all);
		find_successor(all);
		if (all->closedlist->next->pos.x == all->max.x &&
			all->closedlist->next->pos.y == all->max.y)
			break;
	}
	if (all->openlist->next == all->openlist)
		return (NULL);
	find_way_back(all, final_list);
	destroy_astar(all);
	return (final_list);
}
