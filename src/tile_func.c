/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:20:02 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 12:34:18 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_player(t_tile tile)
{
	return (tile.value == 'P' || tile.value == 't' || tile.value == 'b'
		|| tile.value == 'l' || tile.value == 'r');
}

int	is_enemy(t_tile tile)
{
	return (tile.value == 'S' || tile.value == 'T' || tile.value == 'B'
		|| tile.value == 'L' || tile.value == 'R');
}
