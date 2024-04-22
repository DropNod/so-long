/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:40:24 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/19 11:25:46 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*spc;
	int		i;

	spc = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!spc)
		return (NULL);
	i = 0;
	while (src[i])
	{
		spc[i] = src[i];
		i++;
	}
	spc[i] = '\0';
	return ((char *)spc);
}
