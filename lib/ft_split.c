/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:15:10 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/18 17:19:37 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*substring(int start, int end, char const *s)
{
	char	*result;
	int		i;

	i = start;
	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < end)
	{
		result[i - start] = s[i];
		i++;
	}
	result[i - start] = '\0';
	return (result);
}

int	get_segment_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	*get_next_segment(char const *s, char c, int *i)
{
	int	start;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	return (substring(start, *i, s));
}

char	**free_allocated_segments(char **tab, int j)
{
	while (j > 0)
		free(tab[--j]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	char	*segment;

	tab = malloc((get_segment_count(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		segment = get_next_segment(s, c, &i);
		if (!segment)
			return (free_allocated_segments(tab, j));
		tab[j++] = segment;
	}
	tab[j] = NULL;
	return (tab);
}
