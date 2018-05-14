/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** __DESCRIPTION__
*/

#include "file.h"
#include <stdlib.h>

file_t *create_empty_node(void)
{
	file_t *node = malloc(sizeof(file_t));

	if (!node)
		return NULL;
	node->line = NULL;
	node->next = NULL;
	return node;
}
