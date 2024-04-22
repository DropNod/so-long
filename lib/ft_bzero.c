/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:57:21 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/18 15:52:29 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_bzero(char *ptr, int num)
{
	unsigned char	*result;
	int				i;

	result = (unsigned char *) ptr;
	i = 0;
	while (i < num)
	{
		result[i] = 0;
		i++;
	}
	return (ptr);
}
