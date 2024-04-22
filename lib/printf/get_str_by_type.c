/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_by_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:28:10 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/25 14:56:41 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*c_func(va_list args)
{
	char	chr;

	chr = va_arg(args, int);
	if (!chr)
		write(1, "\0", 1);
	else
		return (ft_strdup((char []){chr, '\0'}));
	return (NULL);
}

char	*s_func(va_list args)
{
	char	*str;

	str = (char *) va_arg(args, int *);
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}

char	*get_str_by_type(char c, va_list args)
{
	if (c == 'c')
		return (c_func(args));
	else if (c == 's')
		return (s_func(args));
	else if (c == 'p')
		return (get_adress(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_itoa(va_arg(args, int)));
	else if (c == 'i')
		return (ft_itoa((int) va_arg(args, int)));
	else if (c == 'u')
		return (unsigned_itoa(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (hexa_itoa((unsigned int) va_arg(args, int)));
	else if (c == 'X')
		return (str_upper(hexa_itoa((unsigned int) va_arg(args, int))));
	else if (c == '%')
		return (ft_strdup("%"));
	return (NULL);
}
