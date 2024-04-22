/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_func1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:34:03 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 12:34:33 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_size(t_level *level, char *path)
{
	ssize_t	fd;
	int		i;
	int		w;
	int		h;
	char	*line;

	i = 0;
	w = 1;
	h = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line[i] && line[i + 1] != '\n')
	{
		w++;
		i++;
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		h++;
	}
	free(line);
	close(fd);
	level->size = init_size(w, h);
}

void	get_tiles(t_level *level, char *path)
{
	t_tile	**tiles;
	ssize_t	fd;
	char	*line;
	int		i;
	int		j;

	tiles = malloc((level->size.h) * sizeof(t_tile *));
	fd = open(path, O_RDONLY);
	i = -1;
	line = get_next_line(fd);
	while (++i < level->size.h)
	{
		tiles[i] = malloc((level->size.w) * sizeof(t_tile));
		j = 0;
		while (j < level->size.w)
		{
			tiles[i][j] = init_tile(j, i, line[j]);
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	level->tiles = tiles;
}

void	get_player_and_exit(t_level *level)
{
	int	i;
	int	j;

	i = 0;
	while (i < level->size.h)
	{
		j = 0;
		while (j < level->size.w)
		{
			if (is_player(level->tiles[i][j]))
				level->player = &level->tiles[i][j];
			else if (level->tiles[i][j].value == 'E')
				level->exit = &level->tiles[i][j];
			j++;
		}
		i++;
	}
}

void	get_coins_c(t_level *level)
{
	int	i;
	int	j;
	int	coins_c;

	i = 0;
	j = 0;
	coins_c = 0;
	while (i < level->size.h)
	{
		j = 0;
		while (j < level->size.w)
		{
			if (level->tiles[i][j].value == 'C')
				coins_c++;
			j++;
		}
		i++;
	}
	level->coins_c = coins_c;
}

void	get_coins_v(t_level *level)
{
	int			i;
	int			j;
	int			k;
	t_tile		**coins_v;

	coins_v = malloc(level->coins_c * sizeof(t_tile *));
	i = 0;
	k = 0;
	while (i < level->size.h)
	{
		j = 0;
		while (j < level->size.w)
		{
			if (level->tiles[i][j].value == 'C')
				coins_v[k++] = &level->tiles[i][j];
			j++;
		}
		i++;
	}
	level->coins_v = coins_v;
}
