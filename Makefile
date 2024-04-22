NAME = so_long
LIBFT = lib/libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra
LFLAGS = -Llib -lft -lmlx_Linux -lXext -lX11 -lm -lz
IFLAGS = -Iinclude

SRC_DIR = src
OBJ_DIR = obj

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/check_map.c $(SRC_DIR)/check_map_func.c $(SRC_DIR)/game.c $(SRC_DIR)/level.c $(SRC_DIR)/level_func1.c $(SRC_DIR)/level_func2.c $(SRC_DIR)/tile.c $(SRC_DIR)/tile_func.c $(SRC_DIR)/assets.c $(SRC_DIR)/move.c $(SRC_DIR)/size_position.c $(SRC_DIR)/utils.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(IFLAGS) $(SRC) $(LFLAGS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	make -C lib && make clean -C lib 

clean:
	/bin/rm -rf $(OBJ)
	make clean -C lib && make clean -C lib 

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C lib && make clean -C lib

re: fclean all
	make fclean -C lib && make clean -C lib

.PHONY: all clean fclean re


