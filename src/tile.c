/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:20:02 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 15:57:19 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coin_animation(t_game *game, t_tile *tile)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->assets.coins[tile->sprite], tile->position.x * IMG_SIZE,
		tile->position.y * IMG_SIZE);
	tile->sprite++;
	if (tile->sprite == 7)
		tile->sprite = 0;
}

void	change_player_tile(t_game *game, t_tile *tile)
{
	if (tile->value == 't')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.knight_top, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == 'b')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.knight_bottom, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == 'l')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.knight_left, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == 'r' || tile->value == 'P')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.knight_right, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
}

void	change_enemy_tile(t_game *game, t_tile *tile)
{
	if (tile->value == 'T')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.skeleton_top, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == 'B')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.skeleton_bottom, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == 'L')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.skeleton_left, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == 'R' || tile->value == 'S')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.skeleton_right, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
}

void	change_tile(t_game *game, t_tile *tile)
{
	if (tile->value == '1')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.wall, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == '0')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.empty, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == 'E')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.trapdoor_closed, tile->position.x * IMG_SIZE,
			tile->position.y * IMG_SIZE);
	else if (tile->value == 'e')
		mlx_put_image_to_window(game->mlx, game->window,
			game->assets.trapdoor_opened,
			tile->position.x * IMG_SIZE, tile->position.y * IMG_SIZE);
	else if (tile->value == 't' || tile->value == 'b'
		|| tile->value == 'l' || tile->value == 'r' || tile->value == 'P')
		change_player_tile(game, tile);
	else if (tile->value == 'T' || tile->value == 'B'
		|| tile->value == 'R' || tile->value == 'L' || tile->value == 'S')
		change_enemy_tile(game, tile);
	else if (tile->value == 'C')
		coin_animation(game, tile);
	tile->changed = 0;
}

t_tile	init_tile(int x, int y, int value)
{
	t_tile		tile;
	t_position	position;

	position.x = x;
	position.y = y;
	tile.value = value;
	tile.position = position;
	tile.sprite = 0;
	tile.changed = 1;
	return (tile);
}
