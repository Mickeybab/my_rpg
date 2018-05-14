/*
** EPITECH PROJECT, 2017
** filename
** File description
** Main include file, containing the game_t structure and the important func
*/

#ifndef GAME_INFO_H
#define GAME_INFO_H

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "window.h"
#include "map.h"
#include "music.h"
#include "player.h"
#include "projectile.h"
#include "enemy.h"
#include "collision.h"

#define SUCCESS 0
#define FAILURE 84
#define SECONDS 1000000

#define gauche 0
#define haut 63
#define diaghautgauche 130
#define diagdroite 63 * 3 + 7
#define diaggauche 63 * 4 + 9
#define bas 63 * 5 + 10
#define diagbas 63 * 6 + 13
#define droite 63 * 7 + 15

typedef enum prog_state_s {
	QUIT_PROG,
	FINE,
	GAME_ERROR = 84
} prog_state_t;

typedef struct game_s {
	bool verbose;
	bool in_game;
	void (*destroy)(struct game_s*);
	music_t *music;
	prog_state_t prog_state;
	window_t *window;
	map_t *map;
	player_t *player;
	projectile_t *projectile;
	enemy_t *enemy;
	int nb_enemy;
} game_t;

game_t *init_game(int argc, char **argv, char **env);
window_t *init_window(bool verbose);
music_t *init_music(void);
player_t *init_player(game_t *game);
bool is_env_correct(char **env);
void destroy_game(game_t *game);
void game_loop(game_t *game);
sfVector2i get_real_pos_mouse(game_t *);
void save_player(player_t *player);
int update(game_t *game, void *, sfClock *);
int collision(game_t *game);
void get_mouve(game_t *game);
void init_drop(map_t *);
void draw_drop(game_t *game);
void anim_player(game_t *game);
void anim_basic_spell(game_t *game);
sfIntRect move_rect(sfIntRect rect, int offset, int max_value);
sfIntRect move_rect_less(sfIntRect rect, int offset, int max_value);
void update_player(game_t *game, sfClock *);
void update_enemy(game_t *game);
void init_view(game_t *game);
void make_forest_first_road(game_t *);
void draw_character(game_t *game);
void update_music(music_t *music);
void init_draw(game_t *game);
void destroy_draw(game_t *game);
void draw_enemy(game_t *game);
int pause_menu(game_t *game);
void end_game_loop(game_t *game);
void update_zap(game_t *game);
void spawn_enemy(game_t *game, sfClock *cloc);

/* ENEMY FUNCTIONS */
void collision_projectile_enemy(game_t *all, projectile_t *);
void get_slayer_turn(game_t *game, enemy_t *enemy);
void ia_move(game_t *game, enemy_t *enemy, int size);
void get_dog_turn(game_t *game, enemy_t *enemy);
sfVector2f get_spawn_pos(game_t *game);
void update_anim_enemy(game_t *game);

/* SPELL function */
void teleport(game_t *game);

/* Dead menu call */
int dead(game_t *game);

/* Maze function */
void draw_maze(game_t *game, void * ptr);
void maze_game_loop(game_t *game);
void draw_maze_character(game_t *game);
void draw_maze_drop(game_t *game);
void init_maze_player(game_t *game);
map_t *create_maze(int x, int y);

#endif /* end of include guard: GAME_INFO_H */
