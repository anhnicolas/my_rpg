##
## EPITECH PROJECT, 2023
## B-MUL-200-LIL-2-1-myrpg-isaac.levy-piquet
## File description:
## Makefile
##

SRC =		./src/my_rpg.c							\
			./src/main_menu.c 						\
			./src/update_main_menu.c 				\
			./src/update_level1.c 					\
			./src/update_level2.c 					\
			./src/update_level3.c 					\
			./src/update_level4.c 					\
			./src/level1_loop.c						\
			./src/level2_loop.c						\
			./src/level3_loop.c						\
			./src/level4_loop.c 					\
			./src/initialise_level1.c				\
			./src/initialise_level1_objects.c		\
			./src/initialise_level2.c				\
			./src/initialise_level3.c				\
			./src/initialise_level4.c				\
			./src/initialise_window_and_game.c		\
			./src/initialise_main_menu.c			\
			./src/initialise_main_menu_objects.c	\
			./src/initialise_main_menu_buttons.c	\
			./src/initialise_background.c			\
			./src/initialise_player.c 				\
			./src/player_movement.c 				\
			./src/player_attack.c 					\
			./src/destroy_levels.c 					\
			./src/destroy_all.c						\
			./src/create_enemies.c					\
			./src/update_enemies_movement.c			\
			./src/collision.c						\
			./src/gravity.c							\
			./src/set_music.c						\
			./src/items.c							\
			./src/items2.c							\
			./src/in_game1.c						\
			./src/in_game2.c						\
			./src/in_game3.c						\
			./src/fade_function.c 					\
			./src/groupe_ennemies.c 				\
			./src/create_boss.c						\
			./src/settings.c						\
			./src/hit_enemy.c						\

OBJ = $(SRC:.c=.o)

CFLAGS += -Werror -Wextra -I./include

CSFML = -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -g

NAME = my_rpg

$(NAME): $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy $(CSFML)

all:     $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re:	fclean all

.PHONY: all clean fclean re
