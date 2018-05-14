/*
** EPITECH PROJECT, 2018
** move_rect.c
** File description:
** animated a sprite
*/

#include "game_info.h"

sfIntRect move_rect(sfIntRect rect, int offset, int max_value)
{
	rect.left += offset;
	if (rect.left >= max_value)
		rect.left = 0;
	return (rect);
}

sfIntRect move_rect_less(sfIntRect rect, int offset, int max_value)
{
	rect.left -= offset;
	if (rect.left <= 0)
		rect.left = max_value - offset;
	return (rect);
}
