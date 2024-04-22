/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:33:49 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/18 16:49:01 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (*src && i + 1 < size)
	{
		*dest++ = *src++;
		i++;
	}
	if (size > 0)
		*dest = '\0';
	while (*src)
	{
		src++;
		i++;
	}
	return (i);
}
