/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:43:50 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 12:34:59 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_move(t_level *level, t_tile *from, t_tile *dest, char new_value)
{
	level->player = dest;
	if (dest->value == 'C')
	{
		level->coins_found++;
		if (level->coins_found == level->coins_c)
		{
			level->exit->value = 'e';
			level->exit->changed = 1;
		}
	}
	level->move_c++;
	level->moved++;
	dest->value = new_value;
	dest->changed = 1;
	from->value = '0';
}

void	move_player(t_game *game, t_tile *from, t_tile *dest, char new_value)
{
	t_level	*level;

	level = &game->levels_v[game->current_level];
	from->changed = 1;
	if (dest->value == 'e')
	{
		if (level->coins_found == level->coins_c)
			level->finished = 1;
	}
	else if (is_enemy(*dest))
	{
		ft_printf("\033[31mDEFEAT - You died !\n\033[37m");
		end(game);
	}
	else if (dest->value != '1' && dest->value != 'E' && dest->value != 'S')
		make_move(level, from, dest, new_value);
	else
		from->value = new_value;
}

void	move_enemy(t_game *game, int enemy_index, t_tile *dest, char new_value)
{
	t_level	*level;

	level = &game->levels_v[game->current_level];
	level->enemies_v[enemy_index]->changed = 1;
	if (is_player(*dest))
	{
		ft_printf("\033[31mDEFEAT - You died !\n\033[37m");
		end(game);
	}
	else if (dest->value == '0')
	{
		dest->value = new_value;
		dest->changed = 1;
		level->enemies_v[enemy_index]->value = '0';
		level->enemies_v[enemy_index] = dest;
	}
	else
		level->enemies_v[enemy_index]-> value = new_value;
}

void	move_enemies(t_game *game)
{
	int		i;
	t_level	*level;
	int		random;

	i = 0;
	level = &game->levels_v[game->current_level];
	while (i < level->enemies_c)
	{
		random = random_int(8);
		if (random == 0)
			move_enemy(game, i, &level->tiles[level->enemies_v[i]
				->position.y - 1][level->enemies_v[i]->position.x], 'T');
		else if (random == 1)
			move_enemy(game, i, &level->tiles[level->enemies_v[i]
				->position.y + 1][level->enemies_v[i]->position.x], 'B');
		else if (random == 2)
			move_enemy(game, i, &level->tiles[level->enemies_v[i]->position.y]
			[level->enemies_v[i]->position.x - 1], 'L');
		else if (random == 3)
			move_enemy(game, i, &level->tiles[level->enemies_v[i]->position.y]
			[level->enemies_v[i]->position.x + 1], 'R');
		i++;
	}
}
