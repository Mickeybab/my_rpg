/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#ifndef _FILE_H__
#define _FILE_H__

typedef struct file {
	char *line;
	struct file *next;
} file_t;

file_t *create_empty_node(void);
file_t *load_file_in_mem(char const *);
void free_file_in_mem(file_t *);

#endif
