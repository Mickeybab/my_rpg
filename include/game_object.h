/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** File of the rpg project
*/

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <stdbool.h>
#include <SFML/Graphics.h>

#include "menu.h"

#define NOT_ARMOR 0
#define HELMET 1
#define ARMS 2
#define CHESTPLATE 3
#define LEGGINGS 4

#define X_POS_HELMET 940
#define X_POS_ARMS 940
#define X_POS_CHESTPLATE 940
#define X_POS_LEGGINGS 940

#define Y_POS_HELMET 190
#define Y_POS_ARMS 280
#define Y_POS_CHESTPLATE 370
#define Y_POS_LEGGINGS 460

#define X_POS_STUFF {X_POS_HELMET, X_POS_ARMS, X_POS_CHESTPLATE,\
	X_POS_LEGGINGS\
}
#define Y_POS_STUFF {Y_POS_HELMET, Y_POS_ARMS, Y_POS_CHESTPLATE,\
	Y_POS_LEGGINGS\
}

#define NB_OBJ 26
#define SIZE_MAX_PATH_G_O 40
#define SIZE_MAX_DESC 40

#define ID_1 1
#define SPRITE_1 HEALTH_POTION
#define TYPE_1 NOT_ARMOR
#define DESCRIPTION_1 "Health potion\0"
#define LIFE_1 "10\0"
#define DEFENSE_1 "0\0"
#define MANA_1 "0\0"
#define ATTAQUE_1 "0\0"
#define SCALE_1 {0.18, 0.18}
#define RECT_1 {0, 0, 512, 512}

#define ID_2 2
#define SPRITE_2 MANA_POTION
#define TYPE_2 NOT_ARMOR
#define DESCRIPTION_2 "Mana potion\0"
#define LIFE_2 "\0"
#define DEFENSE_2 "\0"
#define MANA_2 "10\0"
#define ATTAQUE_2 "\0"
#define SCALE_2 {0.18, 0.18}
#define RECT_2 {0, 0, 512, 512}

#define ID_3 3
#define SPRITE_3 SPELL_SPRITE
#define TYPE_3 CHESTPLATE
#define DESCRIPTION_3 "Basic Spell Left Shift + click\0"
#define LIFE_3 "1\0"
#define DEFENSE_3 "5\0"
#define MANA_3 "1\0"
#define ATTAQUE_3 "1\0"
#define SCALE_3 {1, 1}
#define RECT_3 {0, 0, 100, 100}

#define ID_4 4
#define SPRITE_4 SPELL_SPRITE
#define TYPE_4 CHESTPLATE
#define DESCRIPTION_4 "Teleportation Spell Z + left click\0"
#define LIFE_4 "1\0"
#define DEFENSE_4 "5\0"
#define MANA_4 "1\0"
#define ATTAQUE_4 "1\0"
#define SCALE_4 {1, 1}
#define RECT_4 {0, 0, 100, 100}

#define ID_5 5
#define SPRITE_5 SPELL_SPRITE
#define TYPE_5 CHESTPLATE
#define DESCRIPTION_5 "Healing spell E\0"
#define LIFE_5 "1\0"
#define DEFENSE_5 "5\0"
#define MANA_5 "1\0"
#define ATTAQUE_5 "1\0"
#define SCALE_5 {1, 1}
#define RECT_5 {0, 0, 100, 100}

#define ID_6 6
#define SPRITE_6 CHESTPLATE_TEST
#define TYPE_6 CHESTPLATE
#define DESCRIPTION_6 "Spell 4\0"
#define LIFE_6 "1\0"
#define DEFENSE_6 "5\0"
#define MANA_6 "1\0"
#define ATTAQUE_6 "1\0"
#define SCALE_6 {1, 1}
#define RECT_6 {0, 0, 100, 100}

#define ID_7 7
#define SPRITE_7 CHEST_1
#define TYPE_7 CHESTPLATE
#define DESCRIPTION_7 "Basic chestplate\0"
#define LIFE_7 "0\0"
#define DEFENSE_7 "5\0"
#define MANA_7 "0\0"
#define ATTAQUE_7 "0\0"
#define SCALE_7 {0.18, 0.18}
#define RECT_7 {0, 0, 512, 512}

