/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:28:10 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/25 14:51:11 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	strs_len(const char *format)
{
	int	i;
	int	len;

	i = 0;
	len = 2;
	while (format[i])
	{
		if (format[i] == '%')
			len += 2;
		i++;
	}
	return (len);
}

int	print_and_free(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (1);
	write(1, str, ft_strlen(str));
	len += ft_strlen(str);
	free(str);
	return (len);
}

int	get_strs(const char *format, va_list args)
{
	int	i;
	int	start;
	int	len;
	int	total_len;

	i = 0;
	start = 0;
	len = 0;
	total_len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			total_len += print_and_free(ft_substr(format, start, len));
			total_len += print_and_free(get_str_by_type(format[i + 1], args));
			i ++;
			start = i + 1;
			len = 0;
		}
		else
			len++;
		i++;
	}
	total_len += print_and_free(ft_substr(format, start, len));
	return (total_len);
}
