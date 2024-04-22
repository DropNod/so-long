/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:50:45 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/18 17:13:31 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	u_c;
	int				i;
	char			*last;

	i = 0;
	last = NULL;
	u_c = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == u_c)
			last = (char *)&s[i];
		i++;
	}
	if (u_c == '\0')
		return ((char *)&s[i]);
	if (last)
		return (last);
	return (NULL);
}