#define ID_8 8
#define SPRITE_8 HELMET_1
#define TYPE_8 HELMET
#define DESCRIPTION_8 "Basic helmet\0"
#define LIFE_8 "1\0"
#define DEFENSE_8 "2\0"
#define MANA_8 "0\0"
#define ATTAQUE_8 "0\0"
#define SCALE_8 {0.18, 0.18}
#define RECT_8 {0, 0, 512, 512}

#define ID_9 9
#define SPRITE_9 BRACER_1
#define TYPE_9 ARMS
#define DESCRIPTION_9 "Basic bracer\0"
#define LIFE_9 "0\0"
#define DEFENSE_9 "2\0"
#define MANA_9 "0\0"
#define ATTAQUE_9 "1\0"
#define SCALE_9 {0.18, 0.18}
#define RECT_9 {0, 0, 512, 512}

#define ID_10 10
#define SPRITE_10 BOOTS_1
#define TYPE_10 LEGGINGS
#define DESCRIPTION_10 "Basic boots\0"
#define LIFE_10 "0\0"
#define DEFENSE_10 "4\0"
#define MANA_10 "0\0"
#define ATTAQUE_10 "0\0"
#define SCALE_10 {0.18, 0.18}
#define RECT_10 {0, 0, 512, 512}

#define ID_11 11
#define SPRITE_11 CHEST_2
#define TYPE_11 CHESTPLATE
#define DESCRIPTION_11 "Golden chestplate\0"
#define LIFE_11 "0\0"
#define DEFENSE_11 "10\0"
#define MANA_11 "0\0"
#define ATTAQUE_11 "0\0"
#define SCALE_11 {0.18, 0.18}
#define RECT_11 {0, 0, 512, 512}

#define ID_12 12
#define SPRITE_12 HELMET_2
#define TYPE_12 HELMET
#define DESCRIPTION_12 "Golden helmet\0"
#define LIFE_12 "2\0"
#define DEFENSE_12 "4\0"
#define MANA_12 "0\0"
#define ATTAQUE_12 "0\0"
#define SCALE_12 {0.18, 0.18}
#define RECT_12 {0, 0, 512, 512}

#define ID_13 13
#define SPRITE_13 BRACER_2
#define TYPE_13 ARMS
#define DESCRIPTION_13 "Golden bracer\0"
#define LIFE_13 "0\0"
#define DEFENSE_13 "4\0"
#define MANA_13 "0\0"
#define ATTAQUE_13 "2\0"
#define SCALE_13 {0.18, 0.18}
#define RECT_13 {0, 0, 512, 512}

#define ID_14 14
#define SPRITE_14 BOOTS_2
#define TYPE_14 LEGGINGS
#define DESCRIPTION_14 "Golden boots\0"
#define LIFE_14 "0\0"
#define DEFENSE_14 "8\0"
#define MANA_14 "0\0"
#define ATTAQUE_14 "0\0"
#define SCALE_14 {0.18, 0.18}
#define RECT_14 {0, 0, 512, 512}

#define ID_15 15
#define SPRITE_15 CHEST_3
#define TYPE_15 CHESTPLATE
#define DESCRIPTION_15 "Magic chestplate\0"
#define LIFE_15 "2\0"
#define DEFENSE_15 "5\0"
#define MANA_15 "10\0"
#define ATTAQUE_15 "1\0"
#define SCALE_15 {0.18, 0.18}
#define RECT_15 {0, 0, 512, 512}

#define ID_16 16
#define SPRITE_16 HELMET_3
#define TYPE_16 HELMET
#define DESCRIPTION_16 "Magic helmet\0"
#define LIFE_16 "2\0"
#define DEFENSE_16 "4\0"
#define MANA_16 "10\0"
#define ATTAQUE_16 "0\0"
#define SCALE_16 {0.18, 0.18}
#define RECT_16 {0, 0, 512, 512}

#define ID_17 17
#define SPRITE_17 BRACER_3
#define TYPE_17 ARMS
#define DESCRIPTION_17 "Magic bracer\0"
#define LIFE_17 "0\0"
#define DEFENSE_17 "4\0"
#define MANA_17 "5\0"
#define ATTAQUE_17 "10\0"
#define SCALE_17 {0.18, 0.18}
#define RECT_17 {0, 0, 512, 512}

#define ID_18 18
#define SPRITE_18 BOOTS_3
#define TYPE_18 LEGGINGS
#define DESCRIPTION_18 "Magic boots\0"
#define LIFE_18 "0\0"
#define DEFENSE_18 "8\0"
#define MANA_18 "5\0"
#define ATTAQUE_18 "1\0"
#define SCALE_18 {0.18, 0.18}
#define RECT_18 {0, 0, 512, 512}

