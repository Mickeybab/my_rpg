/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdlib.h>
#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "game_object.h"

/* -------------------------------------------------------------- */
/* ------------- HERE BEGINS THE INVENTORY'S MACROS ------------- */
/* -------------------------------------------------------------- */

/* ---- BACKGROUND ---- */
#define NB_BACKGROUND 1
#define POS_BACKGROUND_1 {400, 150}
#define PATH_BACKGROUND_1 INVENTORY_TEST
#define SIZE_MAX_PATH_BACKGROUND 36
#define POS_BACKGROUND {POS_BACKGROUND_1}
#define PATH_BACKGROUND {PATH_BACKGROUND_1}
/* ---- FOREGROUND ---- */
#define NB_FOREGROUND 0
#define POS_FOREGROUND_1 {100, 100}
//#define POS_FOREGROUND_2 {200, 100}
#define COLOR_FOREGROUND_1 sfRed
//#define COLOR_FOREGROUND_2 sfRed
#define SIZE_FOREGROUND_1 {0, 0}
//#define SIZE_FOREGROUND_2 {100, 100}
#define POS_FOREGROUND {}
#define COLOR_FOREGROUND {}
#define SIZE_FOREGROUND {}
/* ---- BUTTON ---- */
#define NB_BUTTON 1
#define POS_BUTTON_1 {1700, 50}
#define COLOR_BUTTON_1 sfRed
#define SIZE_BUTTON_1 {0, 0}
#define POS_BUTTON {POS_BUTTON_1}
#define COLOR_BUTTON {COLOR_BUTTON_1}
#define SIZE_BUTTON {SIZE_BUTTON_1}
/* ---- TEXT ---- */
#define NB_TEXT 6
#define POS_TEXT_1 {800, 0}
#define COLOR_TEXT_1 sfWhite
#define SIZE_TEXT_1 {50, 100}
#define STR_TEXT_1 "Press escape to exit\n\0"

#define POS_TEXT_2 {630, 580}
#define COLOR_TEXT_2 sfWhite
#define SIZE_TEXT_2 {20, 20}
#define STR_TEXT_2 "life_nb\0"

#define POS_TEXT_3 {715, 580}
#define COLOR_TEXT_3 sfWhite
#define SIZE_TEXT_3 {20, 20}
#define STR_TEXT_3 "defense_nb\0"

#define POS_TEXT_4 {800, 580}
#define COLOR_TEXT_4 sfWhite
#define SIZE_TEXT_4 {20, 20}
#define STR_TEXT_4 "mana_nb\0"

#define POS_TEXT_5 {890, 580}
#define COLOR_TEXT_5 sfWhite
#define SIZE_TEXT_5 {20, 20}
#define STR_TEXT_5 "attack_nb\0"

#define POS_TEXT_6 {500, 60}
#define COLOR_TEXT_6 sfWhite
#define SIZE_TEXT_6 {50, 100}
#define STR_TEXT_6 "click on object to use it, "\
	"S + click to deleted one object\0"

#define SIZE_TEXT_MAX 60
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3, POS_TEXT_4, POS_TEXT_5,\
	POS_TEXT_6}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3, COLOR_TEXT_4,\
	COLOR_TEXT_5, COLOR_TEXT_6}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3, SIZE_TEXT_4,\
	SIZE_TEXT_5, SIZE_TEXT_6}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3, STR_TEXT_4, STR_TEXT_5,\
	STR_TEXT_6}
#define FONT_TEXT FONT_BLACK_ITALIC

/* ------------- HERE BEGINS THE INVENTORY'S FUNCTIONS ------------- */

int inventory(game_t *game);
menu_t *initialisation_inventory(game_t *game);
void verbose_inventory_init_ok(game_t *game);
void verbose_inventory_init_fail(game_t *game);

/* ----------------------- INVENTORY_STRUCT ------------------------ */

#define NB_MAX_STUFF_INV 36
#define NB_TEXT_OBJ 5

#define NB_BEGIN_STUFF 7
#define BEGIN_STUFF {ID_1, ID_2, ID_7, ID_8, ID_9, ID_10, ID_10}

typedef struct info_inv {
	int nb_stuff;
	int *obj_in;
	int *player_stuff;
} info_inv_t;

typedef struct inventory {
	info_inv_t *info;
	game_obj_t **obj_in;
	game_obj_t **player_stuff;
} inventory_t;

int event_inventory(game_t *game_info, int choice, inventory_t *inv);
void fly_over_sprite(game_t *game, game_obj_t *obj);
game_obj_t *check_click(game_obj_t *obj, inventory_t *inv,
	game_t *game, int i);
inventory_t *initialisation_stuct_inventory(void);
void add_obj_in_inventory(game_obj_t *obj, inventory_t *inventory, int id);
int check_pos_inventory(inventory_t *inv, sfVector2f pos);
sfVector2f search_pos(inventory_t *inv);
void change_text(menu_t *inv, game_t *game);

#endif /* end of include guard: INVENTORY_H */
