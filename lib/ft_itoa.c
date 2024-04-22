/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:48:29 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/19 11:24:52 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs(int n)
{
	long	result;

	result = n;
	if (result < 0)
		return (result * -1);
	return (result);
}

char	*ft_itoa(int n)
{
	int		len;
	long	n_abs;
	char	*result;

	if (!n)
		return (ft_strdup("0"));
	len = n < 0;
	n_abs = ft_abs(n);
	while (n_abs > 0)
		n_abs /= 10 + (0 * len++);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	n_abs = ft_abs(n);
	while (n_abs > 0)
	{
		result[len--] = (n_abs % 10) + '0';
		n_abs /= 10;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}
