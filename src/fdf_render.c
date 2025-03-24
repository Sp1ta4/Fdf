/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggevorgi <sp1tak.gg@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:34:29 by ggevorgi          #+#    #+#             */
/*   Updated: 2025/03/24 15:06:46 by ggevorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_iso(int x, int y, int z, t_vars *mlx)
{
	t_point	p;

	if (mlx->top_view)
	{
		p.x = x * mlx->zoom + mlx->offset.x / 1.5;
		p.y = y * mlx->zoom + mlx->offset.y;
	}
	else if (mlx->front_view)
	{
		p.x = x * mlx->zoom + mlx->offset.x / 1.5;
		p.y = -z * mlx->z_scale + mlx->offset.y * 1.5;
	}
	else if (mlx->side_view)
	{
		p.x = y * mlx->zoom + mlx->offset.x / 1.4;
		p.y = -z * mlx->z_scale + mlx->offset.y * 1.5;
	}
	else
	{
		p.x = (x - y) * cos(mlx->angle * M_PI / 180.0)
			* mlx->zoom + mlx->offset.x;
		p.y = (x + y) * sin(mlx->angle * M_PI / 180.0) * mlx->zoom
			- z * mlx->z_scale + mlx->offset.y / 1.5;
	}
	return (p);
}

void	draw_map(t_vars *mlx)
{
	if (mlx->default_view)
		mlx->angle = 30;
	else if (mlx->top_view)
		mlx->angle = 0;
	else if (mlx->front_view)
		mlx->angle = 90;
	else if (mlx->side_view)
		mlx->angle = -90;
	draw_view(mlx);
}

int	render(void *param)
{
	t_vars	*mlx;

	mlx = (t_vars *)param;
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
	mlx->needs_redraw = 1;
	mlx_mouse_hook(mlx->win_ptr, mouse_button_press, mlx);
	mlx_loop_hook(mlx->mlx_ptr, render, mlx);
	mlx_loop(mlx->mlx_ptr);
}
