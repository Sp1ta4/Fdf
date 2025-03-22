/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:55:40 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/22 19:01:39 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_img *data, t_point p, int color)
{
    if (p.x >= 0 && p.x < data->width && p.y >= 0 && p.y < data->height)
    {
        int pixel_index = (p.y * data->line_length) + (p.x * (data->bpp / 8));
        *(unsigned int *)(data->addr + pixel_index) = color;
    }
}

void draw_rect(t_img *data, t_point p0, t_point p1, int color)
{
    t_point p2 = {p1.x, p0.y};
    t_point p3 = {p0.x, p1.y};

    draw_line(data, p0, p2, (t_gradient){color, color});
    draw_line(data, p2, p1, (t_gradient){color, color});
    draw_line(data, p1, p3, (t_gradient){color, color});
    draw_line(data, p3, p0, (t_gradient){color, color});
}

void init_line(t_point p0, t_point p1, t_line *line)
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
void			draw_line(t_img *data, t_point p0, t_point p1, t_gradient grad)
{
    double dx = abs(p1.x - p0.x);
    double dy = abs(p1.y - p0.y);
    double steps = (dx > dy) ? dx : dy;
    double x_step = (p1.x - p0.x) / steps;
    double y_step = (p1.y - p0.y) / steps;
    double x = p0.x;
    double y = p0.y;

    int i = 0;
    while (i <= steps)
    {
        double t = i / steps;
        int r = ((1 - t) * ((grad.color1 >> 16) & 0xFF) + t * ((grad.color2 >> 16) & 0xFF));
        int g = ((1 - t) * ((grad.color1 >> 8) & 0xFF) + t * ((grad.color2 >> 8) & 0xFF));
        int b = ((1 - t) * (grad.color1 & 0xFF) + t * (grad.color2 & 0xFF));
        int color = (r << 16) | (g << 8) | b;

        my_mlx_pixel_put(data, (t_point){(int)x, (int)y}, color);
        x += x_step;
        y += y_step;
        i++;
    }
}

void draw_text(t_vars *mlx, char *text)
{
    mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 50, 0xFFFFFF, text);
}