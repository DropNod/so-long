/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:20:32 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/19 11:25:56 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int num_elements, int size_of_element)
{
	unsigned char	*result;
	int				i;

	result = (unsigned char *) malloc(num_elements * size_of_element);
	if (!result)
		return (0);
	i = 0;
	while (i < num_elements * size_of_element)
	{
		result[i] = 0;
		i++;
	}
	return ((void *) result);
}
