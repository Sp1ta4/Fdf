/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:17:07 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/24 14:13:15 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	random_color(void)
{
	unsigned int	seed;

	seed = 2463534242;
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	return (seed & 0xFFFFFF);
}

int	get_color(int z)
{
	if (z > 0)
		return (RED);
	else if (z < 0)
		return (BLUE);
	return (GREEN);
}
