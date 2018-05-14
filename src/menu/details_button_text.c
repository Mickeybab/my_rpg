/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "menu.h"

void add_detail_text(text_t *text, sfColor color, sfVector2f size)
{
	if (size.x != 0)
		sfText_setCharacterSize(text->text, size.x);
	sfText_setColor(text->text, color);
	text->color = color;
}

void add_detail_button(button_t *but, sfColor color, sfVector2f size)
{
	sfRectangleShape_setFillColor(but->shape, color);
	sfRectangleShape_setSize(but->shape, size);
	but->size.y = size.y;
	but->size.x = size.x;
	but->color = color;
}