#define ID_19 19
#define SPRITE_19 CHEST_4
#define TYPE_19 CHESTPLATE
#define DESCRIPTION_19 "Epic chestplate\0"
#define LIFE_19 "10\0"
#define DEFENSE_19 "20\0"
#define MANA_19 "10\0"
#define ATTAQUE_19 "10\0"
#define SCALE_19 {0.18, 0.18}
#define RECT_19 {0, 0, 512, 512}

#define ID_20 20
#define SPRITE_20 HELMET_4
#define TYPE_20 HELMET
#define DESCRIPTION_20 "Epic helmet\0"
#define LIFE_20 "5\0"
#define DEFENSE_20 "10\0"
#define MANA_20 "10\0"
#define ATTAQUE_20 "10\0"
#define SCALE_20 {0.18, 0.18}
#define RECT_20 {0, 0, 512, 512}

#define ID_21 21
#define SPRITE_21 BRACER_4
#define TYPE_21 ARMS
#define DESCRIPTION_21 "Epic bracer\0"
#define LIFE_21 "10\0"
#define DEFENSE_21 "10\0"
#define MANA_21 "10\0"
#define ATTAQUE_21 "10\0"
#define SCALE_21 {0.18, 0.18}
#define RECT_21 {0, 0, 512, 512}

#define ID_22 22
#define SPRITE_22 BOOTS_4
#define TYPE_22 LEGGINGS
#define DESCRIPTION_22 "Epic boots\0"
#define LIFE_22 "8\0"
#define DEFENSE_22 "15\0"
#define MANA_22 "5\0"
#define ATTAQUE_22 "10\0"
#define SCALE_22 {0.18, 0.18}
#define RECT_22 {0, 0, 512, 512}

#define ID_23 23
#define SPRITE_23 HEALTH_POTION
#define TYPE_23 NOT_ARMOR
#define DESCRIPTION_23 "Health potion L2\0"
#define LIFE_23 "20\0"
#define DEFENSE_23 "0\0"
#define MANA_23 "0\0"
#define ATTAQUE_23 "0\0"
#define SCALE_23 {0.18, 0.18}
#define RECT_23 {0, 0, 512, 512}

#define ID_24 24
#define SPRITE_24 HEALTH_POTION
#define TYPE_24 NOT_ARMOR
#define DESCRIPTION_24 "Health potion L3\0"
#define LIFE_24 "50\0"
#define DEFENSE_24 "0\0"
#define MANA_24 "0\0"
#define ATTAQUE_24 "0\0"
#define SCALE_24 {0.18, 0.18}
#define RECT_24 {0, 0, 512, 512}

#define ID_25 25
#define SPRITE_25 MANA_POTION
#define TYPE_25 NOT_ARMOR
#define DESCRIPTION_25 "Mana potion L2\0"
#define LIFE_25 "\0"
#define DEFENSE_25 "\0"
#define MANA_25 "20\0"
#define ATTAQUE_25 "\0"
#define SCALE_25 {0.18, 0.18}
#define RECT_25 {0, 0, 512, 512}

#define ID_26 26
#define SPRITE_26 MANA_POTION
#define TYPE_26 NOT_ARMOR
#define DESCRIPTION_26 "Mana potion L2\0"
#define LIFE_26 "\0"
#define DEFENSE_26 "\0"
#define MANA_26 "50\0"
#define ATTAQUE_26 "\0"
#define SCALE_26 {0.18, 0.18}
#define RECT_26 {0, 0, 512, 512}

#define RARE_1 {ID_1, ID_2, ID_11, ID_12, ID_13, ID_14}
#define RARE_2 {ID_23, ID_25, ID_15, ID_16, ID_17, ID_18}
#define RARE_3 {ID_24, ID_26, ID_19, ID_20, ID_21, ID_22}

#define SPRITES_OBJ {SPRITE_1, SPRITE_2, SPRITE_3, SPRITE_4, SPRITE_5,\
	SPRITE_6, SPRITE_7, SPRITE_8, SPRITE_9, SPRITE_10, SPRITE_11,\
	SPRITE_12, SPRITE_13, SPRITE_14, SPRITE_15, SPRITE_16, SPRITE_17,\
	SPRITE_18, SPRITE_19, SPRITE_20, SPRITE_21, SPRITE_22, SPRITE_23,\
	SPRITE_24, SPRITE_25, SPRITE_26}
