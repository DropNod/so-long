/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:23:31 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 16:03:19 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangle(char **map)
{
	int		i;
	size_t	len;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int		i;
	t_size	size;

	i = 0;
	size = init_size(ft_strlen(map[0]), ft_strslen(map));
	while (map[0][i])
	{
		if (map[0][i++] != '1')
			return (0);
	}
	i = 0;
	while (map[size.h - 1][i])
	{
		if (map[size.h - 1][i++] != '1')
			return (0);
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][size.w - 1] != '1' )
			return (0);
		i++;
	}
	return (1);
}

int	check_value_occ(char **map, char c)
{
	int	i;
	int	j;
	int	occ;

	i = 0;
	occ = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				occ++;
			j++;
		}
		i++;
	}
	return (occ);
}

void	propagate(int x, int y, char **map)
{
	map[y][x] = '2';
	if (map[y - 1][x] != '1' && map[y - 1][x] != '2')
		propagate(x, y - 1, map);
	if (map[y + 1][x] != '1' && map[y + 1][x] != '2')
		propagate(x, y + 1, map);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '2')
		propagate(x - 1, y, map);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '2')
		propagate(x + 1, y, map);
}

int	check_paths(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				propagate(j, i, map);
			j++;
		}
		i++;
	}
	return (check_value_occ(map, 'E') == 0 && check_value_occ(map, 'C') == 0);
}
