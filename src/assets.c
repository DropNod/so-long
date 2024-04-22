/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:13:19 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 13:05:39 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_image(void *mlx, char *path)
{
	return (mlx_xpm_file_to_image(mlx, path, &(int){0}, &(int){0}));
}

t_assets	init_assets(void *mlx)
{
	t_assets	assets;

	assets.wall = load_image(mlx, "./assets/wall.xpm");
	assets.empty = load_image(mlx, "./assets/empty.xpm");
	assets.trapdoor_opened = load_image(mlx, "./assets/trapdoor_opened.xpm");
	assets.trapdoor_closed = load_image(mlx, "./assets/trapdoor_closed.xpm");
	assets.knight_top = load_image(mlx, "./assets/knight_top.xpm");
	assets.knight_bottom = load_image(mlx, "./assets/knight_bottom.xpm");
	assets.knight_left = load_image(mlx, "./assets/knight_left.xpm");
	assets.knight_right = load_image(mlx, "./assets/knight_right.xpm");
	assets.skeleton_top = load_image(mlx, "./assets/skeleton_top.xpm");
	assets.skeleton_bottom = load_image(mlx, "./assets/skeleton_bottom.xpm");
	assets.skeleton_left = load_image(mlx, "./assets/skeleton_left.xpm");
	assets.skeleton_right = load_image(mlx, "./assets/skeleton_right.xpm");
	assets.coins[0] = load_image(mlx, "./assets/coin_0.xpm");
	assets.coins[1] = load_image(mlx, "./assets/coin_1.xpm");
	assets.coins[2] = load_image(mlx, "./assets/coin_2.xpm");
	assets.coins[3] = load_image(mlx, "./assets/coin_3.xpm");
	assets.coins[4] = load_image(mlx, "./assets/coin_4.xpm");
	assets.coins[5] = load_image(mlx, "./assets/coin_5.xpm");
	assets.coins[6] = load_image(mlx, "./assets/coin_6.xpm");
	assets.coins[7] = load_image(mlx, "./assets/coin_7.xpm");
	return (assets);
}

void	free_assets(void *mlx, t_assets assets)
{
	mlx_destroy_image(mlx, assets.wall);
	mlx_destroy_image(mlx, assets.empty);
	mlx_destroy_image(mlx, assets.trapdoor_opened);
	mlx_destroy_image(mlx, assets.trapdoor_closed);
	mlx_destroy_image(mlx, assets.knight_top);
	mlx_destroy_image(mlx, assets.knight_bottom);
	mlx_destroy_image(mlx, assets.knight_left);
	mlx_destroy_image(mlx, assets.knight_right);
	mlx_destroy_image(mlx, assets.skeleton_top);
	mlx_destroy_image(mlx, assets.skeleton_bottom);
	mlx_destroy_image(mlx, assets.skeleton_left);
	mlx_destroy_image(mlx, assets.skeleton_right);
	mlx_destroy_image(mlx, assets.coins[0]);
	mlx_destroy_image(mlx, assets.coins[1]);
	mlx_destroy_image(mlx, assets.coins[2]);
	mlx_destroy_image(mlx, assets.coins[3]);
	mlx_destroy_image(mlx, assets.coins[4]);
	mlx_destroy_image(mlx, assets.coins[5]);
	mlx_destroy_image(mlx, assets.coins[6]);
	mlx_destroy_image(mlx, assets.coins[7]);
}