#define TYPES {TYPE_1, TYPE_2, TYPE_3, TYPE_4, TYPE_5, TYPE_6, TYPE_7,\
	TYPE_8, TYPE_9, TYPE_10, TYPE_11, TYPE_12, TYPE_13, TYPE_14, TYPE_15,\
	TYPE_16, TYPE_17, TYPE_18, TYPE_19, TYPE_20, TYPE_21, TYPE_22,\
	TYPE_23, TYPE_24, TYPE_25, TYPE_26}
#define DESCRIPTIONS {DESCRIPTION_1, DESCRIPTION_2, DESCRIPTION_3,\
	DESCRIPTION_4, DESCRIPTION_5, DESCRIPTION_6, DESCRIPTION_7,\
	DESCRIPTION_8, DESCRIPTION_9, DESCRIPTION_10, DESCRIPTION_11,\
	DESCRIPTION_12, DESCRIPTION_13, DESCRIPTION_14, DESCRIPTION_15,\
	DESCRIPTION_16, DESCRIPTION_17, DESCRIPTION_18, DESCRIPTION_19,\
	DESCRIPTION_20, DESCRIPTION_21, DESCRIPTION_22, DESCRIPTION_23,\
	DESCRIPTION_24, DESCRIPTION_25, DESCRIPTION_26}
#define LIFE {LIFE_1, LIFE_2, LIFE_3, LIFE_4, LIFE_5, LIFE_6, LIFE_7,\
	LIFE_8, LIFE_9, LIFE_10, LIFE_11, LIFE_12, LIFE_13, LIFE_14,\
	LIFE_15, LIFE_16, LIFE_17, LIFE_18, LIFE_19, LIFE_20, LIFE_21,\
	LIFE_22, LIFE_23, LIFE_24, LIFE_25, LIFE_26}
#define DEFENSE {DEFENSE_1, DEFENSE_2, DEFENSE_3, DEFENSE_4, DEFENSE_5,\
	DEFENSE_6, DEFENSE_7, DEFENSE_8, DEFENSE_9, DEFENSE_10, DEFENSE_11,\
	DEFENSE_12, DEFENSE_13, DEFENSE_14, DEFENSE_15, DEFENSE_16, DEFENSE_17,\
	DEFENSE_18, DEFENSE_19, DEFENSE_20, DEFENSE_21, DEFENSE_22, DEFENSE_23,\
	DEFENSE_24, DEFENSE_25, DEFENSE_26}
#define MANA {MANA_1, MANA_2, MANA_3, MANA_4, MANA_5, MANA_6, MANA_7,\
	MANA_8, MANA_9, MANA_10, MANA_11, MANA_12, MANA_13, MANA_14, MANA_15,\
	MANA_16, MANA_17, MANA_18, MANA_19, MANA_20, MANA_21, MANA_22, MANA_23,\
	MANA_24, MANA_25, MANA_26}
#define ATTAQUE {ATTAQUE_1, ATTAQUE_2, ATTAQUE_3, ATTAQUE_4, ATTAQUE_5,\
	ATTAQUE_6, ATTAQUE_7, ATTAQUE_8, ATTAQUE_9, ATTAQUE_10,\
	ATTAQUE_11, ATTAQUE_12, ATTAQUE_13, ATTAQUE_14, ATTAQUE_15,\
	ATTAQUE_16, ATTAQUE_17, ATTAQUE_18, ATTAQUE_19, ATTAQUE_20,\
	ATTAQUE_21, ATTAQUE_22, ATTAQUE_23, ATTAQUE_24, ATTAQUE_25,\
	ATTAQUE_26}
#define SCALES {SCALE_1, SCALE_2, SCALE_3, SCALE_4, SCALE_5, SCALE_6,\
	SCALE_7, SCALE_8, SCALE_9, SCALE_10, SCALE_11, SCALE_12, SCALE_13,\
	SCALE_14, SCALE_15, SCALE_16, SCALE_17, SCALE_18, SCALE_19, SCALE_20,\
	SCALE_21, SCALE_22, SCALE_23, SCALE_24, SCALE_25, SCALE_26}
