/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:55:40 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/24 15:04:24 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *data, t_point p, int color)
{
	int	pixel_index;

	if (p.x >= 0 && p.x < data->width && p.y >= 0 && p.y < data->height)
	{
		pixel_index = (p.y * data->l_length) + (p.x * (data->bpp / 8));
		*(unsigned int *)(data->addr + pixel_index) = color;
	}
}

void	draw_rect(t_img *data, t_point p0, t_point p1, int color)
{
	t_point	p2;
	t_point	p3;

	p2 = (t_point){p1.x, p0.y};
	p3 = (t_point){p0.x, p1.y};
	draw_line(data, (t_line){p0, p2, 0}, (t_grad){color, color});
	draw_line(data, (t_line){p2, p1, 0}, (t_grad){color, color});
	draw_line(data, (t_line){p1, p3, 0}, (t_grad){color, color});
	draw_line(data, (t_line){p3, p0, 0}, (t_grad){color, color});
}

void	init_line(t_point p0, t_point p1, t_line *line)
{
	line->delta.x = abs(p1.x - p0.x);
	line->delta.y = abs(p1.y - p0.y);
	if (p0.x < p1.x)
		line->steps.x = 1;
	else
		line->steps.x = -1;
	if (p0.y < p1.y)
		line->steps.y = 1;
	else
		line->steps.y = -1;
	line->err = line->delta.x - line->delta.y;
}

void	init_line_vars(t_line_vars *vars, t_point p0, t_point p1)
{
	vars->dx = abs(p1.x - p0.x);
	vars->dy = abs(p1.y - p0.y);
	if (vars->dx > vars->dy)
		vars->steps = vars->dx;
	else
		vars->steps = vars->dy;
	vars->x_step = (p1.x - p0.x) / vars->steps;
	vars->y_step = (p1.y - p0.y) / vars->steps;
	vars->x = p0.x;
	vars->y = p0.y;
}

void	compute_color(t_grad grad, double t, t_color *color)
{
	color->r = (int)((1 - t) * ((grad.color1 >> 16) & 0xFF)
			+ t * ((grad.color2 >> 16) & 0xFF));
	color->g = (int)((1 - t) * ((grad.color1 >> 8) & 0xFF)
			+ t * ((grad.color2 >> 8) & 0xFF));
	color->b = (int)((1 - t) * (grad.color1 & 0xFF)
			+ t * (grad.color2 & 0xFF));
}
