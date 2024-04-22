/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:59:21 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/24 17:05:37 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	put_and_count_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

char	*str_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char	*unsigned_itoa(unsigned int n)
{
	unsigned int	n_cpy;
	int				len;
	char			*result;

	if (!n)
		return (ft_strdup("0"));
	n_cpy = n;
	len = 0;
	while (n_cpy > 0)
	{
		n_cpy /= 10;
		len++;
	}
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	while (n > 0)
	{
		result[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
}

char	*hexa_itoa(unsigned long long n)
{
	int					len;
	unsigned long long	n_cpy;
	char				*result;
	char				base[17];

	ft_strlcpy(base, "0123456789abcdef", 17);
	len = 0;
	if (!n)
		return (ft_strdup("0"));
	n_cpy = n;
	while (n_cpy > 0)
		n_cpy /= 16 + (0 * len++);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	while (n > 0)
	{
		result[len--] = base[n % 16];
		n /= 16;
	}
	return (result);
}

char	*get_adress(void *ptr)
{
	char	*hexa;
	char	*adress;

	if (!ptr)
		return (ft_strdup("(nil)"));
	hexa = hexa_itoa((unsigned long long) ptr);
	adress = ft_strjoin("0x", hexa);
	free(hexa);
	return (adress);
}