#define RECTS {RECT_1, RECT_2, RECT_3, RECT_4, RECT_5, RECT_6, RECT_7,\
	RECT_8, RECT_9, RECT_10, RECT_11, RECT_12, RECT_13, RECT_14, RECT_15,\
	RECT_16, RECT_17, RECT_18, RECT_19, RECT_20, RECT_21, RECT_22, RECT_23,\
	RECT_24, RECT_25, RECT_26}

/* ------------------------- */
/* ---- NPC GAME OBJECT ---- */
/* ------------------------- */

#define NB_NPC 7

#define RECT_NPC_1 {0, 0, 100, 200}
#define RECT_NPC_2 {135, 0, 100, 200}
#define RECT_NPC_3 {0, 200, 100, 200}
#define RECT_NPC_4 {0, 400, 100, 200}
#define RECT_NPC_5 {270, 200, 100, 200}
#define RECT_NPC_6 {270, 200, 100, 200}
#define RECT_NPC_7 {270, 200, 100, 200}
#define RECT_NPC {RECT_NPC_1, RECT_NPC_2, RECT_NPC_3, RECT_NPC_4, RECT_NPC_5,\
	RECT_NPC_6, RECT_NPC_7\
}

#define POS_NPC_1 {134, 49}
#define POS_NPC_2 {4, 4}
#define POS_NPC_3 {55, 23}
#define POS_NPC_4 {182, 193}
#define POS_NPC_5 {182, 200}
#define POS_NPC_6 {60, 80}
#define POS_NPC_7 {30, 10}
#define POS_NPC {POS_NPC_1, POS_NPC_2, POS_NPC_3, POS_NPC_4, POS_NPC_5,\
	POS_NPC_6, POS_NPC_7\
}

#define STR_NPC_1 "    Complete the first maze!\nThe maze's entrance is on"\
		"the left.\n    Follow the rocky path!"
#define STR_NPC_2 "Follow the path and meet my aprentices!"
#define STR_NPC_3 "Use the left shift key and\n  the right click to attack"
#define STR_NPC_4 "Welcome to the village"
#define STR_NPC_5 ""
#define STR_NPC_6 "\tFind the first zap that will\nteleport you to your first"\
	" mission"
#define STR_NPC_7 "Use the 'z' key to teleport yourself\n"\
		"Use the 'i' key to open your inventory\n"\
		"Use the 's' key to open your skill tree\n"
#define STR_NPC {STR_NPC_1, STR_NPC_2, STR_NPC_3, STR_NPC_4, STR_NPC_5,\
	STR_NPC_6, STR_NPC_7\
}

#define POS_STR_NPC_1 {120, 75}
#define POS_STR_NPC_2 {175, 25}
#define POS_STR_NPC_3 {120, 50}
#define POS_STR_NPC_4 {110, 25}
#define POS_STR_NPC_5 {0, 0}
#define POS_STR_NPC_6 {130, 50}
#define POS_STR_NPC_7 {135, 75}
#define POS_STR_NPC {POS_STR_NPC_1, POS_STR_NPC_2, POS_STR_NPC_3,\
	POS_STR_NPC_4, POS_STR_NPC_5, POS_STR_NPC_6, POS_STR_NPC_7\
}

typedef struct game_object {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	sfIntRect rect;
	sfVector2f speed;
	sfVector2f scale;
	bool is_triggered;
	char *name;
	text_t **text;
	int id;
} game_obj_t;

typedef struct obj_drop {
	int nb_obj_drop;
	game_obj_t **objs_drop;
} obj_drop_t;

typedef struct npc_s {
	int nb_npc;
	game_obj_t **npc;
} npc_t;

/* ----------------------------- */
/* ---- END NPC GAME OBJECT ---- */
/* ----------------------------- */

game_obj_t *create_game_obj(const char *path, sfVector2f pos, sfIntRect rect,
	int id);
void init_drop(map_t *);
void destroy_game_obj(game_obj_t *object);
game_obj_t *check_drop(game_t *game, game_obj_t *obj, obj_drop_t *obj_drop);
npc_t *init_npc(game_t *);
int choose_drop(void);
game_obj_t *init_anim_projectile(projectile_t *new, bool);
int draw_call(game_t *, void *);
void draw_tile(game_t *, sfVector2f);
void draw_obj(game_t *, int, int);
void draw_npc(game_t *game, game_obj_t *npc);
void draw_all_obj(game_t *game, sfVector2f map_pos);
void draw_projectile(game_t *game);

#endif /* end of include guard: GAME_OBJECT_H */
