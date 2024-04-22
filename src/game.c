/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:13:19 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/13 16:23:06 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	init_game(int paths_c, char **paths_v)
{
	t_game	game;
	int		i;

	game.levels_v = malloc(paths_c * sizeof(t_level));
	i = 1;
	while (i < paths_c)
	{
		game.levels_v[i - 1] = init_level(paths_v[i]);
		i++;
	}
	game.levels_c = paths_c - 1;
	game.current_level = 0;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.levels_v[0].size.w * IMG_SIZE,
			game.levels_v[0].size.h * IMG_SIZE, "Richemont - Level 1");
	game.assets = init_assets(game.mlx);
	game.total_move_c = 0;
	mlx_hook(game.window, 17, 0, end, &game);
	mlx_key_hook(game.window, key_press, &game);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_loop_hook(game.mlx, loop, &game);
	mlx_loop(game.mlx);
	return (game);
}

void	next_level(t_game *game)
{
	char	*title;
	char	*itoa;
	t_level	*level;

	game->total_move_c += game->levels_v[game->current_level].move_c;
	if (game->current_level >= game->levels_c - 1)
	{
		ft_printf("\033[32mVICTORY - You conquered the dungeon!\n\033[37m");
		ft_printf("You made %d moves\n", game->total_move_c);
		end(game);
	}
	else
	{
		level = &game->levels_v[++game->current_level];
		mlx_destroy_window(game->mlx, game->window);
		itoa = unsigned_itoa(game->current_level + 1);
		title = ft_strjoin("Richemont - Level ", itoa);
		game->window = mlx_new_window(game->mlx, level->size.w * IMG_SIZE,
				level->size.h * IMG_SIZE, title);
		free(itoa);
		free(title);
		mlx_hook(game->window, 17, 0, end, game);
		mlx_key_hook(game->window, key_press, game);
		mlx_do_key_autorepeatoff(game->mlx);
	}
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->levels_c)
	{
		free_level(&game->levels_v[i]);
		i++;
	}
	free(game->levels_v);
	free_assets(game->mlx, game->assets);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	update_display(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->levels_v[game->current_level].size.h)
	{
		j = 0;
		while (j < game->levels_v[game->current_level].size.w)
		{
			if (game->levels_v[game->current_level].tiles[i][j].changed)
				change_tile(game,
					&game->levels_v[game->current_level].tiles[i][j]);
			j++;
		}
		i++;
	}
}
