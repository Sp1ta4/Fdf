/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:55:40 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/21 15:54:49 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void my_mlx_pixel_put(t_img *data, t_point p, int color)
{
    // Ограничиваем координаты по X и Y, чтобы не выйти за пределы изображения
    if (p.x >= 0 && p.x < data->width && p.y >= 0 && p.y < data->height)
    {
        int pixel_index = (p.y * data->line_length) + (p.x * (data->bpp / 8));
        *(unsigned int *)(data->addr + pixel_index) = color;
    }
}


void draw_rect(t_img *data, t_point p0, t_point p1, int color)
{
    t_point p2 = {p1.x, p0.y}; // верхний правый угол
    t_point p3 = {p0.x, p1.y}; // нижний левый угол

    draw_line(data, p0, p2, color); // верхняя сторона
    draw_line(data, p2, p1, color); // правая сторона
    draw_line(data, p1, p3, color); // нижняя сторона
    draw_line(data, p3, p0, color); // левая сторона
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

void draw_line(t_img *data, t_point p0, t_point p1, int color)
{
    t_line line;
    int err2;

    init_line(p0, p1, &line);

    while (1)
    {
        my_mlx_pixel_put(data, p0, color);
        if (p0.x == p1.x && p0.y == p1.y)
            break;

        err2 = 2 * line.err;
        if (err2 > -line.delta.y)
        {
            line.err -= line.delta.y;
            p0.x += line.steps.x;
        }
        if (err2 < line.delta.x)
        {
            line.err += line.delta.x;
            p0.y += line.steps.y;
        }
    }
}


void draw_text(t_vars *mlx, char *text)
{
    // Параметры: mlx_ptr, win_ptr, x, y, цвет текста, строка
    mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 50, 0xFFFFFF, text);
}