/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 03:02:19 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 12:34:59 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_game(game);
	exit(0);
}

int	key_press(int keycode, t_game *game)
{
	t_level	*level;
	t_tile	*player;

	level = &game->levels_v[game->current_level];
	player = level->player;
	if (keycode == 'w')
		move_player(game, player,
			&level->tiles[player->position.y - 1][player->position.x], 't');
	else if (keycode == 's')
		move_player(game, player,
			&level->tiles[player->position.y + 1][player->position.x], 'b');
	else if (keycode == 'a')
		move_player(game, player,
			&level->tiles[player->position.y][player->position.x - 1], 'l');
	else if (keycode == 'd')
		move_player(game, player,
			&level->tiles[player->position.y][player->position.x + 1], 'r');
	else if (keycode == 65307)
		end(game);
	return (0);
}

void	frames(t_game *game)
{
	static int	frame = 0;
	int			i;

	i = 0;
	if (frame % 3000 == 0)
	{
		while (i < game->levels_v[game->current_level].coins_c)
			game->levels_v[game->current_level].coins_v[i++]->changed = 1;
	}
	else if (frame % 5000 == 0)
		move_enemies(game);
	frame++;
	if (frame == 100000)
		frame = 0;
}

int	loop(t_game *game)
{
	int			i;
	char		*itoa;

	i = 0;
	frames(game);
	update_display(game);
	if (game->levels_v[game->current_level].finished)
		next_level(game);
	if (game->levels_v[game->current_level].moved)
	{
		game->levels_v[game->current_level].tiles[0][0].changed = 1;
		itoa = unsigned_itoa(game->levels_v[game->current_level].move_c);
		mlx_string_put(game->mlx, game->window, 13, 19, 16777215, itoa);
		free(itoa);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	int		i;

	if (ac < 2)
	{
		ft_printf("Error\n No maps passed as arguments");
		return (0);
	}
	i = 1;
	while (i < ac)
		check_map(av[i++]);
	game = init_game(ac, av);
	return (0);
}
