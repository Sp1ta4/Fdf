/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:34:29 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/21 14:59:41 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void create_window(t_vars *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr) {
		write(2, "Error: mlx_init failed\n", 23);
		free_map(mlx->map, mlx->map_width);
		exit(1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_size.x, mlx->win_size.y, "FDF");
	if (!mlx->win_ptr) {
		write(2, "Error: mlx_new_window failed\n", 28);
		free_map(mlx->map, mlx->map_width);
		exit(1);
	}
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_size.x, mlx->win_size.y);
	if (!mlx->img.img_ptr)
	{
		write(2, "Error: mlx_new_image failed\n", 28);
		exit(1);
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr,
			&mlx->img.bpp, &mlx->img.line_length, &mlx->img.endian);
	mlx_key_hook(mlx->win_ptr, close_window, mlx); 
	mlx_hook(mlx->win_ptr, 17, 0, close_window_button, mlx);
}

void	setup_hooks(t_vars *mlx)
{
	// Подключаем функцию обработки нажатия мыши
	mlx_mouse_hook(mlx->win_ptr, mouse_button_press, mlx);
}

void	clear_image(t_img *img, int width, int height, int color)
{
	int x, y;

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

t_point project_iso(int x, int y, int z, t_vars *mlx)
{
	t_point p;
	double angle = 30 * M_PI / 180; // 30 градусов в радианах

	p.x = (x - y) * cos(angle) * mlx->zoom + mlx->offset.x;
	p.y = (x + y) * sin(angle) * mlx->zoom - z * mlx->z_scale + mlx->offset.y;
	return p;
}

void draw_map(t_vars *mlx)
{
	int x, y;
	t_point p1, p2;

	y = 0;
	if (!mlx->map)
	{
 	   write(2, "Error: map is not initialized\n", 31);
    	exit(1);
	}
	while (y < mlx->map_height)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			if (x < mlx->map_width - 1)
			{
			    // printf("Drawing line between (%d, %d) and (%d, %d)\n", x, y, x + 1, y);
			    p1 = project_iso(x, y, mlx->map[y][x], mlx);
			    p2 = project_iso(x + 1, y, mlx->map[y][x + 1], mlx);
				// printf("Projected: (%d, %d) => (%.2d, %.2d)\n", x, y, p1.x, p1.y);
				// printf("Projected: (%d, %d) => (%.2d, %.2d)\n", x, y, p2.x, p2.y);

			    draw_line(&mlx->img, p1, p2, WHITE);
			}
			if (y < mlx->map_height - 1)
			{
			    // printf("Drawing line between (%d, %d) and (%d, %d)\n", x, y, x, y + 1);
			    p1 = project_iso(x, y, mlx->map[y][x], mlx);
			    p2 = project_iso(x, y + 1, mlx->map[y + 1][x], mlx);
		
			    draw_line(&mlx->img, p1, p2, WHITE);
			}

			x++;
		}
		y++;
	}
}

int render(void *param)
{
	t_vars *mlx = (t_vars *)param;

	if (!mlx->needs_redraw)
		return (0);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	clear_image(&mlx->img, mlx->win_size.x, mlx->win_size.y, BACKGROUND_COLOR);
	create_sidebar(mlx, SIDEBAR_WIDTH, SIDEBAR_HEIGHT);
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
