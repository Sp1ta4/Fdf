/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:34:29 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/22 19:08:08 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point project_iso(int x, int y, int z, t_vars *mlx)
{
    t_point p;
    double angle = mlx->angle * M_PI / 180.0;

    if (mlx->top_view) // Вид сверху
    {
        p.x = x * mlx->zoom + mlx->offset.x / 1.5;
        p.y = y * mlx->zoom + mlx->offset.y;
    }
    else if (mlx->front_view) // Вид спереди
    {
        p.x = x * mlx->zoom + mlx->offset.x / 1.5;
        p.y = -z * mlx->z_scale + mlx->offset.y * 1.5;
    }
    else if (mlx->side_view) // Вид сбоку
    {
        p.x = y * mlx->zoom + mlx->offset.x / 1.4;
        p.y = -z * mlx->z_scale + mlx->offset.y * 1.5;
    }
    else // Изометрия по умолчанию
    {
        p.x = (x - y) * cos(angle) * mlx->zoom + mlx->offset.x;
        p.y = (x + y) * sin(angle) * mlx->zoom - z * mlx->z_scale + mlx->offset.y / 1.5;
    }
    return p;
}

void draw_view(t_vars *mlx)
{
    int x, y;
    t_point p1, p2;

    y = 0;
    while (y < mlx->map_height)
    {
        x = 0;
        while (x < mlx->map_width)
        {
            if (x < mlx->map_width - 1)
            {
                p1 = project_iso(x, y, mlx->map[y][x], mlx);
                p2 = project_iso(x + 1, y, mlx->map[y][x + 1], mlx);
                draw_line(&mlx->img, p1, p2, (t_gradient){get_color(mlx->map[y][x]), get_color(mlx->map[y][x + 1])});
            }
            if (y < mlx->map_height - 1)
            {
                p1 = project_iso(x, y, mlx->map[y][x], mlx);
                p2 = project_iso(x, y + 1, mlx->map[y + 1][x], mlx);
                draw_line(&mlx->img, p1, p2, (t_gradient){get_color(mlx->map[y][x]), get_color(mlx->map[y + 1][x])});
            }
            x++;
        }
        y++;
    }
}

void draw_map(t_vars *mlx)
{
    if (mlx->default_view)
        mlx->angle = 30;
    else if (mlx->top_view)
        mlx->angle = 0;
    else if (mlx->front_view)
        mlx->angle = 90;
    else if (mlx->side_view)
        mlx->angle = -90;
    draw_view(mlx); // Теперь все виды используют одну функцию
}

int render(void *param)
{
	t_vars *mlx = (t_vars *)param;

	if (!mlx->needs_redraw)
		return (0);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	clear_image(&mlx->img, mlx->win_size.x, mlx->win_size.y, BACKGROUND_COLOR);
	create_sidebar(mlx, SIDEBAR_WIDTH, SIDEBAR_HEIGHT + SIDEBAR_TOP);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	show_buttons_text(mlx);

	mlx->needs_redraw = 0;
	return (0);
}

void	start_rendering(t_vars *mlx, int **map, int width, int height)
{
	init_map_mlx(mlx, map, width, height);
	create_window(mlx);
	mlx->needs_redraw = 1; // первое отрисовывание
	mlx_mouse_hook(mlx->win_ptr, mouse_button_press, mlx);
	mlx_loop_hook(mlx->mlx_ptr, render, mlx);
	mlx_loop(mlx->mlx_ptr);
}
