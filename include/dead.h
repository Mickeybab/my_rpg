/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#ifndef DEAD_H
#define DEAD_H

#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "colors.h"

/* -------------------------------------------------------------- */
/* ------------ HERE BEGINS THE DEAD_MENU'S MARCOS ------------- */
/* -------------------------------------------------------------- */

/* ---- BACKGROUND ---- */
#define NB_BACKGROUND 0
#define POS_BACKGROUND_1 {0, 0}
#define PATH_BACKGROUND_1 NULL
#define SIZE_MAX_PATH_BACKGROUND 0
#define POS_BACKGROUND {POS_BACKGROUND_1}
#define PATH_BACKGROUND {PATH_BACKGROUND_1}

/* ---- FOREGROUND ---- */
#define NB_FOREGROUND 1
#define POS_FOREGROUND_1 {480, 156}
#define COLOR_FOREGROUND_1 COLOR_DARK_BLUE
#define SIZE_FOREGROUND_1 {960, 750}
#define POS_FOREGROUND {POS_FOREGROUND_1}
#define COLOR_FOREGROUND {COLOR_FOREGROUND_1}
#define SIZE_FOREGROUND {SIZE_FOREGROUND_1}

/* ---- BUTTON ---- */
#define NB_BUTTON 2
#define POS_BUTTON_1 {540, 600}
#define POS_BUTTON_2 {980, 600}
#define COLOR_BUTTON_1 COLOR_DARK_GREEN
#define COLOR_BUTTON_2 COLOR_DARK_GREEN
#define SIZE_BUTTON_1 {400, 150}
#define SIZE_BUTTON_2 {400, 150}
#define POS_BUTTON {POS_BUTTON_1, POS_BUTTON_2}
#define COLOR_BUTTON {COLOR_BUTTON_1, COLOR_BUTTON_2}
#define SIZE_BUTTON {SIZE_BUTTON_1, SIZE_BUTTON_2}
#define OVER_COLOR_CHANGE 25

/* ---- TEXT ---- */
#define NB_TEXT 3
#define POS_TEXT_1 {700, 200}
#define POS_TEXT_2 {580, 630}
#define POS_TEXT_3 {1050, 630}
#define COLOR_TEXT_1 COLOR_LIGHT_GREY
#define COLOR_TEXT_2 COLOR_LIGHT_WHITE
#define COLOR_TEXT_3 COLOR_LIGHT_WHITE
#define SIZE_TEXT_1 {100, 75}
#define SIZE_TEXT_2 {60, 50}
#define SIZE_TEXT_3 {60, 50}
#define STR_TEXT_1 "... you died ..."
#define STR_TEXT_2 "Back to menu"
#define STR_TEXT_3 "Quit game"
#define SIZE_TEXT_MAX 20
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3}
#define FONT_TEXT FONT_REGULAR

/* ------------- HERE BEGINS THE DEAD FUNCTIONS ------------- */

int dead(game_t *game);
menu_t *initialisation_dead_menu(game_t *game);
void detail_init_dead_menu(menu_t *menu);
void move_dead_view(menu_t *menu, sfView *view);
int event_button_dead(game_t *game, menu_t *menu, sfEvent event);
int back_choice_dead(game_t *game, menu_t *menu, int i, sfEvent event);
int quit_choice_dead(game_t *game, menu_t *menu, int i, sfEvent event);
unsigned int get_event_dead(game_t *game, menu_t *menu);

#endif /* end of include guard: DEAD_H */
