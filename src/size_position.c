/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gprigent <gprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:08:51 by gprigent          #+#    #+#             */
/*   Updated: 2023/11/10 12:34:03 by gprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_size	init_size(int w, int h)
{
	t_size	size;

	size.w = w;
	size.h = h;
	return (size);
}

t_position	init_position(int x, int y)
{
	t_position	position;

	position.x = x;
	position.y = y;
	return (position);
}
