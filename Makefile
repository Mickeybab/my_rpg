NAME	= my_rpg

TEST_NAME	= units

CC	= gcc

RM	= rm -f *.g* $(TEST_NAME) -R report rapport.info ./include/*.h.*

SRCS	= ./src/init_game/init_game.c \
	./src/init_game/init_window.c \
	./src/init_game/is_verbose.c \
	./src/init_game/init_music.c \
	./src/menu/create_background.c \
	./src/menu/create_button.c \
	./src/menu/create_text.c \
	./src/menu/display_menu.c \
	./src/menu/details_button_text.c \
	./src/menu/free_menu.c \
	./src/menu/main_menu/main_menu.c \
	./src/menu/main_menu/init_main_menu/init_main_menu.c \
	./src/menu/main_menu/init_main_menu/verbose_init_main_menu.c \
	./src/menu/main_menu/event_main_menu/get_event.c \
	./src/menu/event/fly_over_button.c \
	./src/menu/event/event_close.c \
	./src/menu/main_menu/event_main_menu/event_button.c \
	./src/menu/about_menu/about_menu.c \
	./src/menu/about_menu/event_about_menu/get_event.c \
	./src/menu/about_menu/init_about_menu/init_about_menu.c \
	./src/menu/about_menu/init_about_menu/verbose_init_about_menu.c \
	./src/menu/about_menu/event_about_menu/choice_button.c \
	./src/menu/about_menu/event_about_menu/event_button.c \
	./src/menu/play_menu/init_play_menu/add_detail_old_player.c \
	./src/menu/play_menu/play_menu.c \
	./src/menu/play_menu/event_play_menu/get_event.c \
	./src/menu/play_menu/init_play_menu/init_play_menu.c \
	./src/menu/play_menu/init_play_menu/verbose_init_play_menu.c \
	./src/menu/play_menu/event_play_menu/choice_button.c \
	./src/menu/play_menu/event_play_menu/event_button.c \
	./src/menu/main_menu/event_main_menu/button_choice.c \
	./src/menu/main_menu/event_main_menu/quit_menu.c \
	./src/menu/play_menu/init_play_menu/init_old_play_menu.c \
	./src/menu/how_menu/event_how_menu/choice_button.c \
	./src/menu/how_menu/event_how_menu/event_button.c \
	./src/menu/how_menu/event_how_menu/get_event.c \
	./src/menu/how_menu/init_how_menu/init_how_menu.c \
	./src/menu/how_menu/init_how_menu/verbose_init_how_menu.c \
	./src/menu/how_menu/how_menu.c \
	./src/menu/setting_menu/event_setting_menu/choice_button.c \
	./src/menu/setting_menu/event_setting_menu/event_button.c \
	./src/menu/setting_menu/event_setting_menu/get_event.c \
	./src/menu/setting_menu/init_setting_menu/init_setting_menu.c \
	./src/menu/setting_menu/init_setting_menu/verbose_init_setting_menu.c \
	./src/menu/setting_menu/setting_menu.c \
	./src/menu/animation/fading_appear.c \
	./src/menu/animation/fading_disappear.c \
	./src/menu/setting_menu/event_setting_menu/frame_event_button.c \
	./src/menu/setting_menu/event_setting_menu/sound_event_button.c \
	./src/menu/text_box.c \
	./src/menu/event/set_button_clicked.c \
	./src/game_loop/update/update.c	\
	./src/game_loop/update/update_zap.c 	\
	./src/game_loop/draw/draw_call.c	\
	./src/game_loop/draw/draw_map.c	\
	./src/game_loop/draw/init_draw.c 	\
	./src/game_loop/update/mouvement/a_star/algo.c	\
	./src/game_loop/update/mouvement/a_star/create.c	\
	./src/game_loop/projectile/create_projectile.c	\
	./src/game_loop/projectile/init_rotation.c	\
	./src/game_loop/update/mouvement/init_mouvement.c	\
	./src/game_loop/event/event.c \
	./src/game_loop/game_loop.c \
	./src/game_loop/update/mouvement/a_star/calcul.c	\
	./src/game_loop/update/mouvement/a_star/add_to_list.c	\
	./src/game_loop/update/mouvement/a_star/best_node.c	\
	./src/game_loop/update/mouvement/a_star/find_successor.c	\
	./src/game_loop/update/mouvement/a_star/find_way_back.c	\
	./src/game_loop/update/mouvement/a_star/destroy.c	\
	./src/game_loop/update/mouvement/mouvement_player.c	\
	./src/game_loop/update/mouvement/teleport.c	\
	./src/game_loop/animations/player_anim.c \
	./src/game_loop/update/update_drop.c \
	./src/game_loop/update/update_hud/move_view.c	\
	./src/game_loop/update/update_hud/update_hud.c \
	./src/game_loop/update/update_hud/hud_component.c \
	./src/game_loop/collision/detect_collision.c	\
	./src/game_loop/collision/setup_collision.c	\
	./src/game_loop/collision/setup_transformed_shape.c	\
	./src/game_loop/projectile/destroy.c	\
	./src/game_loop/collision/collision.c	\
	./src/game_loop/draw/draw_drop.c \
	./src/game_loop/animations/move_rect.c \
	./src/game_loop/update/update_player.c	\
	./src/game_loop/update/update_enemy.c	\
	./src/game_loop/animations/anim_spell_basic.c \
	./src/game_loop/dead/dead.c \
	./src/game_loop/dead/move_view.c \
	./src/game_loop/dead/init/init_dead.c \
	./src/game_loop/dead/event/choice_button.c \
	./src/game_loop/dead/event/event_button.c \
	./src/game_loop/dead/event/get_event.c \
	./src/game_loop/npc/init_npc.c \
	./src/game_loop/event/pause_menu/pause_menu.c \
	./src/game_loop/event/pause_menu/init_pause_menu/init_pause_menu.c \
	./src/game_loop/event/pause_menu/event_pause_menu/choice_button.c \
	./src/game_loop/event/pause_menu/event_pause_menu/event_button.c \
	./src/game_loop/event/pause_menu/event_pause_menu/get_event.c \
	./src/game_loop/event/pause_menu/update_view.c \
	./src/destroy_game.c \
	./src/end_game_loop.c \
	./src/in_game/mouse.c 	\
	./src/map/choose_triangle.c	\
	./src/map/create_convex_array.c	\
	./src/map/create_map.c	\
	./src/map/structure/init_struct.c	\
	./src/map/free_map.c			\
	./src/map/destroy_convex_map.c	\
	./src/map/map_size.c		\
	./src/map/structure/init_house.c 	\
	./src/map/vertex_array.c	\
	./src/map/compare_float.c		\
	./src/map/calcul/get_real_pos.c		\
	./src/map/calcul/get_tile.c		\
	./src/map/savegame/save_map.c	\
	./src/map/calcul/inside_triangle.c	\
	./src/map/load/create_empty_node.c	\
	./src/map/load/create_map_from_file.c	\
	./src/map/load/free_file_in_mem.c	\
	./src/map/load/load_file_in_mem.c	\
	./src/map/structure/init_obj.c 	\
	./src/map/structure/init_zap.c 	\
	./src/map/load/my_getfloat.c	\
	./src/map/structure/init_all_obj.c 	\
	./src/inventory/init_inventory/initialisation_inventory.c \
	./src/inventory/init_inventory/verbose_init_inventory.c \
	./src/inventory/inventory.c \
	./src/inventory/init_game_object.c \
	./src/inventory/fly_over_sprite.c \
	./src/inventory/event_inventory.c \
	./src/inventory/add_obj_in_inventory.c \
	./src/inventory/click_on_objects.c \
	./src/skill_tree/init_skill_tree/init_skill_menu.c \
	./src/skill_tree/init_skill_tree/verbose_init_skill_tree.c \
	./src/skill_tree/event_skill_tree.c \
	./src/skill_tree/skill_tree.c \
	./src/init_game/init_savegame.c \
	./src/init_game/init_player.c	\
	./src/init_game/init_hud.c \
	./src/init_game/init_decor.c 	\
	./src/init_game/init_drop.c \
	./src/init_game/init_enemy.c	\
	./src/init_game/is_env_correct.c \
	./src/character/enemy/create_slayer.c	\
	./src/character/ia_move.c	\
	./src/character/enemy/create_dog.c	\
	./src/character/enemy/ia_dog.c	\
	./src/character/enemy/spawn_enemy.c \
	./src/init_game/init_texture.c 	\
	./src/init_game/init_road.c 	\
	./src/character/enemy/destroy.c	\
	./src/character/enemy/ia_slayer.c	\
	./src/savegame/save_player.c	\
	./src/game_loop/animations/update_anim_enemy.c \
	./src/inventory/check_pos_inventory.c	\
	./src/skill_tree/draw_skill_tree.c 	\
	./src/init_game/init_plaza.c 	\
	./src/init_game/init_road_second.c 	\
	./src/game_loop/drop/choose_drop.c \
	./src/inventory/change_text.c 	\
	./src/maze/recursive_division/create_map.c	\
	./src/maze/recursive_division/create_wall.c	\
	./src/maze/recursive_division/divide_map.c	\
	./src/maze/recursive_division/recursive_generator.c	\
	./src/maze/recursive_division/struct_utility.c	\
	./src/maze/recursive_division/utility.c	\
	./src/maze/create_maze.c	\
	./src/maze/draw_maze.c	\
	./src/maze/maze_game_loop.c	\
	./src/maze/init_maze_player.c	\
	./src/maze/draw_maze_player.c	\
	./src/character/enemy_spawn.c	\
	./src/game_loop/drop/destroy_drop.c

LIB	= ./lib/my_putchar.c \
	./lib/my_putstr.c \
	./lib/my_strlen.c \
	./lib/my_itoa.c \
	./lib/my_nbrlen.c \
	./lib/my_revstr.c \
	./lib/my_strcmp.c \
	./lib/my_putnbr.c \
	./lib/my_getnbr.c \
	./lib/get_next_line.c \
	./lib/my_atoi.c \
	./lib/my_strcpy.c \

SRC_MAIN	= ./src/main.c \

SRCS_TEST	= ./tests/my_putstr_test.c \
		./tests/my_strcmp_test.c \
		./tests/my_strlen_test.c

OBJS	= $(LIB:.c=.o) \
	$(SRCS:.c=.o) \
	$(SRC_MAIN:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wextra

TEST_FLAGS = -I ./include/ -lcriterion --coverage -l c_graph_prog -lm

all: $(NAME)

## COMPILES THE LIB, SRCS, SRC_MAIN
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -l c_graph_prog -lm

## RUN THE TESTS ON THE SRCS AND LIB FILES
tests_run:
	$(CC) $(SRCS) $(LIB) $(SRCS_TEST) -o $(TEST_NAME) $(TEST_FLAGS)
	./$(TEST_NAME)

## SHOW IN HTML STYLE THE COVERAGE
show_coverage:
	$(CC) $(SRCS_TEST) $(SRCS) -o $(TEST_NAME) $(TEST_FLAGS)
	./units
	lcov --directory ./ -c -o rapport.info
	genhtml -o ./report -t "code coverage report" rapport.info
	xdg-open ./report/index.html &>/dev/null

wc:
	wc $(SRCS) $(SRC_MAIN) $(SRCS_TEST) ./include/*

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
