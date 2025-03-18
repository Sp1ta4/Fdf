/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:55:40 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/18 11:13:59 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	my_mlx_pixel_put(t_img *data, t_point p, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (p.y * data->line_length + p.x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }

// void draw_line(t_img *data, t_point p0, t_point p1, int color)
// {
//     t_point delta;
//     t_point steps;
//     int		err;

//     delta.x = abs(p1.x - p0.x);
//     delta.y = -abs(p1.y - p0.y);
// 	if (p0.x < p1.x)
// 		steps.x = 1;
// 	else
// 		steps.x = -1;
// 	if (p0.y < p1.y)
// 		steps.y = 1;
// 	else
// 		steps.y = -1;
//     err = delta.x + delta.y;
//     while (1)
//     {
//         my_mlx_pixel_put(data, p0, color);
//         if (p0.x == p1.x && p0.y == p1.y)
// 			break;
//         if (2 * err >= delta.y)
// 			err += delta.y; p0.x += steps.x;
//         if (2 * err <= delta.x)
// 			err += delta.x; p0.y += steps.y;
//     }
// }