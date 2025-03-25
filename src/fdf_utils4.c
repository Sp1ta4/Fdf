/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:23:55 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/25 13:58:44 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_text(t_vars *mlx, char *text)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 50, 0xFFFFFF, text);
}

void	clear_image(t_img *img, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(img, (t_point){x, y}, color);
			x++;
		}
		y++;
	}
}

void	clg(t_point p, t_vars *mlx, t_line *line, t_grad *grad)
{
	line->delta = project_iso(p.x, p.y, mlx->map[p.y][p.x], mlx);
	line->steps = project_iso(p.x, p.y + 1, mlx->map[p.y + 1][p.x], mlx);
	line->err = 0;
	*grad = (t_grad){
		get_color(mlx->map[p.y][p.x]),
		get_color(mlx->map[p.y + 1][p.x])
	};
}

void	draw_line(t_img *data, t_line line, t_grad grad)
{
	t_line_vars	v;
	int			i;
	double		t;
	t_color		color;

	init_line_vars(&v, line.delta, line.steps);
	i = 0;
	while (i <= v.steps)
	{
		t = i / v.steps;
		compute_color(grad, t, &color);
		my_mlx_pixel_put(data, (t_point){(int)v.x, (int)v.y},
			(color.r << 16) | (color.g << 8) | color.b);
		v.x += v.x_step;
		v.y += v.y_step;
		i++;
	}
}

void	free_data_exit(int **map, int row, char **split, int code)
{
	if (map)
		free_map(map, row);
	if (split)
		free_split(split);
	if (code)
		err_invalid_map(code);
	if (!code)
		exit(1);
}
