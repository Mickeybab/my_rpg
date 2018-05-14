/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#ifndef OBJ_DECOR_H_
#define OBJ_DECOR_H_

#include <stdlib.h>
#include "map.h"
#include "game_info.h"

#define NB_TREE 3

#define PATH_TREE "./resources/decor/palmier.png"
#define WIDTH_TREE 122
#define HEIGHT_TREE 218

#define PATH_TREE2 "./resources/decor/palmier2.png"
#define WIDTH_TREE2 140
#define HEIGHT_TREE2 220

#define PATH_TREE_DOUBLE "./resources/decor/palmier_double.png"
#define WIDTH_TREE_DOUBLE 166
#define HEIGHT_TREE_DOUBLE 222

#define PATH_BIG_HOUSE "./resources/decor/big_house.png"
#define WIDTH_BIG_HOUSE 739
#define HEIGHT_BIG_HOUSE 1082

#define PATH_HOUSE_1 "./resources/decor/house1.png"
#define WIDTH_HOUSE_1 300
#define HEIGHT_HOUSE_1 300

#define PATH_HOUSE_2 "./resources/decor/house2.png"
#define WIDTH_HOUSE_2 300
#define HEIGHT_HOUSE_2 300

#define PATH_HOUSE_3 "./resources/decor/house3.png"
#define WIDTH_HOUSE_3 300
#define HEIGHT_HOUSE_3 300

#define PATH_HOUSE_4 "./resources/decor/house4.png"
#define WIDTH_HOUSE_4 300
#define HEIGHT_HOUSE_4 250

#define PATH_ROAD "./resources/decor/road.jpg"
#define WIDTH_ROAD 256
#define HEIGHT_ROAD 256

#define PATH_BUSH "./resources/decor/bush.png"
#define WIDTH_BUSH 135
#define HEIGHT_BUSH 91

#define PATH_ZAP "./resources/decor/zap.png"
#define WIDTH_ZAP 600
#define HEIGHT_ZAP 400

map_t *init_obj_decor(map_t *, int, sfVector2f);
game_obj_decor_t *init_struct_obj_decor(game_obj_decor_t *, int);
sfConvexShape *init_shape_obj_decor(sfVector2f, int, int);
map_t *make_forest(map_t *, sfVector2f, sfVector2f, float);
void free_decor(game_obj_decor_t **);
void draw_decor(game_obj_decor_t **, sfRenderWindow *w);
int decorlen(game_obj_decor_t **);
game_obj_decor_t *init_tree_1(game_obj_decor_t *, int);
game_obj_decor_t *init_tree_2(game_obj_decor_t *, int);
game_obj_decor_t *init_tree_double(game_obj_decor_t *, int);
game_obj_decor_t *init_big_house(game_obj_decor_t *, int);
game_obj_decor_t *init_house(game_obj_decor_t *, int);
game_obj_decor_t *init_bush(game_obj_decor_t *, int);
game_obj_decor_t *init_zap(game_obj_decor_t *, int);
char *path_house(int);
int width_house(int);
int height_house(int);
void init_decor(game_t *);
void make_vilage(game_t *);
void make_forest2(game_t *);
void block_house(map_t *, sfVector2f, int);

#endif /* OBJ_DECOR_H_ */
