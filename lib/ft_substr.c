/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:11:09 by gprigent          #+#    #+#             */
/*   Updated: 2023/10/18 17:00:02 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	str_len;
	size_t	actual_len;

	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if ((str_len - start) < len)
		actual_len = str_len - start;
	else
		actual_len = len;
	substring = malloc((actual_len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, &s[start], actual_len + 1);
	return (substring);
}
