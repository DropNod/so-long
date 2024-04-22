/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:50:45 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/18 17:12:19 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	u_c;
	int				i;

	u_c = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == u_c)
			return ((char *)&s[i]);
		i++;
	}
	if (u_c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
