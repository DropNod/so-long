/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 05:23:31 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 16:13:31 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	raise_error(char *path, char *message)
{
	ft_printf("Error\nMap \"%s\" %s\n", path, message);
	exit(0);
}

char	**load_map(char *path)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		raise_error(path, "is empty.");
	}
	map = malloc((count_newline(path) + 1) * sizeof(char *));
	i = 0;
	while (line)
	{
		remove_newline(line);
		map[i++] = line;
		line = get_next_line(fd);
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

int	check_values(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'S')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(char *path)
{
	char	**map;
	int		i;

	map = load_map(path);
	if (!map)
		raise_error(path, "can't be loaded.");
	else if (!check_rectangle(map))
		raise_error(path, "isn't rectangular.");
	else if (!check_values(map))
		raise_error(path, "contains invalid value.");
	else if (!check_walls(map))
		raise_error(path, "isn't surrounded by walls.");
	else if (check_value_occ(map, 'P') != 1)
		raise_error(path, "doesn't have one player.");
	else if (check_value_occ(map, 'E') != 1)
		raise_error(path, "doesn't have one exit.");
	else if (check_value_occ(map, 'C') < 1)
		raise_error(path, "doesn't have any items.");
	else if (!check_paths(map))
		raise_error(path, "doesn't have solution.");
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
