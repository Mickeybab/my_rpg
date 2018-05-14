/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

long my_atoi(char *str)
{
	int i = 0;
	long result = 0;

	while (str[i] != '\n' && str[i]) {
		result = result * 10;
		result += str[i] - 48;
		i = i + 1;
	}
	return (result);
}
