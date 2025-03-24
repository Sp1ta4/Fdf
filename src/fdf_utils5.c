/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:06:55 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/24 15:09:24 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_lines(t_vars *mlx)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width - 1)
		{
			p1 = project_iso(x, y, mlx->map[y][x], mlx);
			p2 = project_iso(x + 1, y, mlx->map[y][x + 1], mlx);
			draw_line(&mlx->img, (t_line){p1, p2, 0},
				(t_grad){get_color(mlx->map[y][x]),
				get_color(mlx->map[y][x + 1])});
			x++;
		}
		y++;
	}
}

void	draw_vertical_lines(t_vars *mlx)
{
	int		x;
	int		y;
	t_point	p1;
	t_point	p2;

	y = 0;
	while (y < mlx->map_height - 1)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			p1 = project_iso(x, y, mlx->map[y][x], mlx);
			p2 = project_iso(x, y + 1, mlx->map[y + 1][x], mlx);
			draw_line(&mlx->img, (t_line){p1, p2, 0},
				(t_grad){get_color(mlx->map[y][x]),
				get_color(mlx->map[y + 1][x])});
			x++;
		}
		y++;
	}
}

void	draw_view(t_vars *mlx)
{
	draw_horizontal_lines(mlx);
	draw_vertical_lines(mlx);
}
