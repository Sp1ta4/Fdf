/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:34:29 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/20 16:43:30 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_rect(t_img *data, t_point pos, t_point size, int color)
{
	t_point	p0;
	t_point	p1;

	p0 = pos;
	p1 = (t_point){pos.x + size.x, pos.y};
	draw_line(data, p0, p1, color);
	p0 = (t_point){pos.x + size.x, pos.y};
	p1 = (t_point){pos.x + size.x, pos.y + size.y};
	draw_line(data, p0, p1, color);
	p0 = (t_point){pos.x + size.x, pos.y + size.y};
	p1 = (t_point){pos.x, pos.y + size.y};
	draw_line(data, p0, p1, color);
	p0 = (t_point){pos.x, pos.y + size.y};
	p1 = pos;
	draw_line(data, p0, p1, color);
}

void create_window(t_vars *mlx, int width, int height)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr) {
		write(2, "Error: mlx_init failed\n", 23);
		free_map(mlx->map, mlx->map_width);
		exit(1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, width, height, "FDF");
	if (!mlx->win_ptr) {
		write(2, "Error: mlx_new_window failed\n", 28);
		free_map(mlx->map, mlx->map_width);
		exit(1);
	}
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
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

int	mouse_button_press(__attribute__((unused)) int button, int x, int y, t_vars *vars)
{
	int i;

	// Ищем, на какую кнопку нажал пользователь
	i = 0;
	while (i < vars->buttons_cnt)
	{
		// Проверяем, попадает ли клик в область кнопки
		if (x >= vars->buttons[i].pos.x && x <= vars->buttons[i].pos.x + vars->buttons[i].size.x &&
			y >= vars->buttons[i].pos.y && y <= vars->buttons[i].pos.y + vars->buttons[i].size.y)
		{
			// Выводим контент кнопки в консоль
			printf("Button %d clicked: %s\n", i, vars->buttons[i].content);
			// Здесь можно добавить вызов функции для этой кнопки
			// Например, вызов функции, связанной с кнопкой, которая была нажата
			// button_action(i); // Пример вызова действия для кнопки
			break;
		}
		i++;
	}
	return (0);
}

void	setup_hooks(t_vars *mlx)
{
	// Подключаем функцию обработки нажатия мыши
	mlx_mouse_hook(mlx->win_ptr, mouse_button_press, mlx);
}


void	start_rendering(t_vars *mlx, int **map, int width, int height)
{
	init_map_mlx(mlx, map, width, height);
	create_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	create_sidebar(mlx, SIDEBAR_WIDTH, SIDEBAR_HEIGHT);
	// show_sidebar_content(mlx);
	setup_hooks(mlx);
	// Устанавливаем функцию, которая будет вызываться на каждом кадре
	// mlx_loop_hook(mlx->mlx_ptr, draw, &mlx);
	mlx_loop(mlx->mlx_ptr);
}