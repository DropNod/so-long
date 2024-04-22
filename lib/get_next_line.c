/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 21:51:49 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/26 22:27:19 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free_s1(char *s1, char const *s2)
{
	char	*result;
	int		i;
	int		s1_len;

	s1_len = ft_strlen(s1);
	result = malloc((s1_len + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		result[s1_len + i] = s2[i];
		i++;
	}
	result[s1_len + i] = '\0';
	free(s1);
	return (result);
}

static char	*ft_next(char **temp)
{
	char	*line;
	char	*ptr;

	ptr = *temp;
	while (*ptr && *ptr != '\n')
		ptr++;
	ptr += (*ptr == '\n');
	line = ft_substr(*temp, 0, (size_t)(ptr - *temp));
	if (!line)
	{
		free (*temp);
		return (NULL);
	}
	ptr = ft_substr(ptr, 0, ft_strlen(ptr));
	free (*temp);
	*temp = ptr;
	return (line);
}

static char	*ft_read(char *temp, int fd, char *buffer)
{
	ssize_t		r;

	r = 1;
	while (r && !ft_strchr(temp, '\n'))
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[r] = 0;
		temp = ft_strjoin_and_free_s1(temp, buffer);
		if (!temp)
		{
			free(buffer);
			return (NULL);
		}
	}
	free (buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp[1024];
	char		*buffer;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_strdup("");
	buffer = malloc((BUFFER_SIZE + 1) * sizeof (char *));
	if (!buffer)
	{
		free(temp[fd]);
		return (NULL);
	}
	temp[fd] = ft_read(temp[fd], fd, buffer);
	if (!temp[fd])
		return (NULL);
	if (!*temp[fd])
	{
		free(temp[fd]);
		temp[fd] = NULL;
		return (NULL);
	}
	return (ft_next(&temp[fd]));
}
