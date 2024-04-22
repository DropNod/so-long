/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:19:48 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 12:36:54 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>

# define IMG_SIZE 32

typedef struct s_size
{
	int	w;
	int	h;
}	t_size;
t_size		init_size(int w, int h);

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;
t_position	init_position(int x, int y);

typedef struct s_tile
{
	t_position	position;
	char		value;
	void		*asset;
	int			sprite;
	int			changed;
}	t_tile;
t_tile		init_tile(int x, int y, int value);
int			is_player(t_tile tile);
int			is_enemy(t_tile tile);

typedef struct s_level
{
	t_size		size;
	t_tile		**tiles;
	t_tile		*player;
	t_tile		*exit;
	t_tile		**coins_v;
	int			coins_c;
	t_tile		**enemies_v;
	int			enemies_c;
	int			coins_found;
	int			move_c;
	int			moved;
	int			finished;
}	t_level;
t_level		init_level(char *path);
void		free_level(t_level *level);
void		get_size(t_level *level, char *path);
void		get_tiles(t_level *level, char *path);
void		get_player_and_exit(t_level *level);
void		get_coins_c(t_level *level);
void		get_coins_v(t_level *level);
void		get_enemies_c(t_level *level);
void		get_enemies_v(t_level *level);

typedef struct s_assets
{
	void	*wall;
	void	*empty;
	void	*trapdoor_opened;
	void	*trapdoor_closed;
	void	*knight_right;
	void	*knight_top;
	void	*knight_bottom;
	void	*knight_left;
	void	*skeleton_top;
	void	*skeleton_bottom;
	void	*skeleton_left;
	void	*skeleton_right;
	void	*coins[8];
}	t_assets;
t_assets	init_assets(void *mlx);
void		free_assets(void *mlx, t_assets assets);

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_assets	assets;
	t_level		*levels_v;
	int			levels_c;
	int			current_level;
	int			total_move_c;
}	t_game;
t_game		init_game(int paths_c, char **paths_v);
void		free_game(t_game *game);
void		update_display(t_game *game);
void		next_level(t_game *game);

void		change_tile(t_game *game, t_tile *tile);

//main
int			loop(t_game *game);
int			key_press(int keycode, t_game *game);
int			end(t_game *game);

//check_map
void		check_map(char *path);
int			check_rectangle(char **map);
int			check_walls(char **map);
int			check_value_occ(char **map, char c);
int			check_paths(char **map);

//move
void		move_player(t_game *game, t_tile *from,
				t_tile *dest, char new_value);
void		move_enemies(t_game *game);

//utils
int			count_newline(char *path);
int			random_int(int max);
void		remove_newline(char *str);
int			ft_strslen(char **strs);

#endif
