/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** About menu functions and macros
*/

#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "resources.h"
#include "game_info.h"
#include "menu.h"
#include "colors.h"

/* -------------------------------------------------------------- */
/* ------------ HERE BEGINS THE PAUSE_MENU'S MARCOS ------------- */
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
#define POS_FOREGROUND_1 {285, 270}
#define COLOR_FOREGROUND_1 COLOR_DARK_BLUE
#define SIZE_FOREGROUND_1 {1300, 540}
#define POS_FOREGROUND {POS_FOREGROUND_1}
#define COLOR_FOREGROUND {COLOR_FOREGROUND_1}
#define SIZE_FOREGROUND {SIZE_FOREGROUND_1}

/* ---- BUTTON ---- */
#define NB_BUTTON 3
#define POS_BUTTON_1 {350, 625}
#define POS_BUTTON_2 {750, 625}
#define POS_BUTTON_3 {1150, 625}
#define COLOR_BUTTON_1 COLOR_DARK_GREEN
#define COLOR_BUTTON_2 COLOR_DARK_GREEN
#define COLOR_BUTTON_3 COLOR_DARK_GREEN
#define SIZE_BUTTON_1 {350, 100}
#define SIZE_BUTTON_2 {350, 100}
#define SIZE_BUTTON_3 {350, 100}
#define POS_BUTTON {POS_BUTTON_1, POS_BUTTON_2, POS_BUTTON_3}
#define COLOR_BUTTON {COLOR_BUTTON_1, COLOR_BUTTON_2, COLOR_BUTTON_3}
#define SIZE_BUTTON {SIZE_BUTTON_1, SIZE_BUTTON_2, SIZE_BUTTON_3}
#define OVER_COLOR_CHANGE 25

/* ---- TEXT ---- */
#define NB_TEXT 6
#define POS_TEXT_1 {690, 340}
#define POS_TEXT_2 {420, 650}
#define POS_TEXT_3 {790, 650}
#define POS_TEXT_4 {1210, 650}
#define COLOR_TEXT_1 COLOR_LIGHT_GREY
#define COLOR_TEXT_2 COLOR_LIGHT_WHITE
#define COLOR_TEXT_3 COLOR_LIGHT_WHITE
#define COLOR_TEXT_4 COLOR_LIGHT_WHITE
#define SIZE_TEXT_1 {100, 75}
#define SIZE_TEXT_2 {50, 50}
#define SIZE_TEXT_3 {50, 50}
#define SIZE_TEXT_4 {50, 40}
#define STR_TEXT_1 "Game Paused"
#define STR_TEXT_2 "Continue"
#define STR_TEXT_3 "Back to menu"
#define STR_TEXT_4 "Quit game"
#define SIZE_TEXT_MAX 30
#define POS_TEXT {POS_TEXT_1, POS_TEXT_2, POS_TEXT_3, POS_TEXT_4}
#define COLOR_TEXT {COLOR_TEXT_1, COLOR_TEXT_2, COLOR_TEXT_3, COLOR_TEXT_4}
#define SIZE_TEXT {SIZE_TEXT_1, SIZE_TEXT_2, SIZE_TEXT_3, SIZE_TEXT_4}
#define STR_TEXT {STR_TEXT_1, STR_TEXT_2, STR_TEXT_3, STR_TEXT_4}
#define FONT_TEXT FONT_REGULAR

/* ------------- HERE BEGINS THE PAUSE_MENU'S FUNCTIONS ------------- */

int pause_menu(game_t *game);
menu_t *initialisation_pause_menu(game_t *game);
unsigned int get_event_pause_menu(game_t *game, menu_t *menu);
void detail_init_pause_menu(menu_t *menu);
int event_button_pause_menu(game_t *game, menu_t *menu, sfEvent event);
int back_choice_pause_menu(game_t *game, menu_t *menu, int i, sfEvent event);
int quit_choice_pause_menu(game_t *game, menu_t *menu, int i, sfEvent event);
void update_pause_menu(menu_t *menu, sfView *view);
int continue_choice_pause_menu(game_t *game, menu_t *menu, int i,
	sfEvent event);

#endif /* end of include guard: PAUSE_MENU_H */
