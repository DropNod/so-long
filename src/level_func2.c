/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_func2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:34:03 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 12:34:33 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_enemies_c(t_level *level)
{
	int	i;
	int	j;
	int	enemies_c;

	i = 0;
	j = 0;
	enemies_c = 0;
	while (i < level->size.h)
	{
		j = 0;
		while (j < level->size.w)
		{
			if (level->tiles[i][j].value == 'S')
				enemies_c++;
			j++;
		}
		i++;
	}
	level->enemies_c = enemies_c;
}

void	get_enemies_v(t_level *level)
{
	int			i;
	int			j;
	int			k;
	t_tile		**enemies_v;

	enemies_v = malloc(level->enemies_c * sizeof(t_tile *));
	i = 0;
	k = 0;
	while (i < level->size.h)
	{
		j = 0;
		while (j < level->size.w)
		{
			if (level->tiles[i][j].value == 'S')
				enemies_v[k++] = &level->tiles[i][j];
			j++;
		}
		i++;
	}
	level->enemies_v = enemies_v;
}
