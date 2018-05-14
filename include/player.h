/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** character prototype and structure
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.h>
#include "collision.h"
#include "a_star.h"

#define POS_X 0
#define POS_Y 5
#define RES_X 0
#define RES_Y 5
#define MAX_USER_CHAR 12
#define SIZE_P 20

/* --- DEFAULT VALUES --- */
#define DEFAULT_ATTACK 10
#define DEFAULT_DEFENSE 10
#define DEFAULT_SPEED 3
#define DEFAULT_CRITICAL 10
#define DEFAULT_MANA 100
#define DEFAULT_HEALTH 100
#define DEFAULT_EXP 0

typedef struct render_character_s {
	sfVector2f map_pos;
	sfVector2f real_pos;
	sfRectangleShape *shape;
	sfSprite *sprite;
	sfVector2f arr;
	sfVector2f mouve;
} render_t;

typedef enum actual_mission_s {
	INTRO,
	OPEN_WORLD,
	FINAL
} mission_actual_t;

typedef struct player_info_s {
	char name_player[MAX_USER_CHAR + 1];
	int nb_life;
	int max_mana;
	int level;
	float attack;
	int speed;
	int compet_point;
	int critical;
	int exp;
	int mana;
	int defense;
	float health;
	bool new_savegame;
	mission_actual_t actual_mission;
} player_info_t;

typedef struct player_s {
	player_info_t *info;
	render_t *render_character;
	node_t *mv_list;
	transformed_shape_t *transfo;
	void *inventory;
	void *anim;
	sfClock *ck;
} player_t;

sfRectangleShape *create_player(sfVector2f pos);
player_info_t *init_player_info(void);
render_t *init_render_character(sfVector2f, sfVector2f);
void save_player(player_t *player);

/*
** move function
*/
sfVector2f  mouve_to_node(player_t *player);
void destroy_node(player_t *player);


#endif /* !PLAYER_H  */
