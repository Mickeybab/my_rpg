/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

int my_nbrlen(int nb)
{
	int result = nb;
	int i = 0;

	while (result > 0) {
		result = result / 10;
		i++;
	}
	return (i);
}
