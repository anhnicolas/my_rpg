/*
** EPITECH PROJECT, 2023
** B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
** File description:
** my_rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <my_printf.h>
#include <my_utils.h>
#include <player.h>
#include <enemies.h>
#include <main_menu.h>
#include <lvl1.h>
#include <lvl2.h>
#include <lvl3.h>
#include <lvl4.h>
#include <map.h>
#include "settings.h"
#include "items.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>

#ifndef MY_RPG_H_
    #define MY_RPG_H_
    #define WINDOW g->w->window
    #define W_WIDTH g->w->size.x
    #define W_HEIGHT g->w->size.y
    #define EVENT g->event
    #define MOUSE_POS g->mouse_pos
    #define VIEW g->view
    #define VIEW_POS g->view_pos
    #define VIEW_SIZE g->view_size
    #define MAIN_MENU g->main_menu
    #define PLAYER g->player
    #define LEVEL_1 g->level_1
    #define LEVEL_2 g->level_2
    #define LEVEL_3 g->level_3
    #define LEVEL_4 g->level_4
    #define MUSIC_MENU "assets/music/menu.ogg"
    #define MUSIC_LVL1 "assets/music/level1.ogg"
    #define MUSIC_LVL2 "assets/music/level2.ogg"
    #define MUSIC_LVL3 "assets/music/level3.ogg"
    #define MUSIC_BOSS "assets/music/boss.ogg"

typedef struct window_s {
    sfRenderWindow *window;
    sfVideoMode mode;
    const char *title;
    sfUint32 style;
    sfVector2u size;
} window_t;

typedef struct game_s {
    window_t *w;
    main_menu_t *main_menu;
    level_1_t *level_1;
    level_2_t *level_2;
    level_3_t *level_3;
    level_4_t *level_4;
    player_t *player;
    sfEvent event;
    sfView *view;
    sfVector2f view_size;
    sfVector2f view_pos;
    sfVector2i mouse_pos;
    settings_t *settings;
    items_t *items;
    sfClock *clock;
    sfTime elapsedtime;
    float deltatime;
    sfRectangleShape *fadeRect;
    int fadeAlpha;
} game_t;

game_t *create_game_fullscreen(void);
settings_t *initsettings2(settings_t *settings);
void settings_loop(game_t *g);
void draw_items2(game_t *g);
char *int_to_str(int num);
int check_item_inv1(game_t *g, sfVector2f pos, int tmp);
int check_item_inv2(game_t *g, sfVector2f pos, int tmp);
void submenu2(game_t *g, char *str, sfVector2f tmp, sfFloatRect rect);
void check_item_coli2(game_t *g);
void use_heal(game_t *g);
void submenu1(game_t *g);
void draw_items1(game_t *g);
void check_item_coli1(game_t *g);
items_t *inititems(void);
settings_t *initsettings(void);
int evtsubmenu(game_t *g, int a, sfFloatRect rect, sfVector2i pos);
void event_phone(game_t *g);
game_t *create_game(void);
window_t *create_window(void);
main_menu_t *create_main_menu(game_t *g);
enemy_t *create_enemies(enemy_type_t type, sfVector2f pos, int offset_max);
level_1_t *create_level_1(game_t *g);
level_2_t *create_level_2(game_t *g);
level_3_t *create_level_3(game_t *g);
level_4_t *create_level_4(game_t *g);
boss_torso_t *create_boss_torso();
boss_head_t *create_boss_head();
boss_front_arm_t *create_boss_front_arm();
boss_back_arm_t *create_boss_back_arm();
background_t *create_background(char *path, game_t *g);
backelement_t *create_map(char *path, game_t *g);
player_t *create_player(game_t *g);
void game(void);
void main_menu(game_t *g);
void level1_loop(game_t *g);
void level2_loop(game_t *g);
void level3_loop(game_t *g);
void level4_loop(game_t *g);
void update_level_1_all(game_t *g);
void update_level_2_all(game_t *g);
void update_level_3_all(game_t *g);
void update_level_4_all(game_t *g);
void update_player(game_t *);
void update_jump(game_t *g, float groundHeight);
void move_projectile(game_t *g);
void update_main_menu_objects(main_menu_t *main_menu, game_t *g);
void update_main_menu_buttons(main_menu_t *main_menu, game_t *g);
void update_enemy(enemy_t *enemy, int row, float deltatime);
void update_enemy_movement_drone(enemy_t *enemy, float deltatime);
void update_enemy_movement_cop(enemy_t *enemy, float deltatime);
void update_level_1(game_t *g);
void update_level_1_objects(level_1_t *level_1, game_t *g);
void create_main_menu_objects(main_menu_t *main_menu);
void create_main_menu_buttons(main_menu_t *main_menu, game_t *g);
void create_level1_objects(level_1_t *level_1);
void set_main_menu3(main_menu_t *main_menu, game_t *g);
void set_main_menu4(main_menu_t *main_menu, game_t *g);
void set_main_menu5(main_menu_t *main_menu, game_t *g);
void player_movement(game_t *g);
void player_attack(game_t *g);
void dash_ability(game_t *g);
void set_view(game_t *g);
void get_elapsed_time(game_t *g);
void event_loop(game_t *g);
void draw_objects(game_t *g);
void destroy_level_1(game_t *g);
void destroy_level_2(game_t *g);
void destroy_level_3(game_t *g);
void destroy_level_4(game_t *g);
void destroy_all(game_t *g);
void set_music(sfMusic *music);
void update_collision(game_t *g, level_1_t *l1);
void falling(game_t *g);
void fall_lose(game_t *g);
void collision_lvl4(game_t *g, level_4_t *l4);
void fade_in(game_t *g);
void display_enemies(enemy_t *list, game_t *g);
void add_enemy_to_list(enemy_t *enemy, enemy_t **list);
void update_genemy(enemy_t *list, game_t *g);
void free_enemy_list(enemy_t *list);
void collide_enemy(game_t *g, enemy_t *list);
void shoot_enemy(game_t *g, enemy_t *list);
void interact_pnj(game_t *g);

#endif /* !MY_RPG_H_ */
